# PAGP_COMMIT_PHYSICAL callback function

## Description

The **AgpCommitPhysical** function maps system (physical) memory to the specified range of AGP-decodable physical addresses.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the device extension of the miniport driver.

### `PhysicalReserveContext` [in]

Identifies a reserved physical address range. The context handle is obtained from [AgpReservePhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_reserve_physical).

### `Pages` [in]

Specifies the number of pages of system memory to commit.

### `Offset` [in]

Specifies the page offset at which to commit the pages. The offset is applied to the reserved physical address range associated with **PhysicalReserveContext**.

## Return value

**AgpCommitPhysical** returns **TRUE** if the mapping was successful, and **FALSE** otherwise.

## Remarks

A video miniport driver must first reserve physical addresses by calling [AgpReservePhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_reserve_physical) before it calls this function.

Do not call **AgpCommitPhysical** to commit addresses that have already been committed. If the range of pages that is specified by **PhysicalReserveContext**, **Pages**, and **Offset** includes any pages that were previously committed, **AgpCommitPhysical** might fail.

Video miniport drivers that run on Microsoft Windows 2000 should always reserve and commit a physical range whose size is a multiple of 64 kilobytes. Reserving or committing a physical range that is not a multiple of 64 kilobytes can result in [AgpReserveVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_reserve_virtual) or [AgpCommitVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_commit_virtual) returning an invalid virtual address.

On Windows XP and later, **AgpCommitPhysical** automatically expands the committed range so that it is a multiple of 64 kilobytes.

When a video miniport driver calls **AgpCommitPhysical**, a portion of the physical address range identified by **PhysicalReserveContext** is mapped to locked pages of physical memory. The mapped portion begins **Offset** pages into the range identified by **PhysicalReserveContext**. The video miniport driver can access committed physical memory as if it were contiguous.

## See also

[AgpCommitVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_commit_virtual)

[AgpReservePhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_reserve_physical)

[AgpReserveVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_reserve_virtual)