#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  fileTreeModel = new QStandardItemModel(this); // set parent or it'll leak
  fileTreeModel->setHorizontalHeaderLabels(QStringList("Files"));
}

MainWindow::~MainWindow() { delete ui; }

/**
 * @brief Creates a tree structure from a file path, e.g.
 * FolderA/FolderB/File.txt
 */
void MainWindow::appendPath(QAbstractItemModel *const model,
                            QStringList &fileParts, const QModelIndex &parent) {
  Q_ASSERT(model);

  if (fileParts.isEmpty())
    return;

  if (model->columnCount(parent) <= 0)
    model->insertColumn(0, parent);

  QModelIndex currIdx;
  const QString currLevel = fileParts.takeFirst();
  const int rowCount = model->rowCount(parent);

  // There is already a folder with the same name at this level
  for (int i = 0; i < rowCount; ++i) {
    if (model->index(i, 0, parent).data().toString().compare(currLevel) == 0) {
      currIdx = model->index(i, 0, parent);
      break;
    }
  }

  // There isn´t a folder with this name yet
  if (!currIdx.isValid()) {
    model->insertRow(rowCount, parent);
    currIdx = model->index(rowCount, 0, parent);
    model->setData(currIdx, currLevel);
  }

  appendPath(model, fileParts, currIdx);
}

void MainWindow::on_actionExit_triggered() { close(); }

void MainWindow::on_actionOpen_triggered() {
  QString filename = QFileDialog::getOpenFileName(
      this, tr("Open Fallout 2 dat file"), "", "*.dat");

  if (filename.isEmpty())
    return;

  Dat::File file(filename.toStdString()); // ("master.dat");

  /* FIXME: this freezes the application for a few seconds, but
     QStandardItemModel cannot be used in a separate thread as its unsafe */
  for (auto &entry : file.list()) {
    QStringList fileParts = QString::fromStdString(entry.first).split("/");
    appendPath(fileTreeModel, fileParts);
  }
  ui->treeView->setModel(fileTreeModel);
  // ui->treeView->resizeColumnToContents(0);
}

void MainWindow::on_treeView_clicked(const QModelIndex &index)
{

}
