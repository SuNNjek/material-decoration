/*
 * Copyright (C) 2018 Vlad Zagorodniy <vladzzag@gmail.com>
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

#pragma once

// own
#include "FluentDecorationButton.h"

// KDecoration
#include <KDecoration2/DecorationButton>

namespace Fluent
{
    class Decoration;

    class MinimizeButton : public FluentDecorationButton
    {
    Q_OBJECT

    public:
        MinimizeButton(Decoration *decoration, QObject *parent = nullptr);

        void paint(QPainter *painter, const QRect &repaintRegion) override;
    };
}
