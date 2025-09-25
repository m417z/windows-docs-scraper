# DXGKCB_POWERRUNTIMECONTROLREQUEST callback function

## Description

A kernel-mode display miniport driver calls **DXGKCB_POWERRUNTIMECONTROLREQUEST** to exchange information with the Power Engine Plug-in (PEP).

## Parameters

### `hAdapter` [in]

A handle to the display adapter. The display miniport driver receives the handle from the **DeviceHandle** member of the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface) structure in a call to its [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) function.

### `PowerControlCode` [in]

A pointer to a GUID that defines the meaning of the display miniport driver's control request. For more information, see Remarks.

### `InBuffer` [in, optional]

An optional pointer to an input buffer.

### `InBufferSize` [in]

The size, in bytes, of the optional buffer that **InBuffer** points to. Set to zero if no **InBuffer** is provided.

### `OutBuffer` [in, optional]

An optional pointer to an output buffer.

### `OutBufferSize` [in]

The size, in bytes, of the optional buffer that **OutBuffer** points to. Set to zero if no **OutBuffer** is provided.

### `BytesReturned` [out]

The number of actual bytes returned in the buffer that **OutBuffer** points to. The returned value will be <= **OutBufferSize**.

## Return value

**DXGKCB_POWERRUNTIMECONTROLREQUEST** returns STATUS_SUCCESS if it succeeds. Otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

> [!NOTE]
>
> To avoid a possible deadlock, do not call the [**DXGKCB_SETPOWERCOMPONENTACTIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_setpowercomponentactive) function until this function has returned.

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, call **DxgkCbPowerRuntimeControlRequest** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

Although the driver can use any GUID in the **PowerControlCode** parameter, the following GUIDs that are defined in *D3dkmddi.h* are recommended. By using these GUIDs, the display port driver can issue Event Tracing for Windows (ETW) events, which are useful to profile driver performance issues.

| GUID | Meaning |
| ---- | ------- |
| GUID_DXGKDDI_POWER_VOLTAGE_UP | Increase the voltage. |
| GUID_DXGKDDI_POWER_VOLTAGE_DOWN | Decrease the voltage. |
| GUID_DXGKDDI_POWER_VOLTAGE | Change the voltage, but the driver doesn't know if the change is an increase or decrease. |
| GUID_DXGKDDI_POWER_CLOCK_UP | Increase the clock setting. |
| GUID_DXGKDDI_POWER_CLOCK_DOWN | Decrease the clock setting. |
| GUID_DXGKDDI_POWER_CLOCK | Change the clock setting, but the driver doesn't know if the change is an increase or decrease. |
| GUID_DXGKDDI_POWER_BANDWIDTH_UP | Increase the bandwidth. |
| GUID_DXGKDDI_POWER_BANDWIDTH_DOWN | Decrease the bandwidth. |
| GUID_DXGKDDI_POWER_BANDWIDTH | Change the bandwidth, but the driver doesn't know if the change is an increase or decrease. |

These GUIDs do not imply that there is any communication protocol between the display miniport driver and the PEP, nor do they imply that there are any restrictions on the values that can be passed between the display miniport driver and the PEP.

## See also

[**DXGKCB_SETPOWERCOMPONENTACTIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_setpowercomponentactive)

[**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)