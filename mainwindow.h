#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QDebug>
#include <QSignalMapper>
#include <QPushButton>
#include <QDialog>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void inittbl();
private slots:
    void on_tableView_clicked(const QModelIndex &index);

    void sigmapslot(int);
    void sigmapslotString(QString);

private:
    Ui::MainWindow *ui;
    QSignalMapper *psigmap;
    QTableView *tv;
    QStandardItemModel *tvm;
    QDialog *pdialog;
};

#endif // MAINWINDOW_H
