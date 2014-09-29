/***************************************************************************
                          kmag.h  -  description
                             -------------------
    begin                : Mon Feb 12 23:45:41 EST 2001
    copyright            : (C) 2001 by Sarang Lakare
    email                : sarang@users.sourceforge.net
    copyright            : (C) 2003-2004 by Olaf Schmidt
    email                : ojschmidt@kde.org
    copyright            : (C) 2008 by Matthew Woehlke
    email                : mw_triad@users.sourceforge.net
    copyright              (C) 2010 Sebastian Sauer
    email                  sebsauer@kdab.com
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef KMAG_H
#define KMAG_H

#include "kmagzoomview.h"
#include "focustrackconfig.h"

// include files for Qt
#include <QContextMenuEvent>
#include <QPrinter>

// include files for KDE
#include <kxmlguiwindow.h>
#include <ktoggleaction.h>
#include <kselectaction.h>
#include <ksharedconfig.h>

/**
  * The base class for Kmag application windows. It sets up the main
  * window and reads the config file as well as providing a menubar, toolbar
  * and statusbar. An instance of KmagView creates your center view, which is connected
  * to the window's Doc object.
  * KmagApp reimplements the methods that KXmlGuiWindow provides for main window handling and supports
  * full session management as well as using KActions.
  * @see KXmlGuiWindow
  * @see KApplication
  * @see KConfig
  *
  * @author Source Framework Automatically Generated by KDevelop, (c) The KDevelop Team.
  * @version KDevelop version 1.2 code generation
  */
class KmagApp : public KXmlGuiWindow
{
  Q_OBJECT

  public:
    /**
     * Construtor of KmagApp, calls all init functions to create the application.
     */
    explicit KmagApp(QWidget* parent=0, const char* name=0);

    /// Default destructor
    ~KmagApp();



  protected:
    /** save general Options like all bar positions and status as well as the geometry and the recent file list to the configuration
     * file
     */
    void saveOptions();
    /** read general Options again and initialize all variables like the recent file list
     */
    void readOptions();
    /** initializes the KActions of the application */
    void initActions();

    /** creates the centerwidget of the KTMainWindow instance and sets it as the view
     */
    void initView();

    /// Initialize all connections
    void initConnections();

    virtual bool queryClose();

    /// Catch context menu events
    void contextMenuEvent ( QContextMenuEvent * e );

  public slots:
    /** open a new application window by creating a new instance of KmagApp */
    void slotFileNewWindow();

    /** print the actual file */
    void slotFilePrint();

    void slotFileQuit();

    /** put the marked text/object into the clipboard
     */
    void copyToClipBoard();

    /// Toggle the refreshing of the window
    void slotToggleRefresh();

    void slotModeChanged();
    void slotModeWholeScreen();
    void slotModeSelWin();

    /// Zooms in
    void zoomIn();

    /// Zooms out
    void zoomOut();

    /// Save the zoomed image
    void saveZoomPixmap();

    /// Sets the zoom index to index
    void setZoomIndex(int index);

    /// Sets the rotation index to index
    void setRotationIndex(int index);

    /// Sets the fps index to index
    void setFPSIndex(int index);

    /// Sets the color index to index
    void setColorIndex(int index);

    /// Shows/hides the mouse cursor
    void showMouseCursor(bool show);

    void slotShowMenu();

    void slotToggleHideCursor();
    void slotStaysOnTop();

    /// Opens shortcut key configuration dialog
    void slotConfKeys();

    /// Called when toolbar config is updated
    void slotNewToolbarConfig();

    /// Called when "configure toolbar" is clicked
    void slotEditToolbars();

    void slotChangeZoomBoxIndex(int index);
    void slotChangeRotationBoxIndex(int index);
    void slotChangeFPSIndex(int index);
    void slotChangeColorIndex(int index);


  signals:
    /// This signal is raised whenever the index into the zoom array is changed
    void updateZoomIndex(int);

    /// This signal is raised whenever the zoom value changes
    void updateZoomValue(float);

    /// This signal is raised whenever the index into the rotation array is changed
    void updateRotationIndex(int);

    /// This signal is raised whenever the rotation value changes
    void updateRotationValue(int);

    /// This signal is raised whenever the index into the fps array is changed
    void updateFPSIndex(int);

    /// This signal is raised whenever the fps value changes
    void updateFPSValue(float);

    /// This signal is raised whenever the index into the color array is changed
    void updateColorIndex(int);

    /// This signal is raised whenever the color value changes
    void updateColorValue(int);

  private:
    /// the configuration object of the application
    KSharedConfigPtr config;

    // KAction pointers to enable/disable actions
    QAction *fileNewWindow, *m_pSnapshot, *m_pCopy, *m_keyConf, *m_toolConf;
    QAction *m_pPrint;
    QAction *m_pZoomIn;
    QAction *m_pZoomOut;
    QAction *m_pQuit;
    QAction *refreshSwitch;
    KToggleAction *m_pShowMenu;
    KSelectAction *m_pZoomBox, *m_pRotationBox, *m_pFPSBox, *m_pColorBox;

    /// Current index into the zoomArray
    unsigned int m_zoomIndex;

    /// Current index into the rotationArray
    unsigned int m_rotationIndex;

    /// Current index into the fpsArray
    unsigned int m_fpsIndex;

    /// Current index into the colorArray
    unsigned int m_colorIndex;

    QStringList zoomArrayString;
    QVector<float> zoomArray;

    QStringList rotationArrayString;
    QVector<int> rotationArray;

    QStringList fpsArrayString;
    QVector<float> fpsArray;

    QStringList colorArrayString;
    QVector<int> colorArray;

  KMagZoomView* m_zoomView;
  KToggleAction *m_hideCursor, *m_staysOnTop;
  KToggleAction *m_modeFollowMouse, *m_modeFollowFocus, *m_modeWholeScreen, *m_modeSelWin;

  /// Stores the non-zero cursor type to be used
  unsigned int m_mouseCursorType;

  unsigned int m_defaultMouseCursorType;

    #ifndef QT_NO_PRINTER
    // Keep QPrinter so settings persist
    QPrinter *m_printer;
    #endif // QT_NO_PRINTER

};


#endif // KMAG_H
