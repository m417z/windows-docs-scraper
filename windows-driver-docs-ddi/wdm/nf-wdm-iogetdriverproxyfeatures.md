## Description

The **IoGetDriverProxyFeatures** function gets the DriverProxy feature flags for the current system and the specified driver.

This function allows drivers to determine whether DriverProxy functionality is available and enabled for their specific driver instance. DriverProxy enables hot-swappable driver functionality by allowing drivers to register endpoint functions that can be replaced at runtime without unloading the driver.

## Parameters

### `DriverObject`

[in, optional] An optional pointer to the [**DRIVER_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object) to check for DriverProxy support. If this parameter is NULL, the function checks whether DriverProxy is enabled for all drivers on the system.

### `Flags`

[out] A pointer to a [**DRIVER_PROXY_FEATURE_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-driver_proxy_feature_flags) structure that receives the DriverProxy feature flags. The structure indicates whether DriverProxy functionality is available and enabled.

## Return value

This function does not return a value.

## Remarks

The **IoGetDriverProxyFeatures** function determines DriverProxy availability based on several factors:

- Whether the system supports DriverProxy functionality
- Whether the Secure Kernel is running (required for DriverProxy)
- Whether the specific driver is excluded from DriverProxy operations via registry settings
- Whether DriverProxy has been globally disabled

Drivers should call this function before attempting to use other DriverProxy APIs such as [**IoCreateDriverProxyExtension**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedriverproxyextension) or [**IoRegisterDriverProxyEndpoints**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterdriverproxyendpoints).

The function can be called at any IRQL level and is safe to use during driver initialization.

## See also

[**DRIVER_PROXY_FEATURE_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-driver_proxy_feature_flags)

[**IoCreateDriverProxyExtension**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedriverproxyextension)

[**IoRegisterDriverProxyEndpoints**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterdriverproxyendpoints)

[**DRIVER_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object)