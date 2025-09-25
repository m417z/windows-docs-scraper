## Description

The **DRIVER_PROXY_FEATURE_FLAGS** structure contains feature flags that indicate the availability and status of DriverProxy functionality for the current system and driver.

## Members

### `AsUlong`

The complete set of feature flags as a single **ULONG** value. This provides access to all flags as a 32-bit integer for easy initialization, comparison, or storage.

### `Enabled`

A single-bit flag that indicates whether DriverProxy functionality is enabled and available. When this bit is set to **1**, DriverProxy APIs such as [**IoCreateDriverProxyExtension**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedriverproxyextension) and [**IoRegisterDriverProxyEndpoints**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterdriverproxyendpoints) can be used successfully. When this bit is **0**, DriverProxy functionality is not available.

### `Reserved`

Reserved bits for future use. These bits are currently unused and should be ignored by drivers. They are reserved for potential future expansion of DriverProxy feature flags.

## Remarks

This structure is used by [**IoGetDriverProxyFeatures**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdriverproxyfeatures) to return information about whether DriverProxy hot-swappable functionality is supported and enabled. Drivers should call this function to retrieve the structure and check the **Enabled** flag before attempting to use DriverProxy APIs.

The **Enabled** flag is set based on several system conditions, including:

- The Secure Kernel must be running
- The system must be configured for DriverProxy operations
- The driver must not be excluded from DriverProxy functionality via registry settings
- DriverProxy must not be globally disabled

Drivers should initialize this structure to zero before passing it to [**IoGetDriverProxyFeatures**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdriverproxyfeatures) to ensure that any uninitialized bits do not contain random values.

## See also

[**IoGetDriverProxyFeatures**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdriverproxyfeatures)

[**IoCreateDriverProxyExtension**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedriverproxyextension)

[**IoRegisterDriverProxyEndpoints**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterdriverproxyendpoints)