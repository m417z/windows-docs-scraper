## Description

The **DXGKARG_SETFLIPQUEUELOGBUFFER** structure contains parameters for the driver's [**DXGKDDI_SETFLIPQUEUELOGBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setflipqueuelogbuffer) callback function.

## Members

### `VidPnSourceId`

[in] A **D3DDDI_VIDEO_PRESENT_SOURCE_ID** value that identifies the VidPn source ID for which the flip queue log buffer is being provided.

### `LayerIndex`

[in] A zero-based index value that identifies the MPO plane index for which the flip queue log buffer is being provided.

### `NumberOfEntries`

[in] The number of entries in the flip queue log buffer that **LogBufferAddress** points to.

### `LogBufferAddress`

[in] Pointer to an array of [**DXGK_FLIPQUEUE_LOG_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_flipqueue_log_entry) structures in the flip queue log buffer. This value is the kernel-mode CPU virtual address of the flip queue log buffer in non-paged memory. **LogBufferAddress** is NULL if the OS is about to destroy the current flip queue log buffer.

## Remarks

See [Obtaining present statistics for queued flips](https://learn.microsoft.com/windows-hardware/drivers/display/hardware-flip-queue#obtaining-present-statistics-for-queued-flips) for more information.

## See also

[**DXGK_FLIPQUEUE_LOG_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_flipqueue_log_entry)

[**DXGKDDI_SETFLIPQUEUELOGBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setflipqueuelogbuffer)