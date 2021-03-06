/*
 * Copyright (C) 2020 SuNNjek <sunnerlp@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

// own
#include "MenuButton.h"
#include "Decoration.h"

// KDecoration
#include <KDecoration2/DecoratedClient>

// KF
#include <KColorUtils>
#include <KIconLoader>

// Qt
#include <QPainter>

namespace Fluent
{
    MenuButton::MenuButton(Decoration *decoration, QObject *parent)
            : DecorationButton(KDecoration2::DecorationButtonType::Menu, decoration, parent)
    {
        auto *decoratedClient = decoration->client().toStrongRef().data();
        connect(decoratedClient, &KDecoration2::DecoratedClient::iconChanged, this,
                [this] {
                    update();
                });

        const int titleBarHeight = decoration->titleBarHeight();
        const QSize size(titleBarHeight, titleBarHeight);
        setGeometry(QRect(QPoint(0, 0), size));
        setVisible(decoratedClient->isMaximizeable());
    }

    MenuButton::~MenuButton()
    {
    }

    void MenuButton::paint(QPainter *painter, const QRect &repaintRegion)
    {
        Q_UNUSED(repaintRegion)

        const QSizeF iconSize(24, 24);
        QRectF iconRect( geometry().topLeft(), iconSize );
        iconRect.moveCenter(geometry().center().toPoint());

        const auto *decoratedClient = decoration()->client().toStrongRef().data();
        if (const auto *deco = qobject_cast<Decoration *>(decoration()))
        {
            const QPalette activePalette = KIconLoader::global()->customPalette();
            QPalette palette = decoratedClient->palette();

            palette.setColor(QPalette::Foreground, deco->titleBarForegroundColor());
            KIconLoader::global()->setCustomPalette(palette);
            decoratedClient->icon().paint(painter, iconRect.toRect());

            if (activePalette == QPalette())
            {
                KIconLoader::global()->resetPalette();
            }
            else
            {
                KIconLoader::global()->setCustomPalette(palette);
            }
        }
        else
        {
            decoratedClient->icon().paint(painter, iconRect.toRect());
        }
    }
}
