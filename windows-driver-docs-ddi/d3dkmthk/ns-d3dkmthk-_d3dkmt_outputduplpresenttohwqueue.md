# _D3DKMT_OUTPUTDUPLPRESENTTOHWQUEUE structure

## Description

Used by the [D3DKMTOutputDuplPresentToHwQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtoutputduplpresenttohwqueue) function to output the duplicate handle of a hardware queue.

## Members

### `hSource`

A handle to the source allocation to present from.

### `VidPnSourceId`

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology that the monitor is connected to.

### `BroadcastHwQueueCount`

Specifies the number of hardware queues to broadcast this signal to.

### `hHwQueues`

A handle to an array of hardware queues.

### `PresentRegions`

Dirty and move regions, of type [D3DKMT_PRESENT_RGNS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_present_rgns).

### `Flags`

Flags from the D3DKMT_OUTPUTDUPLPRESENTFLAGS enumeration that specify output behavior.

### `hIndirectHwQueue`

A handle to the indirect hardware queue.

## Remarks

## See also