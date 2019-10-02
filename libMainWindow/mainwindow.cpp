﻿// *******************************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,01.10.2019</created>
/// <changed>ʆϒʅ,02.10.2019</changed>
// *******************************************************************************************


#include "mainwindow.h"
#include "./ui_mainwindow.h"


Application::Application ( int argc, char* argv [] )
  : app ( nullptr )
{
  app = new QApplication ( argc, argv );
};


QApplication* const Application::getApplication ( void )
{
  return app;
}


MainWindow::MainWindow ()
  : appStyle ( nullptr )
{
  try
  {

    QWidget* widget = new QWidget;
    setCentralWidget ( widget );

    QWidget* menuBar = new QWidget;
    menuBar->setSizePolicy ( QSizePolicy::Expanding, QSizePolicy::Expanding );

    QWidget* statusBar = new QWidget;
    statusBar->setSizePolicy ( QSizePolicy::Expanding, QSizePolicy::Expanding );

    QVBoxLayout* layout = new QVBoxLayout;
    layout->setContentsMargins ( 2, 2, 2, 2 );

    layout->addWidget ( menuBar );
    layout->addWidget ( statusBar );
    widget->setLayout ( layout );

    createActions ();
    createMenus ();

    //QString message { "Menus can be chosen! :)" };
    //QString message = tr ( "Menus can be chosen! :)" );
    //statusBar ()->showMessage ( message );

    setWindowTitle ( tr ( "Qt GUI" ) );
    setMinimumSize ( 240, 160 );
    resize ( 480, 320 );

    appStyle = new AppStyle;

    this->centralWidget ()->setStyleSheet ( appStyle->theme.form );
    this->menuBar ()->setStyleSheet ( appStyle->theme.menu );
    this->statusBar ()->setStyleSheet ( appStyle->theme.status );

  }
  catch (const std::exception & ex)
  {

  }
}


MainWindow::~MainWindow ()
{
  if (appStyle)
    delete appStyle;
}


void MainWindow::themeOne ( void )
{
  if (!actionTheme->isChecked ())
  {
    actionTheme->toggled ( false );
    setStyle ( 0 );
  } else
  {
    actionTheme->toggled ( true );
    setStyle ( 1 );
  }
};


void MainWindow::createActions ( void )
{
  actionTheme = new QAction ( tr ( "Theme" ), this );
  actionTheme->setShortcut ( QKeySequence::AddTab ); // Ctrl+T
  actionTheme->setCheckable ( true );
  actionTheme->setStatusTip ( tr ( "Set the application theme" ) );
  connect ( actionTheme, &QAction::triggered, this, &MainWindow::themeOne );
};


void MainWindow::createMenus ( void )
{
  menuFile = menuBar ()->addMenu ( tr ( "&File" ) );

  menuView = menuBar ()->addMenu ( tr ( "&View" ) );
  menuView->addAction ( actionTheme );
};


//#ifndef QT_NO_CONTEXTMENU
//void MainWindow::contextMenuEvent ( QContextMenuEvent* event )
//{
//  QMenu menu ( this );
//  menu.addAction ( actionTheme );
//  menu.exec ( event->globalPos () );
//};
//#endif // QT_NO_CONTEXTMENU


void MainWindow::setStyle ( unsigned char index )
{

  appStyle->set ( index );

  if (appStyle->getLoaded ())
  {
    this->centralWidget ()->setStyleSheet ( appStyle->theme.form );
    this->menuBar ()->setStyleSheet ( appStyle->theme.menu );
    this->statusBar ()->setStyleSheet ( appStyle->theme.status );
  }

};