# SURFACEALIGNMENT structure

## Description

The SURFACEALIGNMENT structure is used by a display driver to describe the alignment restrictions for a surface being allocated by [HeapVidMemAllocAligned](https://learn.microsoft.com/windows/desktop/api/dmemmgr/nf-dmemmgr-heapvidmemallocaligned).

## Members

### `Linear`

Is a structure that describes the alignment restrictions for linear heap allocations.

### `Linear.dwStartAlignment`

Is the start alignment multiple in bytes that DirectDraw should respect when performing linear heap allocations. The driver should set this member to zero if no particular alignment is required.

### `Linear.dwPitchAlignment`

Is the end alignment multiple in bytes that DirectDraw should respect when performing linear heap allocations. The driver should set this member to zero if no particular alignment is required.

### `Linear.dwFlags`

Is reserved for system use and should be ignored by the display driver.

### `Linear.dwReserved2`

Is reserved for system use and should be ignored by the display driver.

### `Rectangular`

Is a structure that describes the alignment restrictions for rectangular heap allocations.

### `Rectangular.dwXAlignment`

Is the X alignment multiple in bytes that DirectDraw should respect when performing rectangular heap allocations. The driver cannot specify an X alignment that is more fine-grained than one doubleword; DirectDraw will round any X alignment up to the nearest multiple of 4 bytes. The driver should set this member to zero if no particular alignment is required.

### `Rectangular.dwYAlignment`

Is the Y alignment multiple in bytes that DirectDraw should respect when performing rectangular heap allocations. The driver should set this member to zero if no particular alignment is required.

### `Rectangular.dwFlags`

Is reserved for system use and should be ignored by the display driver.

### `Rectangular.dwReserved2`

Is reserved for system use and should be ignored by the display driver.

## See also

[HeapVidMemAllocAligned](https://learn.microsoft.com/windows/desktop/api/dmemmgr/nf-dmemmgr-heapvidmemallocaligned)