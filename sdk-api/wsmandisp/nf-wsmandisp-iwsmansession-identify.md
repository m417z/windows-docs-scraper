# IWSManSession::Identify

## Description

The **IWSManSession::Identify** method queries a remote computer to determine if it supports the WS-Management protocol. For more information, see [Detecting Whether a Remote Computer Supports WS-Management Protocol](https://learn.microsoft.com/windows/desktop/WinRM/detecting-whether-a-remote-computer-supports-ws-management-protocol).

## Parameters

### `flags` [in, optional]

The only flag that is accepted is **WSManFlagUseNoAuthentication**.

### `result` [out]

A value that, upon success, is an XML string that specifies the WS-Management protocol version, the operating system vendor and, if the request was sent authenticated, the operating system version.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWSManSession](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmansession)

[Session.Identify](https://learn.microsoft.com/windows/desktop/WinRM/session-identify)