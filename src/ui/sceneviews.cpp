#include "sceneviews.h"

#include <QGridLayout>

#include "sceneview.h"
#include "../geom/vector.h"
#include "../model/camera.h"

SceneViews::SceneViews(Scene &scene, QWidget *parent) : QWidget(parent)
{
	setContentsMargins(0,0,0,0);

	auto *grid = new QGridLayout(this);
	setLayout(grid);

	auto cam0 = std::make_shared<OrtogonalCamera>(0,2,Vector(),.3);
	auto cam1 = std::make_shared<OrtogonalCamera>(1,2,Vector(),.3);
	auto cam2 = std::make_shared<OrtogonalCamera>(0,1,Vector(),.3);
	auto cam3 = std::make_shared<OrtogonalCamera>(0,1,Vector(),.3);

	auto *view0 = new SceneView(scene, cam0, this);
	auto *view1 = new SceneView(scene, cam1, this);
	auto *view2 = new SceneView(scene, cam2, this);
	auto *view3 = new SceneView(scene, cam3, this);

	auto onChanged = [=]() {
		view0->update();
		view1->update();
		view2->update();
		view3->update();
	};

	view0->onChanged = onChanged;
	view1->onChanged = onChanged;
	view2->onChanged = onChanged;
	view3->onChanged = onChanged;

	grid->addWidget(view0, 0, 0);
	grid->addWidget(view1, 0, 1);
	grid->addWidget(view2, 1, 0);
	grid->addWidget(view3, 1, 1);

	grid->setMargin(0);
	grid->setSpacing(0);
	grid->setRowStretch(0, 1);
	grid->setRowStretch(1, 1);
	grid->setColumnStretch(0, 1);
	grid->setColumnStretch(1, 1);
}
