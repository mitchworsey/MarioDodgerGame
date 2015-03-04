#include "mainwindow.h"
#include <iostream>

/** Constructor. Allocates all necessary compentents of the MainWindow and adds them to the 
  * MainWindow
  */
MainWindow::MainWindow(){
    fl = new FormLayout();
    QDockWidget *qdw = new QDockWidget();
    qdw->setWidget(fl);
    addDockWidget(Qt::RightDockWidgetArea, qdw);
    qdw->setFeatures(QDockWidget::NoDockWidgetFeatures);
    qlv = new QListWidget();
    gw = new GraphicWindow(qlv, fl);
    tb = new ToolBar(gw, fl);
    addToolBar(tb);
 
    setCentralWidget(gw);
    
    QMenuBar *mb = menuBar();
    QMenu *fileMenu = new QMenu("File", this);
    QAction *exitAction = new QAction( "Exit", this);
    fileMenu->addAction( exitAction );
    mb->addMenu(fileMenu);
    setMenuBar(mb);
    
    /*QToolBar *errorbar = new QToolBar();
    this->addToolBar(Qt::BottomToolBarArea, errorbar);
    
    QLabel *errorlabel = new QLabel();
    errorbar->addWidget(errorlabel);
    errorlabel->setText("Cheat");
    QDockWidget *qdwl = new QDockWidget();
    qdwl->setWidget(qlv);
    addDockWidget(Qt::BottomDockWidgetArea, qdwl);
    qdwl->setFeatures(QDockWidget::NoDockWidgetFeatures);*/
    
    
    setFixedSize( WINDOW_MAX_X*2.8, WINDOW_MAX_Y*2.2 );
    
}

