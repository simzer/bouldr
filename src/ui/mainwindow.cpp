#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "sceneviews.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	setContentsMargins(0, 0, 0, 0);
	setCentralWidget(new SceneViews(scene, this));
}

MainWindow::~MainWindow()
{
	delete ui;
}
