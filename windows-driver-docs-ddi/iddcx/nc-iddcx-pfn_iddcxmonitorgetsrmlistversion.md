# PFN_IDDCXMONITORGETSRMLISTVERSION callback function

## Description

**PFN_IDDCXMONITORGETSRMLISTVERSION** is a pointer to an OS callback function that retrieves the latest System Renewability Message (SRM) list version stored by the GPU.

## Parameters

### `DriverGlobals` [in]

Contains system-defined per-driver data.

### `MonitorObject` [in]

The monitor object that the SRM list is associated with.

### `pInArgs` [in]

Input arguments of the function.

### `pOutArgs` [out]

Output arguments of function.

## Return value

Returns NTSTATUS with the following error codes:

| Return value | Description |
| --- | --- |
| STATUS_SUCCESS | The routine succeeded. |
| STATUS_GRAPHICS_OPM_NOT_SUPPORTED | The GPU driver does not support this new functionality. |
| STATUS_NO_DATA_DETECTED | The GPU does not have a current SRM list. |
| STATUS_BUFFER_TOO_SMALL | The passed in buffer is too small. |

## Remarks

An indirect display driver (IDD) should not use this pointer to directly call the function that it points to. IDDs should instead call [**IddCxMonitorGetSrmListVersion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorgetsrmlistversion).

## See also

[**IddCxMonitorGetSrmListVersion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorgetsrmlistversion)