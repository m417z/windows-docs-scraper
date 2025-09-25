# _D3DKMT_DEVICEEXECUTION_STATE enumeration

## Description

The **D3DKMT_DEVICEEXECUTION_STATE** enumeration type contains values that indicate the execution status for a device.

## Constants

### `D3DKMT_DEVICEEXECUTION_ACTIVE`

The device is actively executing.

### `D3DKMT_DEVICEEXECUTION_RESET`

The device is reset.

### `D3DKMT_DEVICEEXECUTION_HUNG`

The device is hung. The device is unable to continue.

### `D3DKMT_DEVICEEXECUTION_STOPPED`

 The device is stopped.

### `D3DKMT_DEVICEEXECUTION_ERROR_OUTOFMEMORY`

Even after the video memory manager split the DMA buffer, the video memory manager could not page-in all of the required allocations into video memory at the same time. The device is unable to continue.

### `D3DKMT_DEVICEEXECUTION_ERROR_DMAFAULT`

The display miniport driver reported a fault while processing a DMA buffer for the device. The device is unable to continue.

### `D3DKMT_DEVICEEXECUTION_ERROR_DMAPAGEFAULT`

The display miniport driver reported a page fault while processing a DMA buffer for the device. The device is unable to continue.

## See also

[D3DKMT_GETDEVICESTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getdevicestate)