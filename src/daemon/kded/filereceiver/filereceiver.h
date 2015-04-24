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

#ifndef FILE_RECEIVER_H
#define FILE_RECEIVER_H

#include <QObject>

#include <BluezQt/ObexManager>

namespace BluezQt
{
    class PendingCall;
}

class ObexAgent;

class FileReceiver : public QObject
{
    Q_OBJECT

public:
    explicit FileReceiver(BluezQt::ManagerPtr manager, QObject *parent = Q_NULLPTR);
    ~FileReceiver();

private Q_SLOTS:
    void initJobResult(BluezQt::InitObexManagerJob *job);
    void agentRegistered(BluezQt::PendingCall *call);
    void operationalChanged(bool operational);

private:
    BluezQt::ObexManager *m_manager;
    ObexAgent *m_agent;
};

#endif // FILE_RECEIVER_H
