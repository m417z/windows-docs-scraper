## Description

The **IoGetDriverProxyExtensionFromDriverObject** function retrieves the DriverProxy extension that is owned by the specified driver object.

## Parameters

### `DriverObject`

[in] A pointer to the [**DRIVER_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object) that owns the DriverProxy extension to retrieve.

## Return value

**IoGetDriverProxyExtensionFromDriverObject** returns a pointer to the DriverProxy extension owned by the specified driver object, or NULL if the driver object does not have an associated DriverProxy extension.

## Remarks

This function provides a simple way to retrieve an existing DriverProxy extension that was previously created with [**IoCreateDriverProxyExtension**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedriverproxyextension) and associated with a driver object, without needing to store the extension pointer separately. The function is commonly used when a driver needs to access its DriverProxy extension from different parts of its code.

The function can be called at any IRQL level and does not perform any memory allocation or complex operations.

If the driver object's **DriverExtension** field is NULL, the function will return NULL and may trigger an assertion in debug builds.

## See also

[**IoCreateDriverProxyExtension**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedriverproxyextension)

[**IoRegisterDriverProxyEndpoints**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterdriverproxyendpoints)

[**DRIVER_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object)