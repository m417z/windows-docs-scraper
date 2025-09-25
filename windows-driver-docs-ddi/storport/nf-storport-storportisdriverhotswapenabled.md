## Description

A miniport driver calls the **StorPortIsDriverHotSwapEnabled** function to determine whether driver hot swap is enabled in the kernel.

## Parameters

### `HwDeviceExtension`

[in] A pointer to the hardware device extension for the host bus adapter (HBA).

### `DriverObject`

[in] Pointer to the driver object.

## Return value

**StorPortIsDriverHotSwapEnabled** returns a STOR_STATUS_SUCCESS if driver hot swap is enabled. Otherwise, it returns a value such as:

| Return value | Description |
|--------------|-------------|
| STOR_STATUS_INVALID_PARAMETER | The driver object is NULL. |
| STOR_STATUS_NOT_IMPLEMENTED | This function isn't implemented on the active operating system. |

## Remarks

## See also

[**StorPortRegisterDriverProxy**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportregisterdriverproxy)

[**StorPortRegisterDriverProxyEndpoints**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportregisterdriverproxyendpoints)

[**StorPortGetDriverProxyEndpointWrapper**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetdriverproxyendpointwrapper)