# DlAllocateCommonBuffer function

## Description

Allocates and maps a logically contiguous region of memory that is simultaneously accessible both from the processor and from a device.

## Parameters

### `DeviceHandle`

Handle to the device.

### `DlpDmaAdapter`

Display library direct memory access adapter.

### `DesiredLength`

Specifies the requested number of bytes of memory.

### `LogicalAddress`

Pointer to a memory location that receives the logical address to be used by the adapter to access the allocated buffer.

### `CacheEnabled`

Specifies whether the allocated memory can be cached.

### `Reserved`

Is currently ignored by the video port driver.

## Return value

This function returns PVOID.

## Remarks

## See also