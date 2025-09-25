# PAGP_FREE_PHYSICAL callback function

## Description

The **AgpFreePhysical** function frees system memory that was committed by a previous call to [AgpCommitPhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_commit_physical).

## Parameters

### `HwDeviceExtension` [in]

Pointer to the device extension of the miniport driver.

### `PhysicalReserveContext` [in]

Identifies a reserved physical address range. This context handle was obtained from [AgpReservePhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_reserve_physical).

### `Pages` [in]

Specifies the number of pages of system memory that the video port driver should unmap.

### `Offset` [in]

Specifies the page offset into the reserved physical address range identified by **PhysicalReserveContext** that indicates the actual base address at which to unmap system memory.

## Remarks

When a miniport driver calls **AgpFreePhysical**, **Pages** pages of physical memory are unlocked and unmapped from the AGP-decodable physical address range. This range begins **Offset** pages into the range identified by **PhysicalReserveContext**. The miniport driver must specify that the exact offset and number of pages be freed as were committed in a prior call to [AgpCommitPhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_commit_physical).

## See also

[AgpCommitPhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_commit_physical)

[AgpReleasePhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_release_physical)