## Description

The **DRIVER_PROXY_EXTENSION_CREATION_FLAGS** structure contains configuration flags for DriverProxy extension creation.

## Members

### `AsUlong`

The complete set of creation flags as a single **ULONG** value. This provides access to all flags as a 32-bit integer for easy initialization, comparison, or storage. Currently, this value should always be 0.

### `ReservedZero`

A 32-bit field that is reserved and must be set to zero. This field is reserved for potential future expansion of DriverProxy extension creation options.

## Remarks

The **DRIVER_PROXY_EXTENSION_CREATION_FLAGS** structure is designed as a union that allows access to the creation flags either as individual bit fields or as a complete **ULONG** value.

Currently, no configuration flags are defined for DriverProxy extension creation. Drivers should initialize this structure to zero before passing it to [**IoCreateDriverProxyExtension**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedriverproxyextension).

## See also

[**IoCreateDriverProxyExtension**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedriverproxyextension)