# DXGKDDI_GETDISPLAYSTATENONINTRUSIVE callback function

## Description

The operating system calls a display miniport driver's **DxgkDdiGetDisplayStateNonIntrusive** routine to nonintrusively collect display state information from the driver.

## Parameters

### `Context` [in]

Pointer to a private context returned by [**DxgkDdiQueryInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_interface).

### `pArgs` [in/out]

Pointer to a [**DXGKARG_GETDISPLAYSTATENONINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkarg_getdisplaystatenonintrusive) structure.

## Return value

**DxgkDdiGetDisplayStateNonIntrusive** returns STATUS_SUCCESS if it succeeds. Otherwise it returns an error code such as one of the following.

| Error Code | Meaning |
| ---------- | ------- |
| STATUS_DRIVER_INTERNAL_ERROR | A generic software error occurred inside the driver. |
| STATUS_ACCESS_DENIED | The hardware is being currently used by other threads and this DDI can't get access to it. |
| STATUS_DEVICE_HARDWARE_ERROR | Generic HW error happened. |
| STATUS_DEVICE_POWERED_OFF | The device is powered off. |

## Remarks

The OS calls **DxgkDdiGetDisplayStateNonIntrusive** to collect display state information from the driver. Unlike [**DxgkDdiGetDisplayStateIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystateintrusive), the driver's **DxgkDdiGetDisplayStateNonIntrusive** routine should not perform any operations that cause visible side effects to the user, and the collection process should be relatively fast (ideally within a few milliseconds). This routine's calling frequency will be relatively high. Apart from being called for diagnosing bad user state, the OS might also use this routine for recording historical state information from the driver for debugging purposes.

In rare cases where a platform-specific implementation requires the driver to carry out intrusive operations as part of a call to **DxgkDdiGetDisplayStateNonIntrusive**, the driver should carry out the operations but must set **pArgs->ReturnSubStatus** to DXGK_DIAG_GETDISPLAYSTATE_CAUSED_GLITCH or DXGK_DIAG_GETDISPLAYSTATE_CHANGED_DISPLAY_STATE accordingly. Based on the **ReturnSubStatus** value, the operating system (OS) might only call this routine for error scenarios on a given system.

The OS will call **DxgkDdiGetDisplayStateNonIntrusive** frequently (either periodically or on other commonly occurring events) to gather driver state data for debugging purposes and to look at the historical timeline. The OS will also call this routine in particular error scenarios (such as black screens) before gathering more detailed information by calling [**DxgkDdiGetDisplayStateIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystateintrusive). Given the possible frequency of this call, drivers should complete it as quickly as possible. The OS will call this DDI with **NumOfTargets** set to the maximum number of targets supported by the given graphics adapter and **VidPnTargetId** filled in. The miniport driver should only fill the display state information for targets on which there is actually a monitor connected. For a vidpntarget on which there is no monitor connected, the miniport should just fill in DXGK_DIAG_DISPLAY_CONNECTIVITY and the OS will ignore all other fields for that target.

> [!NOTE]
> Drivers should only use **ReturnSubStatus** to report error conditions and not use DXGK_DIAG_GETDISPLAYSTATE_MONITOR_NOT_CONNECTED for reporting monitor connectivity state. The main purpose of DXGK_DIAG_GETDISPLAYSTATE_MONITOR_NOT_CONNECTED is for intrusive calls where the OS doesn't ask about monitor connectivity.
>
> If driver hits a failure on a given vidpntarget while collecting information, it should use **ReturnSubStatus** to set the error state and proceed to the next vidpntarget and not fail the overall call unless all the paths hit failures. Drivers should ideally record errors hit during this call in some internal error log so that when the OS calls [**DxgkDdiCollectDiagnosticInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_collectdiagnosticinfo) for collecting black box information, these errors are captured as part of an internal log collection to help IHVs during debug.

Synchronization level for this DDI is [zero level synchronization](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-zero-level).

## See also

[**DXGKARG_GETDISPLAYSTATENONINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkarg_getdisplaystatenonintrusive)

[**DxgkDdiCollectDiagnosticInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_collectdiagnosticinfo)

[**DxgkDdiGetDisplayStateIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystateintrusive)

[**DxgkDdiQueryInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_interface)