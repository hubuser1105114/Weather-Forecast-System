#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <qDebug>
#include <QMessageBox>
#include "weatherdata.h"

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

protected:
    void GetWeatherInfo(const QString& citycode);

    void parseJson(QByteArray& byteArray);

    void updateUI(void);

private slots:
    // 槽函数
    void NetworkReply(QNetworkReply* reply);
    void on_buttonSearch_clicked(void);

// 成员对象
private:
    Ui::MainWindow *ui;

    // http连接管理
    QNetworkAccessManager* mAccess;

    // 今天和其余几天的天气
    Today mtoday;
    OtherDay m_otherday[4];

    // 星期和日期
    QList<QLabel*> mWeeklist;
    QList<QLabel*> mDatelist;

    // 天气和图标
    QList<QLabel*> mTypelist;
    QList<QLabel*> mTypeiconlist;

    // 最高、最低温度
    QList<QLabel*> mhighlowlist;

    // 天气污染指数
    QList<QLabel*> mAqilist;

    QMap<QString, QString> mTypemap;

};
#endif // MAINWINDOW_H
