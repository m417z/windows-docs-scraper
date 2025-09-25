## Description

> [!NOTE]
> This function is used for Driver Hot-Swap V1 only. New drivers should use Driver Hot-Swap V2, which handles endpoint registration automatically through compiler-based endpoint enumeration.

The **IoRegisterDriverProxyEndpoints** function registers endpoint functions to a DriverProxy extension, enabling hot-swappable driver functionality in Driver Hot-Swap V1 implementations.

## Parameters

### `DriverProxyExtension`

[in] A pointer to the DriverProxy extension that the endpoints will be registered to. This extension must have been created with [**IoCreateDriverProxyExtension**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedriverproxyextension).

### `EndpointInfo`

[in, out] An array of [**DRIVER_PROXY_ENDPOINT_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-driver_proxy_endpoint_information) structures that describe the endpoint functions to register. The function may modify the contents of this array during registration.

### `Count`

[in] The number of elements in the **EndpointInfo** array.

### `PhasedCallback`

[in, optional] An optional pointer to a [**DRIVER_PROXY_REGISTER_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_proxy_register_callback) function that will be called at various phases during the registration process to allow driver-specific operations.

### `Context`

[in, optional] An optional context pointer that will be passed to the **PhasedCallback** function.

## Return value

**IoRegisterDriverProxyEndpoints** returns one of the following NTSTATUS values:

| Return code | Description |
|-------------|-------------|
| **STATUS_SUCCESS** | The endpoints were successfully registered. |
| **STATUS_INSUFFICIENT_RESOURCES** | Insufficient memory was available to register the endpoints. |
| **STATUS_INVALID_PARAMETER_3** | One or more endpoint information structures attempted to overwrite an existing function with a different parameter count. |
| **STATUS_UNSUCCESSFUL** | The operation timed out while waiting for existing function calls to complete. |

## Remarks

This function establishes the mapping between original driver functions and their hot-swappable wrappers. Once registered, calls to the original functions will be redirected through the DriverProxy system, allowing the functions to be replaced at runtime without unloading the driver.

This function performs a complex multi-phase operation to safely replace function pointers while existing calls may be in progress. The registration process includes:

* Pre-processing phase: The optional **PhasedCallback** is called with **DriverProxyRegisterCallbackPreProcess** to allow driver preparation.

* Rundown acquisition: The function waits for all existing calls to registered endpoints to complete before proceeding.

* Proxy stalled phase: The **PhasedCallback** is called with **DriverProxyRegisterCallbackProxyStalled** while all calls are blocked.

* Function replacement: The actual function pointers are updated atomically.

* Post-processing phase: The **PhasedCallback** is called with **DriverProxyRegisterCallbackPostProcess** to allow driver cleanup.

If an endpoint has the same ID as an existing registered endpoint, the endpoint will be replaced, but only if it has the same parameter count.

This function serves dual purposes in Driver Hot-Swap V1: initial endpoint registration (where **PhasedCallback** should be NULL) and endpoint swapping during hot-swap operations.

The function must be called at PASSIVE_LEVEL as it may need to wait for existing function calls to complete.

## See also

[**IoCreateDriverProxyExtension**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedriverproxyextension)

[**DRIVER_PROXY_ENDPOINT_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-driver_proxy_endpoint_information)

[**DRIVER_PROXY_REGISTER_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_proxy_register_callback)

[**IoGetDriverProxyWrapperFromEndpoint**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdriverproxywrapperfromendpoint)