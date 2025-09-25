# VideoPortMoveMemory function

## Description

The **VideoPortMoveMemory** function copies data from the source location to the destination location in system memory.

## Parameters

### `Destination` [in, out]

Pointer to the destination location.

### `Source` [in, out]

Pointer to the location of the data to copy.

### `Length`

Specifies the number of bytes to copy.

## Return value

None

## Remarks

**VideoPortMoveMemory** moves memory either forward or backward, aligned or unaligned, in 4-byte blocks, followed by any remaining bytes.

The given *Destination* and *Source* must be in a mapped logical range returned by **VideoPortGetDeviceBase** and/or a [system space](https://learn.microsoft.com/windows-hardware/drivers/) RAM address, such as an address on the stack.

Callers of **VideoPortMoveMemory** can be running at any IRQL if both memory blocks are resident. Otherwise, the caller must be running at IRQL < DISPATCH_LEVEL.

## See also

[VideoPortCompareMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportcomparememory)

[VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase)

[VideoPortZeroDeviceMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportzerodevicememory)

[VideoPortZeroMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportzeromemory)