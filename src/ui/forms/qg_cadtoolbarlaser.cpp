#include "qg_cadtoolbarlaser.h"

#include "qg_cadtoolbar.h"
#include "qg_cadtoolbarlaser.h"

QG_CadToolBarLaser::QG_CadToolBarLaser(QWidget *parent, Qt::WindowFlags fl)
    : QWidget(parent, fl)
{
    setupUi(this);
    init();
}


QG_CadToolBarLaser::~QG_CadToolBarLaser()
{

}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void QG_CadToolBarLaser::languageChange()
{
    retranslateUi(this);
}

void QG_CadToolBarLaser::init() {
        actionHandler= NULL;
}

void QG_CadToolBarLaser::setCadToolBar(QG_CadToolBar* tb) {
    if (tb!=NULL) {
        actionHandler= tb->getActionHandler();
    } else {
        RS_DEBUG->print(RS_Debug::D_ERROR,
                        "QG_CadToolBarLaser::setCadToolBar(): No valid toolbar set.");
    }
}

void QG_CadToolBarLaser::restoreAction()
{

    finishCurrentAction();
}

//clear current action
void QG_CadToolBarLaser::finishCurrentAction()
{
    if(actionHandler==NULL) return;
    RS_ActionInterface* currentAction =actionHandler->getCurrentAction();
    if(currentAction != NULL) {
        currentAction->finish(false); //finish the action, but do not update toolBar
    }
}
void QG_CadToolBarLaser::on_QG_CadToolBarLaser_destroyed()
{

}
