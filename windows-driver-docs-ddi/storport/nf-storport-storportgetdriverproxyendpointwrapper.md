## Description

**StorPortGetDriverProxyEndpointWrapper** retrieves the address of a wrapped function pointer for a driver's endpoint.

## Parameters

### `HwDeviceExtension`

[in] A pointer to the hardware device extension for the host bus adapter (HBA).

### `ProxyExtension`

[in] Pointer to an opaque structure that contains the driver proxy extension.

### `Id`

[in] The identifier of the driver's endpoint function.

### `Wrapper`

[out] Pointer to a location in which to receive the address of the wrapped function.

## Return value

**StorPortGetDriverProxyEndpointWrapper** returns **STOR_STATUS_SUCCESS** if the wrapper is sucessfully returned. Otherwise, it returns one of the following STOR_STATUS codes:

| Return code | Description |
| ----------- | ----------- |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STOR_STATUS_INVALID_PARAMETER** | The operation fails with this return value if one or more of the parameters are invalid. |

## Remarks

## See also

[**StorPortIsDriverHotSwapEnabled**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportisdriverhotswapenabled)

[**StorPortRegisterDriverProxy**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportregisterdriverproxy)

[**StorPortRegisterDriverProxyEndpoints**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportregisterdriverproxyendpoints)