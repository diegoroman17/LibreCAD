#ifndef QG_CADTOOLBARLASER_H
#define QG_CADTOOLBARLASER_H
class QG_CadToolBar;
#include "qg_actionhandler.h"
#include "ui_qg_cadtoolbarlaser.h"


class QG_CadToolBarLaser : public QWidget, public Ui::QG_CadToolBarLaser
{
    Q_OBJECT
public:
    QG_CadToolBarLaser(QWidget* parent = 0, Qt::WindowFlags fl = 0);
    ~QG_CadToolBarLaser();
    void restoreAction(); //restore action from checked button
    void finishCurrentAction(); //clear current action
    //void resetToolBar();

public slots:
    virtual void init();
    virtual void setCadToolBar( QG_CadToolBar * tb );

protected slots:
    virtual void languageChange();
private:
    QG_ActionHandler* actionHandler;
private slots:
    void on_QG_CadToolBarLaser_destroyed();
    //void slotDrawText();
    //void slotDrawImage();
};

#endif // QG_CADTOOLBARLASER_H
