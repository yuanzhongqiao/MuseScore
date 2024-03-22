/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-CLA-applies
 *
 * MuseScore
 * Music Composition & Notation
 *
 * Copyright (C) 2024 MuseScore BVBA and others
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef MU_ENGRAVING_APIV1_ENGRAVINGAPIV1_H
#define MU_ENGRAVING_APIV1_ENGRAVINGAPIV1_H

#include "global/api/apiobject.h"

#include "extensions/api/v1/iapiv1object.h"

#include "score.h"
#include "enums.h"

namespace mu::engraving::apiv1 {
class PluginAPI;
class EngravingApiV1 : public mu::api::ApiObject, public extensions::apiv1::IApiV1Object
{
    Q_OBJECT

    Q_PROPERTY(apiv1::Score * curScore READ curScore CONSTANT)

    Q_PROPERTY(apiv1::Enum * Element READ elementEnum CONSTANT)

public:
    EngravingApiV1(mu::api::IApiEngine* e);
    ~EngravingApiV1();

    void setup(QJSValue globalObject) override;

    void setApi(PluginAPI* api);
    PluginAPI* api() const;

    //! Api V1 (qml plugin api)
    apiv1::Score* curScore() const;
    apiv1::Enum* elementEnum() const;

    Q_INVOKABLE void cmd(const QString& code);
    Q_INVOKABLE void quit();

private:
    mutable PluginAPI* m_api = nullptr;
    mutable bool m_selfApi = false;
};
}

#endif // MU_ENGRAVING_APIV1_ENGRAVINGAPIV1_H
