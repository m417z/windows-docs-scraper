# AddConnectNotify function

## Description

The **AddConnectNotify** function is called before and after each add connection operation ([WNetAddConnection](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnectiona),
[WNetAddConnection2](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnection2a), and
[WNetAddConnection3](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnection3a)) is attempted by the [Multiple Provider Router](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) (MPR).

The **AddConnectNotify** function is not called when MPR is automatically restoring network connections.

## Parameters

### `lpNotifyInfo` [in, out]

A pointer to a
[NOTIFYINFO](https://learn.microsoft.com/windows/desktop/api/npapi/ns-npapi-notifyinfo) structure that contains information about the notification.

### `lpAddInfo` [in]

A pointer to a
[NOTIFYADD](https://learn.microsoft.com/windows/desktop/api/npapi/ns-npapi-notifyadd) structure that contains information about the connection being added.

## Return value

If the function succeeds, the function should return WN_SUCCESS.

If the function fails, it should return an error code. This can be any of the error codes specified in
[Network Security Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/network-security-return-values).

## Remarks

The **AddConnectNotify** function is implemented by applications that need to receive notification from the MPR when a network resource is connected or disconnected. For more information about how to write an application that receives such notifications, see
[Receiving Connection Notifications](https://learn.microsoft.com/windows/desktop/SecAuthN/receiving-connection-notifications).

## See also

[CancelConnectNotify](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-cancelconnectnotify)