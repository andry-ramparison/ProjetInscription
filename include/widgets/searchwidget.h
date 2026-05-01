#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include <QLineEdit>
#include <QWidget>

class SearchWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SearchWidget(QWidget *parent = nullptr);

    QLineEdit *line() const;

private:
    QLineEdit *search;

};

#endif // SEARCHWIDGET_H
