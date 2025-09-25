# MBN_CONTEXT_TYPE enumeration

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The **MBN_CONTEXT_TYPE** enumerated type specifies the represented context type.

## Constants

### `MBN_CONTEXT_TYPE_NONE:0`

Context has not yet provisioned for this ID.

### `MBN_CONTEXT_TYPE_INTERNET`

Context represents a connection to the internet.

### `MBN_CONTEXT_TYPE_VPN`

Context represents a connection to a VPN or corporate network.

### `MBN_CONTEXT_TYPE_VOICE`

Context represents a connection to VoIP service.

### `MBN_CONTEXT_TYPE_VIDEO_SHARE`

Context represents a connection to a video share service.

### `MBN_CONTEXT_TYPE_CUSTOM`

Context represents a connection to a custom service.

### `MBN_CONTEXT_TYPE_PURCHASE`

Windows 8 or later: Context represents a purchase connection such as a walled garden, hot-lining, or captive portal.