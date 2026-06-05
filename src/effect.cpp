// SPDX-FileCopyrightText: 2024 kwin-3fingerswipe4alttab contributors
// SPDX-License-Identifier: GPL-2.0-or-later

#include "effect.h"

#include <effect/effecthandler.h>
#include <effect/globals.h>

#include <QAction>
#include <QDBusConnection>
#include <QDBusMessage>
#include <QDBusPendingCall>

namespace KWin
{

SwipeForAltTabEffect::SwipeForAltTabEffect()
{
    // 3-finger swipe left → Walk Through Windows (previous window in MRU order)
    auto *forwardAction = new QAction(this);
    forwardAction->setObjectName(QStringLiteral("3fingerswipe-walk-forward"));
    connect(forwardAction, &QAction::triggered, this, &SwipeForAltTabEffect::walkForward);
    effects->registerTouchpadSwipeShortcut(SwipeDirection::Left, 3, forwardAction);

    // 3-finger swipe right → Walk Through Windows Reverse (next window in MRU order)
    auto *backwardAction = new QAction(this);
    backwardAction->setObjectName(QStringLiteral("3fingerswipe-walk-backward"));
    connect(backwardAction, &QAction::triggered, this, &SwipeForAltTabEffect::walkBackward);
    effects->registerTouchpadSwipeShortcut(SwipeDirection::Right, 3, backwardAction);
}

void SwipeForAltTabEffect::walkForward()
{
    invokeWindowWalk(QStringLiteral("Walk Through Windows"));
}

void SwipeForAltTabEffect::walkBackward()
{
    invokeWindowWalk(QStringLiteral("Walk Through Windows (Reverse)"));
}

// Triggers the existing KWin "Walk Through Windows" shortcut via kglobalaccel.
// This reuses the same tabbox UI as Alt+Tab — no custom rendering needed.
void SwipeForAltTabEffect::invokeWindowWalk(const QString &shortcutName)
{
    QDBusMessage msg = QDBusMessage::createMethodCall(
        QStringLiteral("org.kde.kglobalaccel"),
        QStringLiteral("/component/kwin"),
        QStringLiteral("org.kde.kglobalaccel.Component"),
        QStringLiteral("invokeShortcut")
    );
    msg << shortcutName;
    QDBusConnection::sessionBus().asyncCall(msg);
}

} // namespace KWin
