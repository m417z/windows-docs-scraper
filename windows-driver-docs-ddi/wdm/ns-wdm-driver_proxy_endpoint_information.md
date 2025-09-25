## Description

> [!NOTE]
> This structure is used for Driver Hot-Swap V1 only. New drivers should use Driver Hot-Swap V2, which handles endpoint registration automatically through compiler-based endpoint enumeration.

The **DRIVER_PROXY_ENDPOINT_INFORMATION** structure contains information about a DriverProxy endpoint function that is being registered for hot-swappable functionality in Driver Hot-Swap V1 implementations.

## Members

### `Id`

A unique identifier for the endpoint function. This ID is used to identify the endpoint within the DriverProxy system and must be unique within the scope of the DriverProxy extension. If an endpoint with the same ID already exists, it will be replaced during registration, provided the parameter count matches.

### `EndpointFunction`

A pointer to the [**DRIVER_PROXY_ENDPOINT_FUNCTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_proxy_endpoint_function) that represents the endpoint function to be registered. This is the actual function that will be made hot-swappable through the DriverProxy system.

### `ParameterCount`

The number of parameters that the endpoint function accepts. This value is used for validation during endpoint registration. If an endpoint with the same ID already exists, the parameter count must match exactly, or the registration will fail with **STATUS_INVALID_PARAMETER_3**.

## Remarks

This structure is used with [**IoRegisterDriverProxyEndpoints**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterdriverproxyendpoints) to register endpoint functions in Driver Hot-Swap V1 implementations, which require manual registration. Each structure in the array describes one endpoint function that should be made hot-swappable.

Driver Hot-Swap V2 automatically discovers and registers endpoints during the build process, eliminating the need for this structure in newer implementations.

When registering multiple endpoints, all endpoints in the array are processed atomically. Either all endpoints are successfully registered, or the entire operation fails and no changes are made.

## See also

[**IoRegisterDriverProxyEndpoints**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterdriverproxyendpoints)

[**DRIVER_PROXY_ENDPOINT_FUNCTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_proxy_endpoint_function)

[**DRIVER_PROXY_REGISTER_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_proxy_register_callback)

[**IoCreateDriverProxyExtension**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedriverproxyextension)

[**IoGetDriverProxyEndpointWrapper**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdriverproxyendpointwrapper)