/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the Qt Labs Platform module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QQUICKPLATFORMFILEDIALOG_P_H
#define QQUICKPLATFORMFILEDIALOG_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include "qquickplatformdialog_p.h"
#include <QtCore/qurl.h>
#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

class QQuickPlatformFileDialog : public QQuickPlatformDialog
{
    Q_OBJECT
    Q_PROPERTY(FileMode fileMode READ fileMode WRITE setFileMode NOTIFY fileModeChanged FINAL)
    Q_PROPERTY(QUrl currentFile READ currentFile WRITE setCurrentFile NOTIFY currentFileChanged FINAL)
    Q_PROPERTY(QFileDialogOptions::FileDialogOptions options READ options WRITE setOptions RESET resetOptions NOTIFY optionsChanged FINAL)
    Q_PROPERTY(QStringList nameFilters READ nameFilters WRITE setNameFilters RESET resetNameFilters NOTIFY nameFiltersChanged FINAL)
    Q_PROPERTY(QString defaultSuffix READ defaultSuffix WRITE setDefaultSuffix RESET resetDefaultSuffix NOTIFY defaultSuffixChanged FINAL)
    Q_PROPERTY(QString acceptLabel READ acceptLabel WRITE setAcceptLabel RESET resetAcceptLabel NOTIFY acceptLabelChanged FINAL)
    Q_PROPERTY(QString rejectLabel READ rejectLabel WRITE setRejectLabel RESET resetRejectLabel NOTIFY rejectLabelChanged FINAL)
    Q_FLAGS(QFileDialogOptions::FileDialogOptions)

public:
    explicit QQuickPlatformFileDialog(QObject *parent = nullptr);

    enum FileMode {
        OpenFile,
        OpenFiles,
        SaveFile
    };
    Q_ENUM(FileMode)

    FileMode fileMode() const;
    void setFileMode(FileMode fileMode);

    QUrl currentFile() const;
    void setCurrentFile(const QUrl &file);

    QFileDialogOptions::FileDialogOptions options() const;
    void setOptions(QFileDialogOptions::FileDialogOptions options);
    void resetOptions();

    QStringList nameFilters() const;
    void setNameFilters(const QStringList &filters);
    void resetNameFilters();

    QString defaultSuffix() const;
    void setDefaultSuffix(const QString &suffix);
    void resetDefaultSuffix();

    QString acceptLabel() const;
    void setAcceptLabel(const QString &label);
    void resetAcceptLabel();

    QString rejectLabel() const;
    void setRejectLabel(const QString &label);
    void resetRejectLabel();

Q_SIGNALS:
    void fileModeChanged();
    void currentFileChanged();
    void optionsChanged();
    void nameFiltersChanged();
    void defaultSuffixChanged();
    void acceptLabelChanged();
    void rejectLabelChanged();

    void fileSelected(const QUrl &file);
    void filesSelected(const QList<QUrl> &files);

protected:
    void applyOptions() override;

private:
    FileMode m_fileMode;
    mutable QUrl m_current;
    QSharedPointer<QFileDialogOptions> m_options;
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QQuickPlatformFileDialog)

#endif // QQUICKPLATFORMFILEDIALOG_P_H