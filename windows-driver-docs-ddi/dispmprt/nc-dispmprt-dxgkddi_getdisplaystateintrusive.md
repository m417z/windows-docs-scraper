# DXGKDDI_GETDISPLAYSTATEINTRUSIVE callback function

## Description

The operating system (OS) calls a display miniport driver's **DxgkDdiGetDisplayStateNonIntrusive** routine to collect display state information from the driver.

## Parameters

### `Context` [in]

Pointer to a private context returned by [**DxgkDdiQueryInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_interface).

### `pArgs` [in/out]

Pointer to a [**DXGKARG_GETDISPLAYSTATEINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkarg_getdisplaystateintrusive) structure.

## Return value

**DxgkDdiGetDisplayStateIntrusive** returns STATUS_SUCCESS if it succeeds. Otherwise it returns an error code such as one of the following.

| Error Code | Meaning |
| ---------- | ------- |
| STATUS_DRIVER_INTERNAL_ERROR | A generic software error occurred inside the driver. |
| STATUS_ACCESS_DENIED | The hardware is being currently used by other threads and this DDI can't get access to it. |
| STATUS_DEVICE_HARDWARE_ERROR | Generic HW error happened. |
| STATUS_DEVICE_POWERED_OFF | The device is powered off. |

## Remarks

The OS calls **DxgkDdiGetDisplayStateIntrusive** to collect display state information from the driver when the user is already in a bad state. Unlike [**DxgkDdiGetDisplayStateNonIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystatenonintrusive), the driver's **DxgkDdiGetDisplayStateIntrusive** routine can carry out more intrusive operations that have visible side effects to the user . An intrusive operation is defined as follows (non-intrusive operations do not have any of these properties):

* It causes side effects (glitches) that are visible to the user (such as temporarily stopping scan out and destructive monitor connectivity check).

* It is slow, and affects system or display performance if called frequently (multiple times in a second).

* It changes the state of the display subsystem (or any other subsystem) directly or indirectly.

The driver should not change the state of the system intentionally when collecting data.

The OS will call this routine much less frequently relative to calls to [**DxgkDdiGetDisplayStateNonIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystatenonintrusive). In the majority of error scenarios, the OS will first call **DxgkDdiGetDisplayStateNonIntrusive** and then call **DxgkDdiGetDisplayStateIntrusive** to ensure that any unintentional effect of the intrusive call is not affecting the non-intrusive data collection.

DXGKRNL will call this routine with **NumOfTargets** set to the number of targets on which the OS reports that there is a monitor connected with corresponding **VidPnTargetId** filled in. When the driver believes there is no monitor connected on a given target then it should set the **ReturnSubStatus** for that target to be DXGK_DIAG_GETDISPLAYSTATE_MONITOR_NOT_CONNECTED.

> [!NOTE]
> If the driver hits a failure on a given vidpntarget while collecting information, it should use **ReturnSubStatus** to set the error state and proceed to the next vidpntarget and not fail the overall call unless all the paths hit failures. Drivers should ideally record errors hit during this call in some internal error log so that when OS calls [**DxgkDdiCollectDiagnosticInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_collectdiagnosticinfo) for collecting black box information, these errors are captured as part of an internal log collection to help IHVs debug.
>
> The OS will have a sufficient timeout (approximately 5 seconds) for **DxgkDdiGetDisplayStateIntrusive** to complete, giving the driver more time to collect all the relevant state. After a timeout, the OS might bugcheck the machine and collect a dump if the driver hangs in this call, so the miniport should try to always complete this call within the time frame.

Synchronization level for this DDI is [zero level synchronization](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-zero-level).

## See also

[**DXGKARG_GETDISPLAYSTATEINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkarg_getdisplaystateintrusive)

[**DxgkDdiCollectDiagnosticInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_collectdiagnosticinfo)

[**DxgkDdiGetDisplayStateNonIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystatenonintrusive)

[**DxgkDdiQueryInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_interface)