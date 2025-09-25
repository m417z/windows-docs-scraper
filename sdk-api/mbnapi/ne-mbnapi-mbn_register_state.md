# MBN_REGISTER_STATE enumeration

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The **MBN_REGISTER_STATE** enumerated type indicates the network registration state of a Mobile Broadband device.

## Constants

### `MBN_REGISTER_STATE_NONE:0`

The device registration state is unknown. This state may be set upon failure of registration mode change requests.

### `MBN_REGISTER_STATE_DEREGISTERED`

The device is not registered and not searching for a provider.

### `MBN_REGISTER_STATE_SEARCHING`

The device is not registered and is searching for a provider.

### `MBN_REGISTER_STATE_HOME`

The device is on a home provider.

### `MBN_REGISTER_STATE_ROAMING`

The device is on a roaming provider.

### `MBN_REGISTER_STATE_PARTNER`

The device is on a roaming partner.

### `MBN_REGISTER_STATE_DENIED`

The device was denied registration. Emergency voice calls may be made. This applies to voice and not data.