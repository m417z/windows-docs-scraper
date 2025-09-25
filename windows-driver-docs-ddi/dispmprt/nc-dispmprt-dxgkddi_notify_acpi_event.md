# DXGKDDI_NOTIFY_ACPI_EVENT callback function

## Description

Notifies the display miniport driver about certain ACPI events.

## Parameters

### `MiniportDeviceContext` [in]

A handle to a context block that represents a display adapter. The display miniport driver's [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to the DirectX graphics kernel subsystem.

### `EventType` [in]

A [DXGK_EVENT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-_dxgk_event_type) enumerator that supplies the event type (**DpAcpiEvent**, **DpPowerStateEvent**, **DpDockingEvent**).

### `Event` [in]

The event number. The following table lists the possible event numbers for each of the event types.

|Event type|Possible event numbers|
|--- |--- |
|DpAcpiEvent|The following are the allowed events as defined in Dispmprt.h:

* ACPI_NOTIFY_CYCLE_DISPLAY_HOTKEY - It notifies the operating system that the user has pressed the cycle display hotkey.
* ACPI_NOTIFY_DOCK_EVENT - Indicates that a docking event has occurred. For example, the user docked or undocked a mobile computer.
* ACPI_NOTIFY_DEVICE_HOTPLUG - Indicates that the status of any output device attached to the VGA controller has been changed. For example, the user removed or plugged a CRT display to the VGA port.
* ACPI_NOTIFY_PANEL_SWITCH - Indicates that the status of one of the output devices attached to the VGA controller has been toggled. For example, the user switched the active output display from LCD to CRT display type.
* ACPI_NOTIFY_VIDEO_WAKEUP - Indicates that the output display has been resumed. For example, the user has reactivated the computer display.

|
|DpPowerStateEvent|PO_CB_LID_SWITCH_STATE, PO_CB_AC_STATUS<br>Defined in Wdm.h.|
|DpDockingEvent|ACPI_NOTIFY_DOCK_EVENT - Indicates that a docking event has occurred. For example, the user docked or undocked a mobile computer.<br>Defined in Dispmprt.h.|

### `Argument` [in]

A pointer to an argument that depends on the event. For most events, this will be **NULL**. The following table shows the event arguments, which are ULONG values, for specified event numbers that are available.

|Event number|Possible event arguments|
|--- |--- |
|PO_CB_AC_STATUS|0 - Indicates that the system is on battery power.<br>1 - Indicates that the system is on AC power.|
|PO_CB_LID_SWITCH_STATE|0 - Indicates that the lid is being closed.<br>1 - Indicates that the lid is being opened.|

### `AcpiFlags` [out]

A pointer to a value that indicates the type of request that the display miniport driver should make to the operating system. The following table shows the values that can be specified.

| **Value** | **Request type** |
|:--|:--|
| DXGK_ACPI_CHANGE_DISPLAY_MODE | The display miniport driver makes a request to the operating system to call the [DxgkDdiRecommendFunctionalVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_recommendfunctionalvidpn) function and then to initiate a mode change to the new recommended active video present network (VidPN). For example, the display miniport driver might make this request if the user has specified a mode change. |
| DXGK_ACPI_CHANGE_DISPLAY_TOPOLOGY | |
| DXGK_ACPI_POLL_DISPLAY_CHILDREN | The display miniport driver makes a request to the operating system to poll the connectivity of the children of the display adapter represented by MiniportDeviceContext. |
| DXGK_ACPI_CHAIN_NOT_HANDLED | Indicates that an event with type DxgkChainedAcpiEvent was not handled by the hybrid discrete driver and should therefore be sent to the hybrid integrated driver. |

This parameter is ignored if this function returns an error or if the display adapter loses power.

## Return value

*DxgkDdiNotifyAcpiEvent* returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

*DxgkDdiNotifyAcpiEvent* is an optional display miniport driver function.

*DxgkDdiNotifyAcpiEvent* should be made pageable.

## See also

[DxgkCbEvalAcpiMethod](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_eval_acpi_method)