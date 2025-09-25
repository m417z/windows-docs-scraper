# DXGK_INTERRUPT_STATE enumeration

## Description

The **DXGK_INTERRUPT_STATE** enumeration provides additional information for [**DxgkDdi_ControlInterrupt2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_controlinterrupt2) or [**DxgkDdi_ControlInterrupt3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_controlinterrupt3) when VSYNC is not being used.

This enumeration uses Enable as 0 and Disable as 1 in the bivalent state, which is the opposite of the Boolean value previously used in [**DxgkDdi_ControlInterrupt**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_controlinterrupt).

## Constants

### `DXGK_INTERRUPT_ENABLE:0`

The interrupt is enabled.

### `DXGK_INTERRUPT_DISABLE:1`

The interrupt is disabled.