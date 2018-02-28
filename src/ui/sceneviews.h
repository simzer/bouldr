#ifndef SCENEVIEWS_H
#define SCENEVIEWS_H

#include <QWidget>

#include "../model/scene.h"

class SceneViews : public QWidget
{
	Q_OBJECT
public:
	explicit SceneViews(Scene &scene, QWidget *parent = nullptr);

signals:

public slots:
};

#endif // SCANEVIEWS_H
