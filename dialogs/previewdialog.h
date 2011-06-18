/*
 * Copyright (C) 2011  Christian Kaiser
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */
#ifndef PREVIEWDIALOG_H
#define PREVIEWDIALOG_H

#include <QDialog>

class Screenshot;
class QStackedLayout;
class QPushButton;
class PreviewDialog : public QDialog
{
    Q_OBJECT

public:
  PreviewDialog(QWidget *parent);

  void add(Screenshot* screenshot);
  int count();

  static PreviewDialog *instance();
  static bool isActive();

public slots:
  void setWidth(int w)  { resize(w, height()); }
  void setHeight(int h) { resize(width(), h);  }

signals:
  void acceptAll();
  void rejectAll();

private slots:
  void closePreview();
  void relocate();
  void previous();
  void next();
  void indexChanged(int i);
  void enlargePreview();

protected:
  void closeEvent(QCloseEvent* event);
  void mouseDoubleClickEvent(QMouseEvent *event);
  void timerEvent(QTimerEvent *event);

private:
  static PreviewDialog* mInstance;
  int mSize;
  int mPosition; //0: top left, 1: top right, 2: bottom left, 3: bottom rigth (default)
  int mAutoclose;
  int mAutocloseReset;
  int mAutocloseAction;
  QStackedLayout* mStack;
  QPushButton*    mNextButton;
  QPushButton*    mPrevButton;
};

#endif // PREVIEWDIALOG_H
