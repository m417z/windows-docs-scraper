## Description

The **IofGetDriverProxyWrapperFromEndpoint** function gets the pointer to the wrapper for an endpoint function using the endpoint function pointer.

## Parameters

### `DriverProxyExtension`

[in] A pointer to the DriverProxy extension that the endpoints are registered to. This extension was created in a prior call to [**IoCreateDriverProxyExtension**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedriverproxyextension).

### `Endpoint`

[in] A pointer to the endpoint function for which to find the wrapper. This must be a function pointer that was previously registered with [**IoRegisterDriverProxyEndpoints**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterdriverproxyendpoints).

### `Wrapper`

[out] A pointer to a variable that receives a pointer to the wrapped endpoint function. If the endpoint is found, this will point to the wrapper function that should be called instead of the original endpoint.

## Return value

**IofGetDriverProxyWrapperFromEndpoint** returns one of the following NTSTATUS values:

| Return code | Description |
|-------------|-------------|
| **STATUS_SUCCESS** | The wrapper function was successfully found and returned. |
| **STATUS_NOT_FOUND** | The specified endpoint function was not found in the registered endpoints. |

## Remarks

This function is the standard method for retrieving endpoint wrappers in Driver Hot-Swap V2. The endpoint pointer passed to this function must exactly match a pointer that was identified during the automatic endpoint enumeration process.

To avoid compiler warnings when calling this function, you might need to cast the **Endpoint** and **Wrapper** parameters. For convenience, a macro **IoGetDriverProxyWrapperFromEndpoint** is provided that handles the type casting automatically. It is recommended to use the macro instead of calling this function directly.

The function can be called at any IRQL level and performs a fast lookup operation.

Once a wrapper is obtained, drivers should call the wrapper function instead of the original endpoint function to enable hot-swappable functionality.

## See also

[**IoCreateDriverProxyExtension**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedriverproxyextension)

[**DRIVER_PROXY_ENDPOINT_FUNCTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_proxy_endpoint_function)