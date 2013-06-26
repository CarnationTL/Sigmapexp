#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    inittbl ();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::inittbl() {
    tv = ui->tableView;
    tvm = new QStandardItemModel(4, 4);
    tv->setModel (tvm);
    QPushButton *btn;
    psigmap = new QSignalMapper();
    for(int i = 0; i < 4; i++) {
        tvm->setHeaderData (i, Qt::Horizontal, QString("col") + QString::number (i, 10));
        for(int j = 0; j < 4; j++) {
            QModelIndex pindx = tvm->index (i, j);
            if(j == 3) {
                tvm->setData (pindx, QString::number ((j * i), 10));
                btn = new QPushButton("open");
                tv->setIndexWidget (pindx, btn);
                connect (btn, SIGNAL(clicked()), psigmap, SLOT(map()));
                //psigmap->setMapping (btn, tvm->data(pindx).toInt());
                psigmap->setMapping (btn, tvm->data(pindx).toInt());
                psigmap->setMapping (btn, QString("sig deliver"));
            } else {
                tvm->setData (pindx, QString::number (j, 10));
            }

        }
    }
    connect (psigmap, SIGNAL(mapped(int)), this, SLOT(sigmapslot(int)));
    connect (psigmap ,SIGNAL(mapped(QString)), this, SLOT(sigmapslotString(QString)));
}

void MainWindow::on_tableView_clicked(const QModelIndex &index) {
    QStandardItem *p = tvm->itemFromIndex (index);
    qDebug () << p->text ();
}


void MainWindow::sigmapslot (int a) {
    pdialog = new Dialog();
    pdialog->setWindowTitle (QString::number (a, 10));
    pdialog->show ();
}


void MainWindow::sigmapslotString (QString a) {
    //QMessageBox::warning (this, a, a, QMessageBox::Yes);
    qDebug () << a ;
}
