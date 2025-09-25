# DXGKARG_CONTROLINTERRUPT2 structure

## Description

The **DXGKARG_CONTROLINTERRUPT2** structure is used in [**DxgkDdi_ControlInterrupt2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_controlinterrupt2) calls to describe the state of interrupts.

## Members

### `InterruptType`

A [**DXGK_INTERRUPT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_interrupt_type) enumeration that indicates the type of interrupt.

### `InterruptState`

A [**DXGK_INTERRUPT_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_interrupt_state) enumeration that indicates whether interrupts are enabled for the driver.

### `CrtcVsyncState`

A [**DXGK_CRTC_VSYNC_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_crtc_vsync_state) enumeration that indicates whether VSYNCs are enabled if interrupts are also enabled for the driver.

## Remarks

**InterruptState** and **CrtcVsyncState** are members of a union.

## See also

[**DXGK_INTERRUPT_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_interrupt_state)

[**DXGK_INTERRUPT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_interrupt_type)

[**DXGKARG_CONTROLINTERRUPT3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_controlinterrupt3)

[**DxgkDdi_ControlInterrupt2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_controlinterrupt2)

[**DxgkDdi_ControlInterrupt3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_controlinterrupt3)