# VideoPortGetDeviceBase function

## Description

The **VideoPortGetDeviceBase** function maps a range of bus-relative device memory or I/O addresses into system space.

## Parameters

### `HwDeviceExtension`

Pointer to the miniport driver's device extension.

### `IoAddress`

The base physical address of the range to map. You get this bus-relative value by calling [VideoPortGetDeviceData](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicedata), [VideoPortGetRegistryParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetregistryparameters), or [VideoPortGetAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetaccessranges). Otherwise, this value is a driver-supplied, default base address for the device memory or I/O ports.

You must have successfully claimed the range described by *IoAddress* and *NumberOfUchars* in the registry through a preceding call to [VideoPortVerifyAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportverifyaccessranges) or **VideoPortGetAccessRanges**.

### `NumberOfUchars`

The number of bytes, starting at *IoAddress*, to map.

### `InIoSpace`

The location of the *IoAddress* range. This parameter can be one of the following flags or an ORed, compatible combination of these flags.

| **Flag** | **Meaning** |
|:--|:--|
| VIDEO_MEMORY_SPACE_DENSE | Obsolete. |
| VIDEO_MEMORY_SPACE_IO | The address range is in I/O space, not in memory space. |
| VIDEO_MEMORY_SPACE_MEMORY | The address range is in memory space, not in I/O space. |
| VIDEO_MEMORY_SPACE_P6CACHE | The processor aggregates a sequence of write operations, sends them to a cache line, and later flushes the cache. This flag is meaningful only when VIDEO_MEMORY_SPACE_IO is not set. Designates the video memory as write-combined (WC). For information about WC caching, see the [Write-Combining Memory in Video Miniport Drivers](https://learn.microsoft.com/previous-versions/windows/hardware/design/dn642116(v=vs.85)) website article. |

## Return value

If successful, **VideoPortGetDeviceBase** returns the base virtual address of the mapping. If the specified bus-relative range cannot be mapped, **VideoPortGetDeviceBase** returns **NULL**.

## Remarks

You can pass the mapped virtual addresses to the **VideoPortRead***Xxx*, **VideoPortWrite***Xxx*, and **VideoPort***Xxx***Memory** functions, except for [VideoPortMapMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportmapmemory) and [VideoPortUnmapMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportunmapmemory).

You must call **VideoPortGetDeviceBase** from the miniport driver's [HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter), [HwVidQueryDeviceCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_query_device_routine), or [HwVidQueryNamedValueCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_get_registry_routine) function.

Before *HwVidFindAdapter* returns control, you should store both the mapped base address returned by **VideoPortGetDeviceBase** and the length of the mapped access range in the adapter's device extension (pointed to by *HwDeviceExtension*) for later use.

Access to the mapped address space must follow these rules:

* If *InIoSpace* is VIDEO_MEMORY_SPACE_IO, which indicates that the address is in I/O space, the virtual address that this function returns should be passed to the **VideoPortReadPort***Xxx*, **VideoPortWritePort***Xxx*, **VideoPortReadPortBuffer***Xxx*, and **VideoPortWritePortBuffer***Xxx* functions, where *Xxx* is **Uchar**, **Ushort**, or **Ulong**.
* If *InIoSpace* is VIDEO_MEMORY_SPACE_MEMORY, which indicates that the address is not in I/O space but in memory space, the virtual address that this function returns should be passed to the **VideoPortReadRegister***Xxx*, **VideoPortWriteRegister***Xxx*, **VideoPortReadRegisterBuffer***Xxx*, and **VideoPortWriteRegisterBuffer***Xxx* functions, where *Xxx* is **Uchar**, **Ushort**, or **Ulong**.
* The driver must not access addresses that are outside the range delimited by *NumberOfUchars*.

**VideoPortGetDeviceBase** and [VideoPortMapMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportmapmemory) can both be called by the video miniport driver to map video memory into a virtual address space. If you call both of these functions to map the same physical addresses, or if you call one of the functions more than once to map the same physical addresses, you might have more than one virtual-address range that maps to the same physical-address range. In that case, you must set the VIDEO_MEMORY_SPACE_P6CACHE flag of the *InIoSpace* parameter to the same value in all of those calls.

Every universal memory architecture (UMA) display device uses a frame buffer that is located in main memory rather than on a PCI bus. In this case, do not call **VideoPortMapMemory** to map the frame buffer. To map a UMA frame buffer into system space, call [MmMapIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmapiospace).

If a miniport driver does not support an adapter that it has mapped a logical range for, it must perform two steps before it returns control to the [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) function: call [VideoPortFreeDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportfreedevicebase) to unmap the previously mapped range from system space, and call [VideoPortGetAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetaccessranges) or [VideoPortVerifyAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportverifyaccessranges) to release its claims on the range in the registry.

## See also

[HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter)

[HwVidQueryDeviceCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_query_device_routine)

[HwVidQueryNamedValueCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_get_registry_routine)

[VideoPortCompareMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportcomparememory)

[VideoPortFreeDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportfreedevicebase)

[VideoPortGetAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetaccessranges)

[VideoPortGetDeviceData](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicedata)

[VideoPortGetRegistryParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetregistryparameters)

[VideoPortMoveMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportmovememory)

[VideoPortVerifyAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportverifyaccessranges)

[VideoPortZeroDeviceMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportzerodevicememory)

[VideoPortZeroMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportzeromemory)