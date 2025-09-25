## Description

The **IoGetDriverProxyWrapperFromEndpoint** macro gets the pointer to the wrapper for an endpoint function using the endpoint function pointer. This macro provides a convenient wrapper around [**IofGetDriverProxyWrapperFromEndpoint**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iofgetdriverproxywrapperfromendpoint) with automatic type casting.

This macro is the standard method for retrieving endpoint wrappers in Driver Hot-Swap V2. It handles the type casting automatically and provides a cleaner interface compared to calling the underlying function directly.

## Parameters

### `DriverProxyExtension`

[in] A pointer to the DriverProxy extension that the endpoints are registered to. This extension was created in a prior call to [**IoCreateDriverProxyExtension**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedriverproxyextension).

### `Endpoint`

[in] A pointer to a [**DRIVER_PROXY_ENDPOINT_FUNCTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_proxy_endpoint_function) endpoint function for which to find the wrapper. This must be a function pointer that was identified during the automatic endpoint enumeration process in Driver Hot-Swap V2.

### `Wrapper`

[out] A pointer to a variable that receives a pointer to a [**DRIVER_PROXY_ENDPOINT_FUNCTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_proxy_endpoint_function) wrapper function. If the endpoint is found, **Wrapper** will be set to point to the wrapper function that should be called instead of the original endpoint. If the endpoint isn't found, **Wrapper** is set to NULL.

## Remarks

This macro is designed for Driver Hot-Swap V2, which uses automatic compiler-based endpoint enumeration rather than manual endpoint registration. The endpoint pointer passed to this macro must exactly match a pointer that was identified during the automatic endpoint enumeration process.

The macro handles type casting automatically, making it more convenient to use than the underlying [**IofGetDriverProxyWrapperFromEndpoint**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iofgetdriverproxywrapperfromendpoint) function. This eliminates potential compiler warnings related to pointer type conversions.

The macro can be used at any IRQL level and performs a fast lookup operation.

Once a wrapper is obtained, drivers should call the wrapper function instead of the original endpoint function to enable hot-swappable functionality. This allows the function implementation to be replaced at runtime without unloading the driver.

In Driver Hot-Swap V2, endpoints are automatically discovered and registered during the build process through compiler and linker analysis of the `.shsept` section, eliminating the need for manual endpoint registration.

## See also

[**IofGetDriverProxyWrapperFromEndpoint**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iofgetdriverproxywrapperfromendpoint)

[**IoCreateDriverProxyExtension**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedriverproxyextension)

[**DRIVER_PROXY_ENDPOINT_FUNCTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_proxy_endpoint_function)