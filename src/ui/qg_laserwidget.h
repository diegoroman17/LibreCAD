#ifndef QG_LASERWIDGET_H
#define QG_LASERWIDGET_H
#include <QWidget>
#include <QIcon>
#include <QAbstractTableModel>

#include "rs_layerlistlistener.h"
#include "rs_layerlist.h"

class QG_ActionHandler;
class QTableView;

/**
 * Implementation of a model to use in QG_LaserWidget
 */
class QG_LaserModel: public QAbstractTableModel {
public:
    enum {
        VISIBLE,
        LOCKED,
        NAME,
        LAST
    };
    QG_LaserModel(QObject * parent = 0);
    ~QG_LaserModel();
    Qt::ItemFlags flags ( const QModelIndex & /*index*/ ) {
            return Qt::ItemIsSelectable|Qt::ItemIsEnabled;}
    int columnCount(const QModelIndex &/*parent*/) const {return LAST;}
    int rowCount ( const QModelIndex & parent = QModelIndex() ) const;
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
    QModelIndex parent ( const QModelIndex & index ) const;
    QModelIndex index ( int row, int column, const QModelIndex & parent = QModelIndex() ) const;
    void setLaserList(RS_LayerList* ll);
    RS_Layer *getLayer( int row );
    QModelIndex getIndex (RS_Layer * lay);

private:
    QList<RS_Layer*> listLayer;
    QIcon layerVisible;
    QIcon layerHidden;
    QIcon layerDefreeze;
    QIcon layerFreeze;
};


/**
 * This is the Qt implementation of a widget which can view a
 * layer list and provides a user interface for basic layer actions.
 */
class QG_LaserWidget: public QWidget, public RS_LayerListListener {
    Q_OBJECT

public:
    QG_LaserWidget(QG_ActionHandler* ah, QWidget* parent,
                   const char* name=0, Qt::WFlags f = 0);
    ~QG_LaserWidget();

    void setLaserList(RS_LayerList* layerList, bool showByBlock);

    void update();
    void activateLaser(RS_Layer* layer);

    virtual void laserActivated(RS_Layer* layer) {
        activateLaser(layer);
    }
    virtual void laserAdded(RS_Layer* layer) {
        update();
        activateLaser(layer);
    }
    virtual void laserEdited(RS_Layer*) {
        update();
    }
   virtual void laserRemoved(RS_Layer*) {
        update();
        activateLaser(layerList->at(0));
    }
    virtual void laserToggled(RS_Layer*) {
        update();
    }

signals:
        void escape();

public slots:
    void slotActivated(QModelIndex layerIdx);

protected:
    void contextMenuEvent(QContextMenuEvent *e);
    virtual void keyPressEvent(QKeyEvent* e);

private:
    RS_LayerList* layerList;
    bool showByBlock;
    QTableView* layerView;
    QG_LaserModel *laserModel;
    RS_Layer* lastLayer;
    QG_ActionHandler* actionHandler;
};

#endif


