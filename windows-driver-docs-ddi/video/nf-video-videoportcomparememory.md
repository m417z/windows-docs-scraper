# VideoPortCompareMemory function

## Description

The **VideoPortCompareMemory** function compares two blocks of system memory, byte-by-byte, and returns the number of compared bytes that are equivalent.

## Parameters

### `Source1`

Pointer to the first block of memory to compare.

### `Source2`

Pointer to the second block of memory to compare.

### `Length`

Specifies the number of bytes to be compared.

## Return value

**VideoPortCompareMemory** returns the number of bytes that are equivalent. If both blocks are equivalent, it returns the *Length* parameter.

## Remarks

The values in the *Source1* and *Source2* parameters must be in a mapped logical range returned by [VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase) and/or a [system space](https://learn.microsoft.com/windows-hardware/drivers/) RAM address, such as an address on the stack.

Callers of **VideoPortCompareMemory** can be running at any IRQL if both blocks of memory are resident.

## See also

[VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase)

[VideoPortMoveMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportmovememory)

[VideoPortScanRom](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportscanrom)

[VideoPortZeroDeviceMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportzerodevicememory)

[VideoPortZeroMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportzeromemory)