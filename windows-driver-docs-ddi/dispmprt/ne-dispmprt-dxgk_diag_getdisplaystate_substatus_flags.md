# DXGK_DIAG_GETDISPLAYSTATE_SUBSTATUS_FLAGS enumeration

## Description

**DXGK_DIAG_GETDISPLAYSTATE_SUBSTATUS_FLAGS** specifies the substatus for per target diagnostic data collection.

## Constants

### `DXGK_DIAG_GETDISPLAYSTATE_SUCCESS`

No errors occurred on the given vidpntarget while collecting the diagnostic information.

### `DXGK_DIAG_GETDISPLAYSTATE_CAUSED_GLITCH`

A user-visible glitch occurred on a given vidpntarget while collecting the diagnostic information.

### `DXGK_DIAG_GETDISPLAYSTATE_CHANGED_DISPLAY_STATE`

A display state change (hardware or software) was caused while collecting the diagnostic information on the given vidpntarget.

### `DXGK_DIAG_GETDISPLAYSTATE_MONITOR_NOT_CONNECTED`

No monitor was detected as connected on the given vidpntarget.

### `DXGK_DIAG_GETDISPLAYSTATE_TIMEOUT`

The driver hit a timeout while collecting the diagnostic information on a given vidpntarget.

### `DXGK_DIAG_GETDISPLAYSTATE_ERROR_HARDWARE`

The driver hit a hardware error while collecting the diagnostic information on a given vidpntarget.

### `DXGK_DIAG_GETDISPLAYSTATE_ERROR_DRIVER`

The driver hit a software error while collecting the diagnostic information on a given vidpntarget.

### `DXGK_DIAG_GETDISPLAYSTATE_VIDPNTARGETID_NOT_FOUND`

The driver did not find the VidPnTargetId provided by the OS in the DDI call.

## Remarks

The **DXGK_DIAG_GETDISPLAYSTATE_SUBSTATUS_FLAGS** enumeration is a member of the [**DXGK_DISPLAYSTATE_NONINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_displaystate_nonintrusive) structure. It is used while gathering display diagnostic information via calls to [**DxgkDdiGetDisplayStateNonIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystatenonintrusive).

In rare cases where a platform-specific implementation requires the driver to carry out intrusive operations during a call to **DxgkDdiGetDisplayStateNonIntrusive**, the driver should carry out these operations but must set **DXGK_DIAG_GETDISPLAYSTATE_SUBSTATUS_FLAGS** to DXGK_DIAG_GETDISPLAYSTATE_CAUSED_GLITCH or DXGK_DIAG_GETDISPLAYSTATE_CHANGED_DISPLAY_STATE accordingly. The OS can use this information to decide whether to call the DDI for error scenarios only on a given system.

The substatus information helps the driver succeed the overall [**DxgkDdiGetDisplayStateNonIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystatenonintrusive) call even if there were failure or errors on some of the targets.

## See also

[**DXGK_DISPLAYSTATE_NONINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_displaystate_nonintrusive)

[**DXGKARG_GETDISPLAYSTATENONINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkarg_getdisplaystatenonintrusive)

[**DxgkDdiGetDisplayStateNonIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystatenonintrusive)