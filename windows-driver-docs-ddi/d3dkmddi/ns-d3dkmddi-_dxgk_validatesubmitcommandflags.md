# DXGK_VALIDATESUBMITCOMMANDFLAGS structure

## Description

The **DXGK_VALIDATESUBMITCOMMANDFLAGS** structure contains flags needed to validate a command buffer.

### `Value`

This value is used to operate over the structure members collectively.

## Members

### `HardwareQueueSubmission`

**HardwareQueueSubmission** can be one of the following values.

| Value | Meaning |
| ----- | ------- |
| TRUE | [**DxgkDdiSubmitCommandToHwQueue**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_submitcommandtohwqueue) called [**DXGKDDI_VALIDATESUBMITCOMMAND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_validatesubmitcommand). |
| FALSE | [**D3DKMTSubmitCommand**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_submitcommand) called **DXGKDDI_VALIDATESUBMITCOMMAND**. |

### `Reserved`

Reserved.

## Remarks

The kernel-mode driver should interpret these flags as needed to validate the command buffer.

## See also

[**DXGKARG_VALIDATESUBMITCOMMAND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_validatesubmitcommand)

[**DXGKDDI_VALIDATESUBMITCOMMAND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_validatesubmitcommand)