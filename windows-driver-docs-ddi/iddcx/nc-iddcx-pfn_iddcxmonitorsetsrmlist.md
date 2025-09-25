# PFN_IDDCXMONITORSETSRMLIST callback function

## Description

**PFN_IDDCXMONITORSETSRMLIST** is a pointer to an OS callback function that passes a High-Bandwidth Digital Content Protection (HDCP) System Renewability Message (SRM) list to the GPU driver associated with the rendering of the specified monitor.

## Parameters

### `DriverGlobals` [in]

Contains system-defined per-driver data.

### `MonitorObject` [in]

The monitor object that the SRM list is associated with.

### `pInArgs` [in]

Input arguments of function.

## Return value

Returns NTSTATUS with the following error codes:

| Return value | Description |
| --- | --- |
| STATUS_SUCCESS | The routine succeeded. |
| STATUS_GRAPHICS_OPM_NOT_SUPPORTED | The GPU driver does not support this new functionality. |
| STATUS_GRAPHICS_OPM_INVALID_SRM | the GPU driver does recognize the format of the SRM list, this include if the driver detected the list had been tampered with. |

## Remarks

An indirect display driver (IDD) should not use this pointer to directly call the function that it points to. IDDs should instead call [**IddCxMonitorSetSrmList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorsetsrmlist).

## See also

[**IddCxMonitorSetSrmList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorsetsrmlist)