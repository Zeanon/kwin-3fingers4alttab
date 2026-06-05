// SPDX-FileCopyrightText: 2024 kwin-3fingerswipe4alttab contributors
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <effect/effect.h>

namespace KWin
{

class SwipeForAltTabEffect : public Effect
{
    Q_OBJECT

public:
    SwipeForAltTabEffect();

private:
    void walkForward();
    void walkBackward();
    void invokeWindowWalk(const QString &shortcutName);
};

} // namespace KWin
