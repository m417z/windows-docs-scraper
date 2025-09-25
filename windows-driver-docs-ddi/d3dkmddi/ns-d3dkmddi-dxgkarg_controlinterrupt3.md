## Description

The DXGKARG_CONTROLINTERRUPT3 structure is used in [**DxgkDdi_ControlInterrupt3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_controlinterrupt3) calls to describe the state of interrupts.

## Members

### `InterruptType`

A [**DXGK_INTERRUPT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_interrupt_type) enumeration indicating the type of interrupt.

### `InterruptState`

A [**DXGK_INTERRUPT_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_interrupt_state) enumeration that indicates whether interrupts are enabled for the driver.

### `CrtcVsyncState`

A [**DXGK_CRTC_VSYNC_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_crtc_vsync_state) enumeration that indicates whether VSYNCs are enabled if interrupts are also enabled for the driver.

### `VidPnSourceId`

The unique ID of the VidPnSource on which to control the VSync. This member only applies to VSync interrupts. **VidPnSourceId** can be one of the following values:

| Value | Meaning |
| ----- | ------- |
| 0 to (number of actual VidPnSources-1) | Identifies a particular VidPnSource |
| D3DDDI_ID_ALL | VSync is to be controlled on every VidPnSource of the adapter. The OS will set this value in certain scenarios where it cannot determine the particular VidPnSource to control, or in scenarios such as adapter termination where VSync needs to be disabled globally across all VidPnSources. |

## Remarks

**InterruptState** and **CrtcVsyncState** are members of a union.

## See also

[**DXGK_INTERRUPT_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_interrupt_state)

[**DXGK_INTERRUPT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_interrupt_type)

[**DxgkDdi_ControlInterrupt3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_controlinterrupt3)