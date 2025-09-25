# WTSCLIENTA structure

## Description

Contains information about a Remote Desktop Connection (RDC) client.

## Members

### `ClientName`

The NetBIOS name of the client computer.

### `Domain`

The domain name of the client computer.

### `UserName`

The client user name.

### `WorkDirectory`

The folder for the initial program.

### `InitialProgram`

The program to start on connection.

### `EncryptionLevel`

The security level of encryption.

### `ClientAddressFamily`

The address family. This member can be **AF_INET**, **AF_INET6**, **AF_IPX**, **AF_NETBIOS**, or **AF_UNSPEC**.

### `ClientAddress`

The client network address.

### `HRes`

Horizontal dimension, in pixels, of the client's display.

### `VRes`

Vertical dimension, in pixels, of the client's display.

### `ColorDepth`

Color depth of the client's display. For possible values, see the **ColorDepth**
member of the [WTS_CLIENT_DISPLAY](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_client_display)
structure.

### `ClientDirectory`

The location of the client ActiveX control DLL.

### `ClientBuildNumber`

The client build number.

### `ClientHardwareId`

Reserved.

### `ClientProductId`

Reserved.

### `OutBufCountHost`

The number of output buffers on the server per session.

### `OutBufCountClient`

The number of output buffers on the client.

### `OutBufLength`

The length of the output buffers, in bytes.

### `DeviceId`

The device ID of the network adapter.

## Remarks

For the **ClientAddressFamily** member, **AF_INET** (IPv4) will return in string format, for example "127.0.0.1".
**AF_INET6** (IPv6) will return in binary form.

> [!NOTE]
> The wtsapi32.h header defines WTSCLIENT as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).