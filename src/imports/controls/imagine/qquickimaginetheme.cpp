/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the Qt Quick Controls 2 module of the Qt Toolkit.
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

#include "qquickimaginetheme_p.h"

#include <QtGui/qfontinfo.h>

QT_BEGIN_NAMESPACE

QQuickImagineTheme::QQuickImagineTheme()
    : QQuickTheme(QStringLiteral("Imagine"))
{
    QFont font;
    font.setFamily(QLatin1String("Open Sans"));
    const QString family = QFontInfo(font).family();
    if (family == QLatin1String("Open Sans")) {
        buttonFont.setFamily(family);
        checkBoxFont.setFamily(family);
        editorFont.setFamily(family);
        groupBoxFont.setFamily(family);
        labelFont.setFamily(family);
        itemViewFont.setFamily(family);
        menuItemFont.setFamily(family);
        systemFont.setFamily(family);
        toolTipFont.setFamily(family);
    }

    const QColor accentColor = QColor::fromRgb(0x4fc1e9);
    const QColor windowTextColor = QColor::fromRgb(0x434a54);
    const QColor disabledWindowTextColor = QColor::fromRgb(0xccd1d9);

    systemPalette.setColor(QPalette::ButtonText, Qt::white);
    systemPalette.setColor(QPalette::BrightText, Qt::white);
    systemPalette.setColor(QPalette::Highlight, accentColor);
    systemPalette.setColor(QPalette::HighlightedText, Qt::white);
    systemPalette.setColor(QPalette::Text, windowTextColor);
    systemPalette.setColor(QPalette::ToolTipText, Qt::white);
    systemPalette.setColor(QPalette::WindowText, windowTextColor);
    systemPalette.setColor(QPalette::Disabled, QPalette::Text, disabledWindowTextColor);
    systemPalette.setColor(QPalette::Disabled, QPalette::WindowText, disabledWindowTextColor);
    systemPalette = resolvePalette(systemPalette);
}

const QFont *QQuickImagineTheme::font(QPlatformTheme::Font type) const
{
    switch (type) {
    case QPlatformTheme::TabButtonFont:
    case QPlatformTheme::PushButtonFont:
    case QPlatformTheme::ToolButtonFont:
        return &buttonFont;
    case QPlatformTheme::CheckBoxFont:
        return &checkBoxFont;
    case QPlatformTheme::GroupBoxTitleFont:
        return &groupBoxFont;
    case QPlatformTheme::LabelFont:
        return &labelFont;
    case QPlatformTheme::TipLabelFont:
        return &toolTipFont;
    case QPlatformTheme::ItemViewFont:
        return &itemViewFont;
    case QPlatformTheme::MenuItemFont:
    case QPlatformTheme::ComboMenuItemFont:
        return &menuItemFont;
    case QPlatformTheme::EditorFont:
        return &editorFont;
    default:
        return &systemFont;
    }
}

const QPalette *QQuickImagineTheme::palette(QPlatformTheme::Palette type) const
{
    Q_UNUSED(type);
    return &systemPalette;
}

QT_END_NAMESPACE