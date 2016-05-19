#ifndef SEQUENCESELECTOR_H
#define SEQUENCESELECTOR_H

#include <QWidget>

namespace Ui {
class SequenceSelector;
}

class SequenceSelector : public QWidget
{
    Q_OBJECT

public:
    explicit SequenceSelector(QWidget *parent = 0);
    ~SequenceSelector();

private:
    Ui::SequenceSelector *ui;
    void closeEvent(QCloseEvent *);

signals:
    void setSequence( QString );
    void closeWindow( bool );
private slots:
    void on_loadSequenceButton_clicked();
};

#endif // SEQUENCESELECTOR_H
