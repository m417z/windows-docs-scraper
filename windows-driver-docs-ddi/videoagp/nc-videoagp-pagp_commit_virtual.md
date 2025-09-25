# PAGP_COMMIT_VIRTUAL callback function

## Description

The **AgpCommitVirtual** function maps reserved virtual memory to an associated range of AGP-decodable physical addresses.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the device extension of the miniport driver'.

### `VirtualReserveContext` [in]

Identifies a reserved virtual address range. The context handle was obtained from [AgpReserveVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_reserve_virtual).

### `Pages` [in]

Specifies the number of pages of virtual memory to map.

### `Offset` [in]

Specifies the page offset at which to commit the pages. The offset is applied to the reserved virtual address range that is identified by **VirtualReserveContext**.

## Return value

**AgpCommitVirtual** returns the virtual address for the base of the committed pages if the mapping succeeded; otherwise returns **NULL**.

## Remarks

Before calling **AgpCommitVirtual** to commit a range of virtual pages, you must do the following:

* Call [AgpReservePhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_reserve_physical) to reserve a range of physical addresses for the GPU to use.
* Call [AgpCommitPhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_commit_physical) to map a portion (or all) of the reserved physical addresses to locked pages in system memory.
* Call [AgpReserveVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_reserve_virtual) to reserve a range of virtual addresses that is associated with the range of physical addresses reserved by [AgpReservePhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_reserve_physical).

After these items are completed, you can call **AgpCommitVirtual** to map a portion of the reserved virtual pages to pages that have already been mapped and locked by [AgpCommitPhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_commit_physical). You must not attempt to map a page of virtual addresses if the corresponding page of physical addresses has not already been mapped.

Video miniport drivers that run on Microsoft Windows 2000 should always commit a virtual range whose size is a multiple of 64 kilobytes. If you call **AgpCommitVirtual** to commit a virtual range that is not a multiple of 64 kilobytes, it can return an invalid virtual address.

On Windows XP and later, **AgpCommitVirtual** automatically expands the committed range so that it is a multiple of 64 kilobytes.

When a miniport driver calls **AgpCommitVirtual**, a portion of the virtual address range identified by **VirtualReserveContext** is mapped to physical addresses. The mapped portion begins *Offset* pages into the virtual address range that is identified by **VirtualReserveContext**.

## See also

[AgpFreeVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_free_virtual)

[AgpReservePhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_reserve_physical)

[AgpReserveVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_reserve_virtual)