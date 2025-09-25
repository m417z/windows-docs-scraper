# MBN_PROVIDER_STATE enumeration

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The **MBN_PROVIDER_STATE** enumerated type specifies the various states with which a provider entry can be tagged. These values are intended to be used together in a bitwise OR combination.

## Constants

### `MBN_PROVIDER_STATE_NONE:0`

Unknown provider state.

### `MBN_PROVIDER_STATE_HOME:0x1`

The provider is a home operator.

### `MBN_PROVIDER_STATE_FORBIDDEN:0x2`

The provider is on the forbidden list.

### `MBN_PROVIDER_STATE_PREFERRED:0x4`

The provider is on the preferred list.

### `MBN_PROVIDER_STATE_VISIBLE:0x8`

The provider is visible.

### `MBN_PROVIDER_STATE_REGISTERED:0x10`

Windows 8 or later: The provider is currently registered by the device.

### `MBN_PROVIDER_STATE_PREFERRED_MULTICARRIER:0x20`

Windows 8 or later: The provider is currently on the preferred multi-carrier list.

## Remarks

The following table provides the valid combinations of values for different operations.

| Operation | MBN_PROVIDER_STATE |
| --- | --- |
| Query Home Provider | MBN_PROVIDER_STATE_HOME |
| Query Preferred Providers | MBN_PROVIDER_STATE_FORBIDDEN |
| MBN_PROVIDER_STATE_PREFERRED |
| Query Visible Providers | MBN_PROVIDER_STATE_REGISTERED |
| MBN_PROVIDER_STATE_HOME |
| MBN_PROVIDER_STATE_PREFERRED |
| MBN_PROVIDER_STATE_FORBIDDEN |