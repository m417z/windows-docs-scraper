# D3DKMT_CHANGEVIDEOMMEMORYRESERVATION structure

## Description

The **D3DKMT_CHANGEVIDEOMMEMORYRESERVATION** structure is used to change the video memory management reservation.

## Members

### `hProcess`

[in, opt] A handle to a process. If NULL, the current process is used. The process handle must be opened with PROCESS_SET_INFORMATION privileges.

### `hAdapter`

[in] A handle to the graphics adapter.

### `MemorySegmentGroup`

[in] The memory segment group to change reservation for.

### `Reservation`

[in] Desired reservation in the range between 0 and AvailableForReservation returned by [QueryVideoMemoryInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryvideomemoryinfo).

### `PhysicalAdapterIndex`

[in] Zero based physical adapter index in the LDA (linked display adapter) configuration.

## See also

[**D3DKMTChangeVideoMemoryReservation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtchangevideomemoryreservation)