# IddCxMonitorSetSrmList function

## Description

**IddCxMonitorSetSrmList** passes a System Renewability Message (SRM) list to the GPU driver associated with the rendering of the specified monitor.

## Parameters

### `MonitorObject` [in]

The [IDDCX_MONITOR](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-objects) object that the SRM list is associated with.

### `pInArgs` [in]

Pointer to an [**IDARG_IN_SETSRMLIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_setsrmlist) structure with input parameters.

## Return value

If the routine succeeds it returns STATUS_SUCCESS; otherwise it returns an appropriate error code such as one of the following:

| Error code | Meaning |
| ---------- | ------- |
| STATUS_GRAPHICS_OPM_NOT_SUPPORTED | The GPU driver does not support this functionality. |
| STATUS_GRAPHICS_OPM_INVALID_SRM | The GPU driver does not recognize the format of the SRM list. This includes whether the driver detected the list had been tampered with. |

## Remarks

An indirect display driver (IDD) calls **IddCxMonitorGetSrmList** to pass a High-Bandwidth Digital Content Protection (HDCP) SRM list to the GPU driver associated with the rendering of the specified monitor. To get the SRM list version, call [**IddCxMonitorGetSrmListVersion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorgetsrmlistversion).

SRMs are used to update the list of revoked High-Bandwidth Digital Content Protection (HDCP) devices, and are delivered with the video content.

## See also

[**IDARG_IN_SETSRMLIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_setsrmlist)

[**IddCxMonitorGetSrmListVersion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorgetsrmlistversion)