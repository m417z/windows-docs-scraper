# IWTSProtocolManager::NotifySessionStateChange

## Description

[**IWTSProtocolManager::NotifySessionStateChange** is no longer available for use as of Windows Server 2012. Instead, use [IWRdsProtocolManager::NotifySessionStateChange](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolmanager-notifysessionstatechange).]

Notifies the protocol provider of changes in the state of a session.

## Parameters

### `SessionId` [in]

A pointer to a [WTS_SESSION_ID](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_session_id) structure that uniquely identifies the session.

### `EventId` [in]

An integer that contains the event ID. The following IDs can be found in Winuser.h.

#### WTS_CONSOLE_CONNECT (0x1)

#### WTS_CONSOLE_DISCONNECT (0x2)

#### WTS_REMOTE_CONNECT (0x3)

#### WTS_SESSION_LOGOFF (0x6)

#### WTS_SESSION_LOCK (0x7)

#### WTS_SESSION_UNLOCK (0x8)

#### WTS_SESSION_REMOTE_CONTROL (0x9)

## Return value

When you are implementing this method, return **S_OK** if the function succeeds. If it fails, return an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IWTSProtocolManager](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocolmanager)