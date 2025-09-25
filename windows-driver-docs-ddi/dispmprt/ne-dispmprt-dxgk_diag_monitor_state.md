# DXGK_DIAG_MONITOR_STATE enumeration

## Description

**DXGK_DIAG_MONITOR_STATE** specifies the state of the monitors according to the miniport driver, indicating to the operating system (OS) whether the monitors are ready to receive the pixels.

## Constants

### `DXGK_DIAG_MONITOR_STATE_UNINITIALIZED`

Reserved for OS use during diagnostic initialization.

### `DXGK_DIAG_MONITOR_READY`

The monitor is initialized and setup, and is ready to receive pixels.

### `DXGK_DIAG_MONITOR_NOT_READY`

The monitor is not initialized or setup correctly, and is not ready to receive pixels.

### `DXGK_DIAG_MONITOR_READY_NOTAPPLICABLE`

The driver doesn't know the current state of the monitor. This value should be used only for monitors for which the driver has no insight into monitor state.

## Remarks

The **DXGK_DIAG_MONITOR_STATE** enumeration is a member of the [**DXGK_DISPLAYSTATE_INTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_displaystate_intrusive) structure. It is used while gathering display diagnostic information via calls to [**DxgkDdiGetDisplayStateIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystateintrusive).

In many situations, the driver needs to initialize the monitor and set it up (typically by sending a command sequence) before it can start sending pixels to the monitor. Additionally, there might be some driver-initiated negotiation/handshaking done with the monitor before pixels can be sent. **DXGK_DIAG_MONITOR_STATE** specifies the final state of the monitors according to the miniport driver, indicating to the OS whether the monitors are ready to receive the pixels.

> [!NOTE]
> In some cases (like DisplayPort), **DXGK_DIAG_MONITOR_STATE** might overlap with [**DXGK_DIAG_DISPLAY_LINK_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-dxgk_diag_display_link_state). The purpose of this enumeration is to get the overall current status of the monitor irrespective of the bus/link state.

## See also

[**DXGK_DIAG_DISPLAY_LINK_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-dxgk_diag_display_link_state)

[**DXGK_DISPLAYSTATE_INTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_displaystate_intrusive)

[**DXGKARG_GETDISPLAYSTATEINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkarg_getdisplaystateintrusive)

[**DxgkDdiGetDisplayStateIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystateintrusive)