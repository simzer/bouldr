#ifndef SCENEVIEW_H
#define SCENEVIEW_H

#include <memory>
#include <functional>
#include <QWidget>

#include "../geom/vector.h"
#include "../geom/line.h"
#include "../model/scene.h"
#include "../model/camera.h"

class SceneView : public QWidget
{
	Q_OBJECT
public:
	std::function<void()> onChanged;

	explicit SceneView(Scene &scene,
					   const std::shared_ptr<Camera> &camera,
					   QWidget *parent = nullptr);
	void paintEvent(QPaintEvent*) override;
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);

private:
	std::shared_ptr<Camera> camera;
	Scene &scene;
	QPainter *painter;
	double forceSize;
	VectorProxy draggedObj;

	void drawBackground();
	void drawWall();
	void drawHuman();
	void drawTriangle();
	void drawDrag();
	void drawVector(const Vector &pos, const Vector &v);

	void drawLine(const Vector &v0, const Vector &v1);
	void drawDot(const Vector &v0, double size);

	QPoint toQPoint(const Vector &pos);
	Line fromQPoint(const QPoint &point);
	void setColor(const QColor &color);

signals:

public slots:
};

#endif // SCENEVIEW_H
