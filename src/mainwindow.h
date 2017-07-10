#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

#include "src/Format/Dat/File.h"

using namespace Falltergeist::Format;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private slots:
  void on_actionExit_triggered();
  void on_actionOpen_triggered();
  void on_treeView_clicked(const QModelIndex &index);

private:
  Ui::MainWindow *ui;
  QStandardItemModel *fileTreeModel;

  Dat::File *file;

  void appendPath(QAbstractItemModel *const model, QStringList &fileParts,
                  const QModelIndex &parent = QModelIndex());
};

#endif // MAINWINDOW_H
