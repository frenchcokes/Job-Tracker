#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "Job.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_submitButton_clicked();

    void on_datePostedCheckBox_toggled(bool checked);

    void on_jobLoadPushButton_clicked();

    void on_addJobPushButton_clicked();

    void on_deleteJobPushButton_clicked();

    void on_editJobDetailsPushButton_clicked();

    void on_addEventViewPushButton_clicked();

    void on_addEventPushButton_clicked();

    void on_addEventBackPushButton_clicked();

private:
    Ui::MainWindow *ui;

    void displayJobs(QList<Job> jobList);
    void startup();

    void deleteJob(int index);

    bool viewJobAtIndex(int index);

    QList<Job> loadJobs();
    void saveJobs(QList<Job> jobList);
};
#endif // MAINWINDOW_H
