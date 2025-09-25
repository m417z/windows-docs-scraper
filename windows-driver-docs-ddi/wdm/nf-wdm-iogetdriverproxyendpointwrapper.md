## Description

> [!WARNING]
> **IoGetDriverProxyEndpointWrapper** is only available in Driver Hot-Swap V1 and is not supported in Driver Hot-Swap V2. New drivers should use Driver Hot-Swap V2 with [**IoGetDriverProxyWrapperFromEndpoint**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdriverproxywrapperfromendpoint) instead.

The **IoGetDriverProxyEndpointWrapper** function gets the pointer to the wrapper for an endpoint function using a function ID in Driver Hot-Swap V1 implementations.

## Parameters

### `DriverProxyExtension`

[in] A pointer to the DriverProxy extension that contains the registered endpoints.

### `FunctionId`

[in] The function ID of the endpoint function to search for. This is a deprecated mechanism for identifying endpoint functions.

## Return value

**IoGetDriverProxyEndpointWrapper** returns a pointer to the endpoint wrapper function, or NULL if the specified function ID could not be found.

## Remarks

This function is only available in Driver Hot-Swap V1 and is not supported in Driver Hot-Swap V2. New drivers should use Driver Hot-Swap V2 with [**IoGetDriverProxyWrapperFromEndpoint**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdriverproxywrapperfromendpoint) instead.

The function ID approach was used in the original Driver Hot-Swap implementation but is not part of the current Driver Hot-Swap V2 system.

## See also

[**IoGetDriverProxyWrapperFromEndpoint**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdriverproxywrapperfromendpoint)

[**IoRegisterDriverProxyEndpoints**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterdriverproxyendpoints)