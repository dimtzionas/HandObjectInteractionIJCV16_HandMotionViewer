#ifndef SEQUENCEDOWNLOADER_H
#define SEQUENCEDOWNLOADER_H

#include <QWidget>
#include <QDesktopServices>
#include <QUrl>

namespace Ui {
class SequenceDownloader;
}

class SequenceDownloader : public QWidget
{
    Q_OBJECT

public:
    explicit SequenceDownloader(QWidget *parent = 0);
    ~SequenceDownloader();

private:
    Ui::SequenceDownloader *ui;
    void closeEvent(QCloseEvent *);

signals:
    void closeWindow( bool );
private slots:
    void on_loadSequenceButton_clicked();
};

#endif // SEQUENCEDOWNLOADER_H
