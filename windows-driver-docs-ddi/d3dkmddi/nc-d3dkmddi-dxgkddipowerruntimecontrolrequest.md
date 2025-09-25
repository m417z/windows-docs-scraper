# DXGKDDIPOWERRUNTIMECONTROLREQUEST callback function

## Description

Called by the Power Engine Plug-in (PEP) to exchange information with the display miniport driver. Also called by the Microsoft DirectX graphics kernel subsystem to notify the display miniport driver about certain events.

## Parameters

### `DriverContext`

A handle to a context block associated with a display adapter. The display miniport driver's [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to the DirectX graphics kernel subsystem.

### `PowerControlCode`

A pointer to a GUID that defines the meaning of the PEP's control request. For more information, see Remarks.

### `InBuffer`

An optional pointer to an input buffer.

### `InBufferSize`

The size, in bytes, of the buffer that *InBuffer* points to.

### `OutBuffer`

An optional pointer to an output buffer.

### `OutBufferSize`

The size, in bytes, of the buffer that *OutBuffer* points to.

### `BytesReturned`

An optional pointer to a buffer that contains the number of bytes that are written by the display miniport driver to the output buffer.

## Return value

Returns STATUS_SUCCESS if it succeeds. Otherwise, it returns one of the error codes defined in Ntstatus.h.

## Remarks

The operating system calls *DxgkDdiPowerRuntimeControlRequest* only if the display miniport driver indicates support by setting [DXGK_DRIVERCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps).**SupportRuntimePowerManagement** to **TRUE**.

### GUIDs used by the Power Engine Plugin (PEP)

The PEP uses the following GUIDs that are defined in D3dkmddi.h to exchange information with the display miniport driver. The display port driver uses these GUIDs to issue Event Tracing for Windows (ETW) events, which are useful to profile driver performance issues.

GUID_DXGKDDI_POWER_VOLTAGE_UP

Increase the voltage.

GUID_DXGKDDI_POWER_VOLTAGE_DOWN

Decrease the voltage.

GUID_DXGKDDI_POWER_VOLTAGE

Change the voltage, but the driver doesn't know if the change is an increase or decrease.

GUID_DXGKDDI_POWER_CLOCK_UP

Increase the clock setting.

GUID_DXGKDDI_POWER_CLOCK_DOWN

Decrease the clock setting.

GUID_DXGKDDI_POWER_CLOCK

Change the clock setting, but the driver doesn't know if the change is an increase or decrease.

GUID_DXGKDDI_POWER_BANDWIDTH_UP

Increase the bandwidth.

GUID_DXGKDDI_POWER_BANDWIDTH_DOWN

Decrease the bandwidth.

GUID_DXGKDDI_POWER_BANDWIDTH

Change the bandwidth, but the driver doesn't know if the change is an increase or decrease.

### GUIDs used by the DirectX graphics kernel subsystem

The DirectX graphics kernel subsystem uses the following GUIDs that are defined in D3dkmddi.h to notify the display miniport driver about certain events.

GUID_DXGKDDI_POWER_MANAGEMENT_PREPARE_TO_START

Used after the DirectX graphics kernel subsystem registers the device for runtime power management, but before the device is started. After this function has been called with this GUID, the display miniport driver can call these functions:

* [DxgkCbSetPowerComponentActive](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_setpowercomponentactive)
* [DxgkCbSetPowerComponentLatency](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_setpowercomponentlatency)
* [DxgkCbSetPowerComponentResidency](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_setpowercomponentresidency)

GUID_DXGKDDI_POWER_MANAGEMENT_STARTED

Used after the DirectX graphics kernel subsystem starts runtime power management. After this function has been called with this GUID, the display miniport driver can call any power runtime functions.

GUID_DXGKDDI_POWER_MANAGEMENT_STOPPED

Used immediately before the DirectX graphics kernel subsystem unregisters the device for runtime power management. After this function has been called with this GUID, the display miniport driver should not call any power runtime functions.

### Synchronization

This function can be called simultaneously from multiple execution threads.

The operating system guarantees that this function follows the zero level synchronization mode as defined in [Threading and Synchronization Zero Level](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-zero-level).

## See also

[DXGKARG_QUERYADAPTERINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo)

[DXGK_DRIVERCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps)

[DxgkCbSetPowerComponentActive](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_setpowercomponentactive)

[DxgkCbSetPowerComponentLatency](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_setpowercomponentlatency)

[DxgkCbSetPowerComponentResidency](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_setpowercomponentresidency)

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)