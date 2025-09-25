## Description

**StorPortRegisterDriverProxy** creates a driver proxy endpoint for the specified driver object.

## Parameters

### `HwDeviceExtension`

[in] A pointer to the hardware device extension for the host bus adapter (HBA).

### `DriverObject`

[in] A pointer to the driver object.

### `ProxyExtension`

[out] Pointer to StorPort's opaque data that contains the allocated driver proxy extension.

## Return value

**StorPortRegisterDriverProxy** returns one of the following status codes:

| Return code | Description |
| ----------- | ----------- |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STOR_STATUS_SUCCESS** | The operation was successful. |
| **STOR_STATUS_INVALID_PARAMETER** | The operation fails with this return value if one or more of the parameters are invalid. |

## Remarks

## See also

[**StorPortGetDriverProxyEndpointWrapper**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetdriverproxyendpointwrapper)

[**StorPortRegisterDriverProxyEndpoints**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportregisterdriverproxyendpoints)