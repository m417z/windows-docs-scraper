## Description

The **DXGKARG_SETINTERRUPTTARGETPRESENTID** structure contains parameters for the driver's [**DXGKDDI_SETINTERRUPTTARGETPRESENTID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setinterrupttargetpresentid) callback function.

## Members

### `VidPnSourceId`

[in] A **D3DDDI_VIDEO_PRESENT_SOURCE_ID** value that identifies the VidPn source ID of the hardware flip queue.

### `LayerIndex`

[in] A zero-based index value that identifies the MPO plane index of the flip queue.

### `InterruptTargetPresentId`

[in] Value that identifies the PresentId that is required to raise a corresponding VSync or HSync interrupt when it's completed. **InterruptTargetPresentId** can be one of the following values:

| Value | Meaning |
| ----- | ------- |
| UINT64_MAX | No VSync interrupt is required going forward until the target present ID is changed again. |
| 0 | VSync interrupts are required for every interval regardless of whether any new flips are completed. |
| Any other value | Interrupts are raised if the currently scanned PresentId >= **InterruptTargetPresentId**. |

## Remarks

See [Specifying Vsync interrupt behavior](https://learn.microsoft.com/windows-hardware/drivers/display/hardware-flip-queue#specifying-vsync-interrupt-behavior) for more information.

## See also

[**DXGKDDI_SETINTERRUPTTARGETPRESENTID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setinterrupttargetpresentid)