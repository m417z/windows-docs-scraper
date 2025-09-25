# MBN_MSG_STATUS enumeration

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The **MBN_MSG_STATUS** enumerated type defines the type of message being handled.

## Constants

### `MBN_MSG_STATUS_NEW:0`

The received message is newly arrived or unread.

### `MBN_MSG_STATUS_OLD`

The received message is old and read.

### `MBN_MSG_STATUS_DRAFT`

The outgoing message is unsent and stored in the device.

### `MBN_MSG_STATUS_SENT`

The outgoing message is already sent.