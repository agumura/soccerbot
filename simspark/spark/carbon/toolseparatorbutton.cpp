/* -*- mode: c++; c-basic-offset: 4; indent-tabs-mode: nil -*-

   This file is part of Carbon
   Author: Patrick Geib
   $Id: toolseparatorbutton.cpp 398 2015-09-12 01:47:34Z hedayat $

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#include "toolseparatorbutton.h"

#include <QToolButton>

ToolSeparatorButton::ToolSeparatorButton(QWidget* parent) :
    QToolButton(parent)
{
    setCheckable(true);
    setChecked(false);
    setArrowType(Qt::LeftArrow);
    connect(this, SIGNAL(toggled(bool)), this, SLOT(updateArrow(bool)));
}

ToolSeparatorButton::~ToolSeparatorButton()
{

}

void ToolSeparatorButton::updateArrow(bool state)
{
    if (state == true)
        setArrowType(Qt::RightArrow);
    else
        setArrowType(Qt::LeftArrow);
}
