# DXGKDDI_DPAUXIOTRANSMISSION callback function

## Description

The **DXGKDDI_DPAUXIOTRANSMISSION** callback reads or writes DisplayPort Configuration Data (DPCD) for devices directly attached on the GPU.

## Parameters

### `Context`

Context pointer provided when querying the interface.

### `pArgs`

Pointer to a [DXGKARG_DPAUXIOTRANSMISSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkarg_dpauxiotransmission) structure.

## Return value

**DXGKDDI_DPAUXIOTRANSMISSION** returns STATUS_SUCCESS if it succeeds; otherwise it returns an error code such as one of the following:

| Error Code | Meaning |
| ---------- | ------- |
| STATUS_DRIVER_INTERNAL_ERROR | An internal software error occurred.|
| STATUS_ACCESS_DENIED | The request is not supported. For Windows 10 version 2004, only native AUX read is supported. |
| STATUS_BUFFER_TOO_SMALL | The buffer is too small for the operation. |
| STATUS_DEVICE_HARDWARE_ERROR | A hardware error occurred. |
| STATUS_DEVICE_POWERED_OFF | The device is powered off. |
| STATUS_DEVICE_NOT_CONNECTED | The device is not connected. |
| STATUS_DEVICE_PROTOCOL_ERROR | An error occurred at the DP AUX protocol level. The driver can use **DPNativeError** to encode more details about the error. |

## Remarks

Write operations are not supported in Windows 10, version 2004 and should be blocked.

## See also

[DXGKARG_DPAUXIOTRANSMISSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkarg_dpauxiotransmission)