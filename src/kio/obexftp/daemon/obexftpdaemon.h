/*************************************************************************************
 *  Copyright (C) 2013 by Alejandro Fiestas Fiestas <afiestas@kde.org>               *
 *                                                                                   *
 *  This program is free software; you can redistribute it and/or                    *
 *  modify it under the terms of the GNU General Public License                      *
 *  as published by the Free Software Foundation; either version 2                   *
 *  of the License, or (at your option) any later version.                           *
 *                                                                                   *
 *  This program is distributed in the hope that it will be useful,                  *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of                   *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                    *
 *  GNU General Public License for more details.                                     *
 *                                                                                   *
 *  You should have received a copy of the GNU General Public License                *
 *  along with this program; if not, write to the Free Software                      *
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA   *
 *************************************************************************************/

#ifndef OBEXFTPDAEMON_H
#define OBEXFTPDAEMON_H

#include <QLoggingCategory>

#include <KDEDModule>

#include <BluezQt/Types>

namespace BluezQt
{
    class InitObexManagerJob;
    class PendingCall;
}

class QDBusMessage;
class QDBusObjectPath;
class QDBusPendingCallWatcher;

class Q_DECL_EXPORT ObexFtpDaemon : public KDEDModule
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.kde.ObexFtp")

public:
    ObexFtpDaemon(QObject *parent, const QList<QVariant>&);
    ~ObexFtpDaemon();

    Q_SCRIPTABLE bool isOnline(const QDBusMessage &msg);
    Q_SCRIPTABLE QString session(const QString &address, const QString &target, const QDBusMessage &msg);
    Q_SCRIPTABLE bool cancelTransfer(const QString &transfer, const QDBusMessage &msg);

private Q_SLOTS:
    void initJobResult(BluezQt::InitObexManagerJob *job);
    void createSessionFinished(BluezQt::PendingCall *call);
    void cancelTransferFinished(QDBusPendingCallWatcher *watcher);

    void operationalChanged(bool operational);
    void sessionRemoved(BluezQt::ObexSessionPtr session);

private:
    struct Private;
    Private *d;
};

Q_DECLARE_LOGGING_CATEGORY(OBEXDAEMON)

#endif // OBEXFTPDAEMON_H
