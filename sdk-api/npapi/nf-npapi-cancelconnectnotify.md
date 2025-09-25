# CancelConnectNotify function

## Description

The [Multiple Provider Router](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) (MPR) calls **CancelConnectNotify** before and after each cancel connection operation ([WNetCancelConnection](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetcancelconnectiona) and
[WNetCancelConnection2](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetcancelconnection2a)).

## Parameters

### `lpNotifyInfo` [in, out]

A pointer to a
[NOTIFYINFO](https://learn.microsoft.com/windows/desktop/api/npapi/ns-npapi-notifyinfo) structure that contains information about the notification.

### `lpCancelInfo` [in]

A pointer to a
[NOTIFYCANCEL](https://learn.microsoft.com/windows/desktop/api/npapi/ns-npapi-notifycancel) structure that contains the cancel connection specific information.

## Return value

If the function succeeds, the function should return WN_SUCCESS.

If the function fails, it should return an error code. This can be any of the error codes specified in
[Network Security Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/network-security-return-values).

## Remarks

The **CancelConnectNotify** function is implemented by applications that need to receive notification from the MPR when a network resource is connected or disconnected. For more information about how to write an application that receives such notifications, see
[Receiving Connection Notifications](https://learn.microsoft.com/windows/desktop/SecAuthN/receiving-connection-notifications).

## See also

[AddConnectNotify](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-addconnectnotify)