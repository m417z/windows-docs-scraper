# PAGP_FREE_VIRTUAL callback function

## Description

The **AgpFreeVirtual** function frees virtual memory committed by a previous call to [AgpCommitVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_commit_virtual).

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `VirtualReserveContext` [in]

Identifies a reserved virtual address range. This context handle was obtained from [AgpReserveVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_reserve_virtual).

### `Pages` [in]

Specifies the number of pages of virtual memory that the video port driver should unmap.

### `Offset` [in]

Specifies the page offset into the reserved virtual address range identified by **VirtualReserveContext** that indicates the actual base address at which to unmap virtual memory.

## Remarks

When a miniport driver calls **AgpFreeVirtual**, *Pages* pages of virtual addresses are unmapped. The unmapped range begins **Offset** pages into the range associated with **VirtualReserveContext**. The miniport driver must specify that the exact offset and number of pages be freed as were committed in a prior call to [AgpCommitVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_commit_virtual).

A call to **AgpFreeVirtual** must be paired with a previous call to [AgpCommitVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_commit_virtual), and that call to **AgpCommitVirtual** must be preceded by a successful call to [AgpReserveVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_reserve_virtual). If **AgpReserveVirtual** fails (returns **NULL**), you must not call **AgpCommitVirtual** or **AgpFreeVirtual**.

## See also

[AgpCommitVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_commit_virtual)