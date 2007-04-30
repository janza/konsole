/*
    Copyright (C) 2007 by Robert Knight <robertknight@gmail.com>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
    02110-1301  USA.
*/

#ifndef EDITSESSIONDIALOG_H
#define EDITSESSIONDIALOG_H

// Qt
#include <QAbstractItemDelegate>

// KDE
#include <KDialog>


namespace Ui
{
    class EditProfileDialog;
};

namespace Konsole
{

class Profile;
class MutableSessionInfo;

/**
 * A dialog which allows the user to edit a session type.
 *
 * TODO: More documentation
 */
class EditProfileDialog : public KDialog
{
Q_OBJECT

public:
    /** Constructs a new dialog with the specified parent. */
    EditProfileDialog(QWidget* parent = 0);
    virtual ~EditProfileDialog();

    /**
     * Initialises the dialog with the settings for the specified session
     * type.
     *
     * @param key The key for the session type provided by the SessionManager instance
     */
    void setProfile(const QString& key);

    /**
     * Returns a profile instance representing the new or modified profile.
     */
    Profile* newProfile();

private slots:
    // general page
    void selectInitialDir();

    // appearence page
    void setFontSize(int pointSize);
    void showFontDialog();

private:
    // initialize various pages of the dialog
    void setupGeneralPage(const Profile* info);
    void setupAppearencePage(const Profile* info);
    void setupKeyboardPage(const Profile* info);
    void setupScrollingPage(const Profile* info);
    void setupAdvancedPage(const Profile* info);

    // apply changes from various pages of the dialog
    void applyGeneralPage(MutableSessionInfo* info);
    void applyAppearencePage(MutableSessionInfo* info);
    void applyKeyboardPage(MutableSessionInfo* info);
    void applyScrollingPage(MutableSessionInfo* info);
    void applyAdvancedPage(MutableSessionInfo* info);

    Ui::EditProfileDialog* _ui;
    QString _profileKey;
};

/**
 * A delegate which can display and edit color schemes in a view.
 */
class ColorSchemeViewDelegate : public QAbstractItemDelegate
{
public:
    ColorSchemeViewDelegate(QObject* parent = 0);

    // reimplemented
    virtual void paint(QPainter* painter, const QStyleOptionViewItem& option,
                       const QModelIndex& index) const;
    virtual QSize sizeHint( const QStyleOptionViewItem& option,
                       const QModelIndex& index) const;

   // virtual bool editorEvent(QEvent* event,QAbstractItemModel* model,
   //                          const QStyleOptionViewItem& option, const QModelIndex& index);
};

/**
 * A delegate which can display and edit key bindings in a view.
 */
class KeyBindingViewDelegate : public QAbstractItemDelegate
{
public:
    KeyBindingViewDelegate(QObject* parent = 0);

    // reimplemented
    virtual void paint(QPainter* painter, const QStyleOptionViewItem& option,
                       const QModelIndex& index) const;
    virtual QSize sizeHint( const QStyleOptionViewItem& option,
                       const QModelIndex& index) const;

};

};
#endif // EDITSESSIONDIALOG_H

