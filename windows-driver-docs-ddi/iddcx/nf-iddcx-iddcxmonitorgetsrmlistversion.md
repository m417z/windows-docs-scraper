# IddCxMonitorGetSrmListVersion function

## Description

**IddCxMonitorGetSrmListVersion** retrieves the latest System Renewability Message (SRM) list version stored by the GPU.

## Parameters

### `MonitorObject` [in]

The [IDDCX_MONITOR](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-objects) object that the SRM list is associated with.

### `pInArgs` [in]

Pointer to an [**IDARG_IN_GETSRMLISTVERSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_getsrmlistversion) structure with input parameters.

### `pOutArgs` [out]

Pointer to an [**IDARG_OUT_GETSRMLISTVERSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_getsrmlistversion) structure in which the OS returns output.

## Return value

If the routine succeeds it returns STATUS_SUCCESS; otherwise it returns an appropriate error code such as one of the following:

| Error code | Meaning |
| ---------- | ------- |
| STATUS_GRAPHICS_OPM_NOT_SUPPORTED | The GPU driver does not support this functionality. |
| STATUS_NO_DATA_DETECTED | The GPU does not have a current SRM list. |
| STATUS_BUFFER_TOO_SMALL | The buffer that **pOutArgs** points to is too small. |

## Remarks

An indirect display driver (IDD) calls **IddCxMonitorGetSrmListVersion** to retrieve the latest SRM list version stored by the GPU. To set an SRM list, call [**IddCxMonitorSetSrmList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorsetsrmlist).

SRMs are used to update the list of revoked High-Bandwidth Digital Content Protection (HDCP) devices, and are delivered with the video content.

## See also

[**IDARG_IN_GETSRMLISTVERSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_getsrmlistversion)

[**IDARG_OUT_GETSRMLISTVERSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_getsrmlistversion)

[**IddCxMonitorSetSrmList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorsetsrmlist)