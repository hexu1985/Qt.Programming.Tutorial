#ifndef CLIPBOARDWIDGET_H
#define CLIPBOARDWIDGET_H

#include <QLineEdit>

class ClipboardWidget : public QWidget
{
    Q_OBJECT
    
public:
    ClipboardWidget(QWidget *parent = 0);
    ~ClipboardWidget();

private slots:
    void setClipboard();   //设置剪贴板的内容
    void getClipboard();   //获取剪贴板的内容

private:
    QLineEdit *sourceEdit;
    QLineEdit *targetEdit;
};

#endif
