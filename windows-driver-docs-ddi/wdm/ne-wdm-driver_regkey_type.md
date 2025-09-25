# DRIVER_REGKEY_TYPE enumeration

## Description

Defines values for the type of registry key to be used by a driver. This enumeration is used by the [**IoOpenDriverRegistryKey**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioopendriverregistrykey) function.

## Constants

### `DriverRegKeyParameters`

The requested registry key is the immutable parameters key for the driver.

### `DriverRegKeyPersistentState`

The requested registry key is a location for mutable state to be read/written that will persist across reboots. This mutable state is specific to the internals of the driver and only accessible by the driver itself.

### `DriverRegKeySharedPersistentState`

The requested registry key is a location for mutable state to be read/written that will persist across reboots. This mutable state is meant to be shared between the driver and other components. Other components can access this registry key using GetSharedServiceRegistryStateKey. This value is available on Windows Server 2022 and later versions of Windows.

## Remarks

## See also

[**IoOpenDriverRegistryKey**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioopendriverregistrykey)