## Description

The **AgpReservePhysical** function reserves a range of physical addresses on the system bus to which the AGP controller can respond.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `Pages` [in]

Specifies the number of pages that the video port driver should reserve.

### `Caching` [in]

A [**VIDEO_PORT_CACHE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/ne-videoagp-video_port_cache_type) enumeration that specifies the type of caching that the system should use.

### `PhysicalReserveContext` [out]

Specifies the location in which the video port driver writes a context handle that identifies the reserved physical address space.

## Return value

**AgpReservePhysical** returns the base address of the reserved physical address range if successful; otherwise, it returns NULL.

## Remarks

Video miniport drivers that run on Windows 2000 should always reserve a range whose size is a multiple of 64 kilobytes. Reserving a range that is not a multiple of 64 kilobytes can result in [**AgpReserveVirtual**](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_reserve_virtual) or [**AgpCommitVirtual**](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_commit_virtual) returning an invalid virtual address.

On Windows XP and later, **AgpReservePhysical** automatically expands the requested range to a multiple of 64 kilobytes.

Upon successful return, the AGP controller can respond to the reserved physical address range on the bus. However, the video miniport driver must first call [**AgpCommitPhysical**](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_commit_physical) to cause this memory to be committed before accessing it in order for the accessed results to be defined.

The miniport driver can call **AgpReservePhysical** several times to reserve many smaller address ranges rather than one big range.

The miniport driver should call [**AgpReleasePhysical**](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_release_physical) to release the physical address range when it is no longer needed.

## See also

[**AgpCommitPhysical**](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_commit_physical)

[**AgpReleasePhysical**](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_release_physical)

[**AgpReserveVirtual**](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_reserve_virtual)