## Description

**StorPortRegisterDriverProxyEndpoints** registers driver proxy endpoints with the kernel.

## Parameters

### `HwDeviceExtension`

[in] A pointer to the hardware device extension for the host bus adapter (HBA).

### `ProxyExtension`

[in] Pointer to opaque data that contains the driver proxy extension. Storport returns this information when the miniport driver calls [**StorPortRegisterDriverProxy**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportregisterdriverproxy).

### `EndpointInfo`

[in/out] Pointer to an array of [**STOR_DRIVER_PROXY_ENDPOINT_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_driver_proxy_endpoint_information) structures that contain the driver proxy endpoint information.

### `Count`

[in] The number of elements in the array that **EndpointInfo** points to.

## Return value

**StorPortRegisterDriverProxyEndpoints** returns one of the following STOR_STATUS codes:

| Return code | Description |
| ----------- | ----------- |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STOR_STATUS_SUCCESS** | The operation was successful. |
| **STOR_STATUS_INVALID_PARAMETER** | The operation fails with this return value if one or more of the parameters are invalid. |

## Remarks

## See also

[**STOR_DRIVER_PROXY_ENDPOINT_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_driver_proxy_endpoint_information)

[**StorPortGetDriverProxyEndpointWrapper**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetdriverproxyendpointwrapper)

[**StorPortRegisterDriverProxy**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportregisterdriverproxy)