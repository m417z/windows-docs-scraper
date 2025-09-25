# VideoPortUnmapMemory function

## Description

The **VideoPortUnmapMemory** function releases a mapping between a logical address range for the adapter and a virtual address range in the user-mode address space of a particular thread. This function is the complement of [VideoPortMapMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportmapmemory).

## Parameters

### `HwDeviceExtension`

Pointer to the miniport driver's device extension.

### `VirtualAddress`

Pointer to a virtual address within the mapped range to be released.

### `ProcessHandle`

Should be set to zero, or to the process handle specified when the miniport driver called **VideoPortMapMemory**.

## Return value

**VideoPortUnmapMemory** returns NO_ERROR if the mapping was released. Otherwise, it returns ERROR_INVALID_PARAMETER.

## Remarks

A miniport driver cannot release a subrange of the mapping between a logical device range and the user-space virtual address range of its corresponding display driver. Whether the *VirtualAddress* parameter is the base virtual address for the mapped range that was returned by **VideoPortMapMemory**, or is an offset into that mapped virtual range, **VideoPortUnmapMemory** releases the mapping for the full range.

## See also

[VideoPortMapMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportmapmemory)