# DXGKDDI_CONTROLINTERRUPT callback function

## Description

The *DxgkDdiControlInterrupt* function enables or disables the given interrupt type on the graphics hardware.

## Parameters

### `hAdapter` [in]

A handle to the adapter object for the graphics processing unit (GPU). The driver returned this handle in the *MiniportDeviceContext* parameter from a call to its [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `InterruptType` [in]

A [DXGK_INTERRUPT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_interrupt_type)-type value that supplies the interrupt type.

### `EnableInterrupt` [in]

A Boolean value that indicates whether *DxgkDdiControlInterrupt* enables or disables the specified interrupt type. **TRUE** indicates that it enables and **FALSE** indicates that it disables.

## Return value

*DxgkDdiControlInterrupt* returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The interrupt type was successfully enabled or disabled on the graphics hardware.|
|STATUS_NOT_IMPLEMENTED|*DxgkDdiControlInterrupt* does not support enabling or disabling the specified interrupt type.|

## Remarks

The display miniport driver's *DxgkDdiControlInterrupt* function can enable or disable the specified interrupt type. However, *DxgkDdiControlInterrupt* is not required to disable the interrupt type if the driver requires the interrupt type for an internal purpose. A call to *DxgkDdiControlInterrupt* to enable the specified interrupt type indicates that the operating system requires that the driver call the [DxgkCbNotifyInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_interrupt) function to report when the interrupt type is triggered on the graphics hardware.

Currently, the Microsoft DirectX graphics kernel subsystem specifies only the DXGK_INTERRUPT_CRTC_VSYNC interrupt type in the *InterruptType* parameter. A call to *DxgkDdiControlInterrupt* to enable the DXGK_INTERRUPT_CRTC_VSYNC interrupt type indicates for the driver to control vertical retrace interrupt. During every vertical retrace period and immediately after the primary surface address specified in the DAC register is latched and scanned out, the interrupt should be triggered and reported.

The driver must return STATUS_NOT_IMPLEMENTED if an interrupt type other than DXGK_INTERRUPT_CRTC_VSYNC is supplied.

*DxgkDdiControlInterrupt* should be made pageable.

## See also

[DXGK_INTERRUPT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_interrupt_type)

[DxgkCbNotifyInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_interrupt)

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)