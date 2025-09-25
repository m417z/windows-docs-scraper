# MBN_ACTIVATION_STATE enumeration

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The **MBN_ACTIVATION_STATE** enumerated type indicates the current data connection state.

## Constants

### `MBN_ACTIVATION_STATE_NONE:0`

The connection state is unknown.

### `MBN_ACTIVATION_STATE_ACTIVATED`

The connection has been established.

### `MBN_ACTIVATION_STATE_ACTIVATING`

The device is establishing the connection.

### `MBN_ACTIVATION_STATE_DEACTIVATED`

There is no connection.

### `MBN_ACTIVATION_STATE_DEACTIVATING`

The device is in the process of disconnection.