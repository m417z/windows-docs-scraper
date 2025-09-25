# IWSMan::CreateSession

## Description

Creates a [Session](https://learn.microsoft.com/windows/desktop/WinRM/session) object that can then be used for subsequent network operations.

## Parameters

### `connection` [in]

The protocol and service to connect to, including either IPv4 or IPv6. The format of the connection information is as follows: <*Transport*><*Address*><*Suffix*>. For examples, see Remarks. If no connection information is provided, the local computer is used.

### `flags` [in]

The session flags that specify the authentication method, such as
[Negotiate authentication](https://learn.microsoft.com/windows/desktop/WinRM/windows-remote-management-glossary)
or
[Digest authentication](https://learn.microsoft.com/windows/desktop/WinRM/windows-remote-management-glossary),
for connecting to a remote computer. These flags also specify other session connection information, such as
encoding or encryption. This parameter must contain one or more of the flags in
**__WSManSessionFlags** for a remote connection. For more information, see
[Session Constants](https://learn.microsoft.com/windows/desktop/WinRM/session-constants). No flag settings are required for a
connection to the WinRM service on the local computer.

If no authentication flags are specified, Kerberos is used unless one of the following conditions is true,
in which case Negotiate is used:

* explicit credentials are supplied and the destination host is trusted
* the destination host is "localhost", "127.0.0.1" or "[::1]"
* the client computer is in a workgroup and the destination host is trusted

For more information, see [Authentication for Remote Connections](https://learn.microsoft.com/windows/desktop/WinRM/authentication-for-remote-connections) and the *connectionOptions* parameter.

### `connectionOptions` [in]

A pointer to an [IWSManConnectionOptions](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanconnectionoptions) object that contains a user name and password. The default is **NULL**.

### `session` [out]

A pointer to a new [IWSManSession](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmansession) object.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The following list contains examples of formats used to specify connection information in the *connection* parameter (when creating an HTTPS session, the <*Address*> field must match the server computer certificate name, otherwise a failure occurs):

* "https://service"

  Uses HTTPS to connect to the default web service location.
* "https://service.corp.com/websvcs/wsman"

  Uses HTTPS to connect to the specific web service location.
* "https://[E3D7:0000:0000:0000:51F4:9BC8:C0A8:6420]"

  Uses HTTPS and IPv6 with the default port.
* "https://[E3D7:0000:0000:0000:51F4:9BC8:C0A8:6420]:9999/wsman"

  Uses HTTPS and IPv6 with the given port.

## See also

[IWSMan](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsman)

[WSMan.CreateSession](https://learn.microsoft.com/windows/desktop/WinRM/wsman-createsession)