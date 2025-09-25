# VideoPortLogError function

## Description

The **VideoPortLogError** function logs errors to the system event log when a miniport driver detects a hardware error condition during I/O operations.

## Parameters

### `HwDeviceExtension`

Pointer to the miniport driver's device extension.

### `Vrp`

[optional] Pointer to a [**VIDEO_REQUEST_PACKET**] structure that describes the video request packet (VRP) if one is associated with the error; otherwise NULL.

### `ErrorCode`

Specifies a miniport driver-defined error code that indicates the type of hardware error.

### `UniqueId`

Specifies a unique identifier for the error. This value differentiates the current error from other errors with the same **ErrorCode**. For some miniport drivers, this identifies the line of code where the error was detected; for others, it is a value returned by the hardware.

## Return value

None

## Remarks

Miniport drivers should call **VideoPortLogError** to notify the user if the driver encounters unusual hardware errors during normal operations. Posting such errors to the system event log warns the user that the video adapter might be failing so the user can replace (or reconfigure) the adapter before a total hardware failure occurs.

However, miniport drivers should *not* log errors, such as "failed to detect hardware," that occur frequently during normal operation.

**VideoPortLogError** can be called from a miniport driver's [**HwVidInterrupt**](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt) or [**HwVidSynchronizeExecutionCallback**](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_synchronize_routine) function.

## See also

[**VideoDebugPrint**](https://learn.microsoft.com/previous-versions/ff570170(v=vs.85))