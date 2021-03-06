/* -*- mode: c++; c-basic-offset: 4; indent-tabs-mode: nil -*-

   this file is part of rcssserver3D
   Fri May 9 2003
   Copyright (C) 2002,2003 Koblenz University
   Copyright (C) 2003 RoboCup Soccer Server 3D Maintenance Group
   $Id: bodycontroller.cpp 331 2013-02-13 08:31:45Z hedayat $

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
#include <oxygen/physicsserver/bodycontroller.h>
#include <oxygen/physicsserver/rigidbody.h>
#include <zeitgeist/logserver/logserver.h>

using namespace oxygen;
using namespace zeitgeist;
using namespace boost;

void BodyController::OnLink()
{
    UpdateCached();
}

void BodyController::OnUnlink()
{
    BaseNode::OnUnlink();
    mBody.reset();
}

void BodyController::UpdateCached()
{
    mBody.reset();

    mBody = dynamic_pointer_cast<RigidBody>
        (GetParentSupportingClass("RigidBody").lock());

    if (mBody.get() == 0)
    {
       GetLog()->Error() << "(BodyController) ERROR: found no parent body.\n";
       return;
    }
}
