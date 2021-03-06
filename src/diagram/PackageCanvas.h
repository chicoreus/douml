// *************************************************************************
//
// Copyright 2004-2010 Bruno PAGES  .
// Copyright 2012-2013 Nikolai Marchenko.
// Copyright 2012-2013 Leonardo Guilherme.
//
// This file is part of the DOUML Uml Toolkit.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License Version 3.0 as published by
// the Free Software Foundation and appearing in the file LICENSE.GPL included in the
//  packaging of this file.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License Version 3.0 for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
//
// e-mail : doumleditor@gmail.com
// home   : http://sourceforge.net/projects/douml
//
// *************************************************************************

#ifndef PACKAGECANVAS_H
#define PACKAGECANVAS_H

#include "DiagramCanvas.h"
//Added by qt3to4:
#include <QTextStream>

#define PACKAGE_CANVAS_MIN_WIDTH 64
#define PACKAGE_CANVAS_MIN_HEIGHT 32

class PackageCanvas : public QObject, public DiagramCanvas
{
    Q_OBJECT

protected:
    bool in_tab;
    Uml3States name_in_tab;
    Uml3States show_stereotype_properties;
    ShowContextMode show_context_mode;
    UmlColor itscolor;
    UmlColor used_color;
    QString full_name;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
public:
    PackageCanvas(BrowserNode * bn, UmlCanvas * canvas, int x, int y, int id);
    virtual ~PackageCanvas();

    virtual void delete_it() override;

    virtual void draw(QPainter & p);

    virtual UmlCode typeUmlCode() const override;
    virtual void delete_available(BooL & in_model, BooL & out_model) const override;
    virtual bool alignable() const override;
    virtual bool copyable() const override;
    virtual void remove(bool from_model) override;
    virtual void open() override;
    virtual void menu(const QPoint &) override;
    virtual QString may_start(UmlCode &) const override;
    virtual QString may_connect(UmlCode & l, const DiagramItem * dest) const override;
    virtual void connexion(UmlCode, DiagramItem *, const QPoint &, const QPoint &) override;
    virtual aCorner on_resize_point(const QPoint & p) override;
    using DiagramCanvas::resize;
    virtual void resize(aCorner c, int dx, int dy, QPoint &) override;
    virtual void resize(const QSize & sz, bool w, bool h) override;
    virtual void prepare_for_move(bool on_resize) override;
    virtual bool move_with_its_package() const override;
    virtual void change_scale() override;
    virtual void history_save(QBuffer &) const override;
    virtual void history_load(QBuffer &) override;
    virtual void history_hide() override;

    virtual bool has_drawing_settings() const override;
    virtual void edit_drawing_settings(QList<DiagramItem *> &) override;
    virtual void clone_drawing_settings(const DiagramItem *src) override;
    void edit_drawing_settings();
    virtual bool get_show_stereotype_properties() const override;

    virtual void apply_shortcut(const QString & s) override;

    virtual void save(QTextStream &, bool ref, QString & warning) const override;
    static PackageCanvas * read(char *& , UmlCanvas * canvas, char *);
    virtual void post_loaded() override;

    void check_size();
    int min_width();
    int min_height();

private slots:
    void modified();	// canvas must be updated
    void deleted();	// the package is deleted
};

#endif
