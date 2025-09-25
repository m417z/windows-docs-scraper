## Description

The **DXGKARG_CREATEDOORBELL_FLAGS** structure specifies doorbell creation flags.

## Members

### `ResizeRingBufferOperation`

Indication from UMD to KMD that a doorbell is being recreated for this hardware queue with a new, resized [**hRingBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_createdoorbell) ring buffer.

### `Reserved`

Reserved; set to zero.

### `Value`

An alternative way to access the structure members.

## Remarks

For more information, see [User-mode work submission](https://learn.microsoft.com/windows-hardware/drivers/display/user-mode-work-submission).

## See also

[**DXGKARG_CREATEDOORBELL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_createdoorbell)

[**DxgkDdiCreateDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdoorbell)