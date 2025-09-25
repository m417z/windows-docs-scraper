## Description

The **IoCreateDriverProxyExtension** function allocates and initializes a DriverProxy extension that enables hot-swappable driver functionality.

## Parameters

### `OwningDriverObject`

[in, optional] An optional pointer to the [**DRIVER_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object) that will own the DriverProxy extension. If provided, the extension will be associated with this driver object. If NULL, the extension is created without an owning driver.

### `Flags`

[in] A [**DRIVER_PROXY_EXTENSION_CREATION_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-driver_proxy_extension_creation_flags) value that provides additional configuration options for extension creation. Currently, no flags are defined, so this parameter should be set to 0.

### `DriverProxyExtension`

[out] A pointer to a variable that receives a pointer to the newly created DriverProxy extension. This extension can be used with other DriverProxy APIs.

## Return value

**IoCreateDriverProxyExtension** returns one of the following NTSTATUS values:

| Return code | Description |
|-------------|-------------|
| **STATUS_SUCCESS** | The extension was successfully allocated and initialized. |
| **STATUS_NOT_SUPPORTED** | The current system does not support DriverProxy extensions. |
| **STATUS_DRIVER_BLOCKED** | The specified driver is excluded from DriverProxy operations via registry settings. |
| **STATUS_INSUFFICIENT_RESOURCES** | Insufficient memory was available to allocate the extension. |
| **STATUS_RESOURCE_IN_USE** | The specified driver object already owns a DriverProxy extension. |

## Remarks

A DriverProxy extension is required for any driver that wants to use Driver Hot-Swap functionality. The extension serves as an opaque token that holds all relevant DriverProxy information and enables hot-swappable operations.

Drivers using Driver Hot-Swap should create a DriverProxy extension during [**DriverEntry**](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-a-driverentry-routine), preferably early in the function. It is recommended to store the result in a global variable for easy access throughout the driver's lifetime.

Before calling **IoCreateDriverProxyExtension**, drivers should call [**IoGetDriverProxyFeatures**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdriverproxyfeatures) to verify that DriverProxy functionality is available and enabled.

Each driver object can own at most one DriverProxy extension. If a driver object already has an associated extension, the function returns **STATUS_RESOURCE_IN_USE**.

In Driver Hot-Swap V2, once the extension is successfully created, endpoint wrappers are automatically available without requiring explicit registration calls. The compiler and linker automatically generate the endpoint information during the build process.

The system automatically manages the lifecycle of the DriverProxy extension. When the owning driver object is unloaded, the extension is automatically cleaned up.

## See also

[**IoGetDriverProxyFeatures**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdriverproxyfeatures)

[**IoGetDriverProxyWrapperFromEndpoint**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdriverproxywrapperfromendpoint)

[**IoGetDriverProxyExtensionFromDriverObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdriverproxyextensionfromdriverobject)

[**DRIVER_PROXY_EXTENSION_CREATION_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-driver_proxy_extension_creation_flags)

[**DRIVER_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object)