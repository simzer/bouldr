#include "sceneview.h"

#include <QPainter>
#include <QMouseEvent>

SceneView::SceneView(Scene &scene,
					 const std::shared_ptr<Camera> &camera,
					 QWidget *parent)
	: QWidget(parent),
	  scene(scene),
	  camera(camera),
	  painter(nullptr)
{
	forceSize = 1.7 / 700.0;
	setMinimumSize(320, 200);
	setContentsMargins(0,0,0,0);
}

void SceneView::paintEvent(QPaintEvent*)
{
	painter = new QPainter(this);
	drawBackground();
	drawWall();
	drawHuman();
	drawTriangle();
	drawDrag();
	delete painter;
}

void SceneView::mousePressEvent(QMouseEvent *event)
{
	for(auto point : scene.controlPoints()) {
		if ((toQPoint(point.get()) - event->pos()).manhattanLength() <= 7)
		{
			draggedObj = point;
			break;
		}
	}
	if (onChanged) onChanged();
}

void SceneView::mouseReleaseEvent(QMouseEvent *)
{
	draggedObj = VectorProxy();
	if (onChanged) onChanged();
}

void SceneView::mouseMoveEvent(QMouseEvent *event)
{
	if (draggedObj.valid()) {
		auto scanLine = fromQPoint(event->pos());
		draggedObj.set(scanLine.projectedPoint(draggedObj.get()));
	}
	if (onChanged) onChanged();
}

void SceneView::drawTriangle()
{
	auto triangle = scene.getTriangle();

	setColor(QColor(168,168,168));

	drawLine(triangle->point(0), triangle->point(1));
	drawLine(triangle->point(1), triangle->point(2));
	drawLine(triangle->point(2), triangle->point(0));

	setColor(QColor(92, 92, 92));
	drawDot(triangle->CoG(), 12);

	setColor(QColor(0, 0, 255));
	drawVector(triangle->CoG(), triangle->gForce());

	for (auto i = 0u; i < 3; i++)
	{
		setColor(QColor(92, 92, 92));
		drawDot(triangle->point(i), 5);

		setColor(QColor(0, 192, 0));
		drawVector(triangle->point(i),
				triangle->normalForceAt(i));

		setColor(QColor(0, 0, 255));
		drawVector(triangle->point(i),
				triangle->tangentForceAt(i));
	}
}

void SceneView::drawDrag()
{
	if (draggedObj.valid()) {
		setColor(QColor(192, 192, 255));
		drawDot(draggedObj.get(), 8);
	}
}

void SceneView::drawVector(const Vector &pos, const Vector &v)
{
	drawLine(pos, pos + v * forceSize);
}

void SceneView::drawLine(const Vector &v0, const Vector &v1)
{
	painter->drawLine(toQPoint(v0), toQPoint(v1));
}

void SceneView::drawDot(const Vector &v0, double size)
{
	painter->drawEllipse(toQPoint(v0), (int)size/2, (int)size/2);
}

QPoint SceneView::toQPoint(const Vector &pos)
{
	auto coords = camera->project(pos);
	return QPoint((coords.x + 0.5) * width(), (0.5 - coords.y) * height());
}

Line SceneView::fromQPoint(const QPoint &point)
{
	Coords coords = {
		(double)point.x() / width() - 0.5,
		-((double)point.y() / height() - 0.5)
	};
	return camera->scanline(coords);
}

void SceneView::setColor(const QColor &color)
{
	auto brush = painter->brush();
	brush.setColor(color);
	brush.setStyle(Qt::SolidPattern);
	painter->setBrush(brush);

	auto pen = painter->pen();
	pen.setColor(color);
	painter->setPen(pen);
}

void SceneView::drawHuman()
{
	setColor(QColor(0,0,0));
	for (auto &section : scene.getHuman().sections)
		drawLine(section.joints.first->position,
				 section.joints.second->position);
}

void SceneView::drawWall()
{

}

void SceneView::drawBackground()
{
	QRect geo(0, 0, width()-1, height()-1);
	setColor(QColor(192,192,192));
	painter->drawRect(geo);

	auto brush = painter->brush();
	brush.setStyle(Qt::NoBrush);
	painter->setBrush(brush);
	painter->fillRect(geo, QColor(255,255,255));
}
