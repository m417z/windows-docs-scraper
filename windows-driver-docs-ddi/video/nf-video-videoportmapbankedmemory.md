# VideoPortMapBankedMemory function

## Description

The **VideoPortMapBankedMemory** function is **obsolete**, and is supported only for Windows NT 4.0 and previous drivers. Windows 2000 and later drivers must use [VideoPortMapMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportmapmemory).

**VideoPortMapBankedMemory** remaps a bus-relative physical range of video memory into the corresponding display driver's virtual address space in response to a VRP with the **IoControlCode** member set to [IOCTL_VIDEO_SHARE_VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_share_video_memory) or [IOCTL_VIDEO_MAP_VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_map_video_memory).

## Parameters

### `HwDeviceExtension`

Pointer to the miniport driver's device extension.

### `PhysicalAddress`

Specifies the bus-relative base address of the range to be mapped.

### `Length`

Pointer to a variable specifying the total number of bytes of device memory to be mapped (regardless of bank size). **VideoPortMapBankedMemory** returns the actual size of the memory mapped, which can be rounded to a system-determined alignment boundary, in this parameter. However, the miniport and display drivers cannot access memory outside the range delimited by the input value at *Length*.

### `InIoSpace`

Indicates the location of the range. This parameter can be one of the following values:

|Value|Meaning|
|--- |--- |
|VIDEO_MEMORY_SPACE_DENSE|Obsolete|
|VIDEO_MEMORY_SPACE_IO|The range is in system I/O space rather than in memory space.|
|VIDEO_MEMORY_SPACE_MEMORY|The range is in memory space rather than in system I/O space.|
|VIDEO_MEMORY_SPACE_P6CACHE|The processor aggregates a sequence of write operations and sends them to a given cache line. The processor then flushes the cache. This flag is meaningful only when VIDEO_MEMORY_SPACE_IO is not set.|
|VIDEO_MEMORY_SPACE_USER_MODE|Indicates that the address range specified should be mapped into user mode rather than kernel mode. This flag is meaningful only when VIDEO_MEMORY_SPACE_IO is not set.|

### `VirtualAddress`

Is a handle to the process into which the memory must be mapped, or **NULL**. **NULL** specifies that the port driver should map the logical memory range at any location in the address space of the current process. Otherwise, this handle can be a value passed in a [VRP](https://learn.microsoft.com/windows-hardware/drivers/) by the miniport driver's corresponding display driver. On return from a successful call, **VideoPortMapBankedMemory** resets the variable to the base virtual address to which it has mapped the given *PhysicalAddress*.

### `BankLength`

Specifies the size of a bank, in bytes.

### `ReadWriteBank`

If set to **TRUE** the bank is Read\Write; if set to **FALSE** there are two independent read and write banks.

### `BankRoutine`

Pointer to a driver-supplied [HwVidBankedMemoryCallback](https://learn.microsoft.com/windows-hardware/drivers/display/) function to be called by the Memory Manager when a new bank is accessed by the display driver.

### `Context`

Pointer to a miniport driver-supplied context that is passed back to the driver when the *BankRoutine* is called.

## Return value

**VideoPortMapBankedMemory** returns NO_ERROR if the given logical range was successfully mapped to a user-space virtual range. Otherwise, it can return ERROR_INVALID_PARAMETER.

## Remarks

**VideoPortMapBankedMemory** runs in kernel mode within the same context as the user-mode thread that initiated the call.

**VideoPortMapBankedMemory** is called by miniport drivers to efficiently manage x86 type devices that are limited to mapping a frame buffer in banks. When this routine returns to the caller, the frame buffer managed by the miniport driver is mapped as a linear frame buffer into the address space of the requesting process (see *VirtualAddress* parameter). When an access is made to an address in that mapped space, the Memory Manager calls the miniport driver to update the Bank Index Register to point to a new bank that contains the currently referenced address. The Bank Index Register is maintained by the miniport driver in *BankRoutine*. The correct Bank Index is calculated by the Memory Manager transparently to a display driver and passed to the miniport driver in the callback to *BankRoutine*.

## See also

[HwVidBankedMemoryCallback](https://learn.microsoft.com/windows-hardware/drivers/display/)

[IOCTL_VIDEO_MAP_VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_map_video_memory)

[IOCTL_VIDEO_SHARE_VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_share_video_memory)

[IOCTL_VIDEO_UNSHARE_VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_unshare_video_memory)

[VIDEO_REQUEST_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_request_packet)

[VideoPortMapMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportmapmemory)

[VideoPortUnmapMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportunmapmemory)