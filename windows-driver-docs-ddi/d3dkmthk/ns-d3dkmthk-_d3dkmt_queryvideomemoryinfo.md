# _D3DKMT_QUERYVIDEOMEMORYINFO structure

## Description

Used to query for video memory info.

## Members

### `hProcess` [in, opt]

A handle to the process.

### `hAdapter` [in]

A handle to the graphics adapter.

### `MemorySegmentGroup` [in]

The memory segment group to query.

### `Budget` [out]

The total memory the application may use.

### `CurrentUsage` [out]

The current memory usage of the device.

### `CurrentReservation` [out]

The current reservation of the device.

### `AvailableForReservation` [out]

The total that the device may reserve.

### `PhysicalAdapterIndex` [in]

The physical adapter index in the LDA (linked display adapter) chain.

## Remarks

## See also