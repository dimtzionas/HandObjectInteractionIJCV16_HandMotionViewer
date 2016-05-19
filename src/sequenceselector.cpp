#include "sequenceselector.h"
#include "ui_sequenceselector.h"

SequenceSelector::SequenceSelector(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SequenceSelector)
{
    ui->setupUi(this);
}

SequenceSelector::~SequenceSelector()
{
    delete ui;
}

void SequenceSelector::on_loadSequenceButton_clicked()
{
    this->hide();
    QString sequence = "";
    if      (ui->sequenceRadio_01->isChecked())     sequence = QString("01");
    else if (ui->sequenceRadio_02->isChecked())     sequence = QString("02");
    else if (ui->sequenceRadio_03->isChecked())     sequence = QString("03");
    else if (ui->sequenceRadio_04->isChecked())     sequence = QString("04");
    else if (ui->sequenceRadio_05->isChecked())     sequence = QString("05");
    else if (ui->sequenceRadio_06->isChecked())     sequence = QString("06");
    else if (ui->sequenceRadio_07->isChecked())     sequence = QString("07");
    else if (ui->sequenceRadio_08->isChecked())     sequence = QString("08");
    else if (ui->sequenceRadio_09->isChecked())     sequence = QString("09");
    else if (ui->sequenceRadio_10->isChecked())     sequence = QString("10");
    else if (ui->sequenceRadio_11->isChecked())     sequence = QString("11");
    else if (ui->sequenceRadio_12->isChecked())     sequence = QString("12");
    else if (ui->sequenceRadio_13->isChecked())     sequence = QString("13");
    else if (ui->sequenceRadio_14->isChecked())     sequence = QString("14");
    else if (ui->sequenceRadio_15->isChecked())     sequence = QString("15");
    else if (ui->sequenceRadio_16->isChecked())     sequence = QString("16");
    else if (ui->sequenceRadio_17->isChecked())     sequence = QString("17");
    else if (ui->sequenceRadio_18->isChecked())     sequence = QString("18");
    else if (ui->sequenceRadio_19->isChecked())     sequence = QString("19");
    else if (ui->sequenceRadio_20->isChecked())     sequence = QString("20");
    else if (ui->sequenceRadio_21->isChecked())     sequence = QString("21");
    emit setSequence(sequence);
}

void SequenceSelector::closeEvent(QCloseEvent *){
    emit closeWindow( false );
}
