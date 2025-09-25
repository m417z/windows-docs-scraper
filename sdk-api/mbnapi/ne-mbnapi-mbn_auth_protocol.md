# MBN_AUTH_PROTOCOL enumeration

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The **MBN_AUTH_PROTOCOL** enumerated type specifies the authentication protocol used for Packet Data Protocol (PDP) activation.

This type is applicable only for GSM devices.

## Constants

### `MBN_AUTH_PROTOCOL_NONE:0`

No authentication protocol is used.

### `MBN_AUTH_PROTOCOL_PAP`

Password Authentication Protocol (PAP) is used for authentication. PAP authentication is unencrypted.

### `MBN_AUTH_PROTOCOL_CHAP`

Challenge Handshake Authentication Protocol (CHAP) is used for authentication.

### `MBN_AUTH_PROTOCOL_MSCHAPV2`

Microsoft Challenge-Handshake Authentication Protocol version 2.0 (MS-CHAP v2) is used for authentication.