# _VIDEO_MEMORY_INFORMATION structure

## Description

The VIDEO_MEMORY_INFORMATION structure contains information about a mapping of video memory into system space or the private virtual address space of a user-mode process. The mapping is created when an [IOCTL_VIDEO_MAP_VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_map_video_memory) request is sent to the video miniport driver.

## Members

### `VideoRamBase`

Virtual address of the video RAM in system space or in the address space of the user-mode process that initiated the request.

### `VideoRamLength`

The size, in bytes, of the virtual address range that is mapped to video RAM. Memory accessible through a bank switch mechanism is not described by this value.

This value must be equal to the product **VideoMemoryBitmapHeight** * **ScreenStride**, where each factor in the product is a member of the [VIDEO_MODE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_mode_information) structure.

### `FrameBufferBase`

Pointer to the virtual address of the [frame buffer](https://learn.microsoft.com/windows-hardware/drivers/) in the caller's address space. The frame buffer is the actively displayed part of video RAM.

### `FrameBufferLength`

Specifies the linear length of the frame buffer in the caller's virtual address space. Memory accessible through a bank switch mechanism is not described by this value.

This value must be equal to the product **VisScreenWidth** * **ScreenStride**, where each term in this product is a member of the [VIDEO_MODE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_mode_information) structure.

## Remarks

In the [IOCTL_VIDEO_MAP_VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_map_video_memory) request, [VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_memory) serves as an input structure, while VIDEO_MEMORY_INFORMATION serves as an output structure.

## See also

[IOCTL_VIDEO_MAP_VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_map_video_memory)

[IOCTL_VIDEO_UNMAP_VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_unmap_video_memory)

[VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_memory)

[VIDEO_MODE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_video_mode_information)