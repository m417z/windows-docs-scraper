## Description

The **DdMapMemory** callback function maps application-modifiable portions of the frame buffer into the user-mode address space of the specified process, or unmaps memory.

## Parameters

### `unnamedParam1`

Points to a [DD_MAPMEMORYDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_mapmemorydata) structure that contains details for the memory mapping or unmapping operation.

## Return value

**DdMapMemory** returns one of the following callback codes:

## Remarks

**DdMapMemory** is called to perform memory mapping before the first call to [DdLock](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_lock). The handle returned by the driver in the **fpProcess** member of the [DD_MAPMEMORYDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_mapmemorydata) structure at *lpMapMemory* will be passed to every *DdLock* call made on the driver.

**DdMapMemory** is also called to unmap memory after the last [DdUnlock](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_unlock) call is made.

To prevent driver crashes, the driver must not map any portion of the frame buffer that must not be modified by an application.

The display driver must call upon the [video miniport driver](https://learn.microsoft.com/windows-hardware/drivers/display/video-miniport-drivers-in-the-windows-2000-display-driver-model) to perform the memory mapping or unmapping. To send a synchronous request to the video miniport driver to map the memory, the display driver calls the [EngDeviceIoControl](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engdeviceiocontrol) GDI function with [IOCTL_VIDEO_SHARE_VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddvdeo/ni-ntddvdeo-ioctl_video_share_video_memory) or [IOCTL_VIDEO_MAP_VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddvdeo/ni-ntddvdeo-ioctl_video_map_video_memory). The display driver sends [IOCTL_VIDEO_UNSHARE_VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddvdeo/ni-ntddvdeo-ioctl_video_unshare_video_memory) or [IOCTL_VIDEO_UNMAP_VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddvdeo/ni-ntddvdeo-ioctl_video_unmap_video_memory) to the video miniport driver to unmap the memory. For more information, see [Communicating IOCTLs to the Video Miniport Driver](https://learn.microsoft.com/windows-hardware/drivers/display/communicating-ioctls-to-the-video-miniport-driver).

**DdMapMemory** can only be called with a disabled [PDEV](https://learn.microsoft.com/windows-hardware/drivers/) to unmap memory. A PDEV is disabled or enabled by calling the display driver's [DrvAssertMode](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvassertmode) function. See [Managing PDEVs](https://learn.microsoft.com/windows-hardware/drivers/display/managing-pdevs) for more information.

## See also

[DD_MAPMEMORYDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_mapmemorydata)

[DdLock](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_lock)

[DdUnlock](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_unlock)

[EngDeviceIoControl](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engdeviceiocontrol)

[IOCTL_VIDEO_MAP_VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddvdeo/ni-ntddvdeo-ioctl_video_map_video_memory)

[IOCTL_VIDEO_SHARE_VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddvdeo/ni-ntddvdeo-ioctl_video_share_video_memory)

[IOCTL_VIDEO_UNMAP_VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddvdeo/ni-ntddvdeo-ioctl_video_unmap_video_memory)

[IOCTL_VIDEO_UNSHARE_VIDEO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddvdeo/ni-ntddvdeo-ioctl_video_unshare_video_memory)