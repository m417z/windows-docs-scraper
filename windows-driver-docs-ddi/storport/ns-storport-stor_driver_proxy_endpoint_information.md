## Description

The **STOR_DRIVER_PROXY_ENDPOINT_INFORMATION** structure contains information about a driver proxy endpoint.

## Members

### `Id`

Unique identifier for the endpoint function that **EndpointFunction** points to.

### `EndpointFunction`

Pointer to the driver's endpoint function. **EndpointFunction** must point to a function that has **ParameterCount** parameters.

### `ParameterCount`

Number of parameters that the endpoint function takes.

## Remarks

## See also

[**StorPortRegisterDriverProxyEndpoints**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportregisterdriverproxyendpoints)