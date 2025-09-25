## Description

KMD's **DxgkDdiCreateMemoryBasis** function creates a handle for a collection of memory ranges that represent the allocation being operated on during dirty bit tracking.

## Parameters

### `hAdapter`

[in] A handle to a context block associated with a display adapter. KMD previously provided this handle to *Dxgkrnl* in the **MiniportDeviceContext** output parameter of the [**DxgiDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pArgs`

[in] A pointer to a [**DXGKARG_CREATEMEMORYBASIS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_creatememorybasis) structure that contains information for the basis being created.

## Return value

**DxgkDdiCreateMemoryBasis** returns a HANDLE to KMD's reference for tracking the collection of ranges. KMD should be able to transform this information into the information of the basis in subsequent commands like [**DxgkDdiDestroyMemoryBasis**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_destroymemorybasis).

## Remarks

The tracking of modify operations on VRAM is for allocations that might not be backed contiguously. So the physical addresses represented in the tracking of dirty bits consists of a collection of ranges representing the allocation being operated on. **DxgkDdiCreateMemoryBasis** returns a handle to KMD's reference for tracking these ranges.

The KMD can rely on the following invariants:

* For each range in **Ranges**, both **SegmentOffset** and (**SegmentOffset** + **SizeInBytes** - 1) represent valid addresses on the segment referred to by **SegmentId**.

* All **Ranges** are pairwise disjoint; that is, the intersection between any two ranges is always null.

It is also common that **SegmentOffset** and **SizeInBytes** will respect certain page alignments when the created memory basis is used in certain dirty tracking DDIs. These values are described on those DDI's reference page, and are always a multiple of [**DXGK_DIRTY_BIT_TRACKING_SEGMENT_CAPS::PageSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_dirty_bit_tracking_segment_caps).

*Dxgkrnl* otherwise doesn't make guarantees about the ordering of the addresses in the collection of **Ranges** or related assurances.

For more information, see [Dirty bit tracking](https://learn.microsoft.com/windows-hardware/drivers/display/dirty-bit-tracking).

## See also

[**DXGKARG_CREATEMEMORYBASIS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_creatememorybasis)

[**DxgkDdiDestroyMemoryBasis**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_destroymemorybasis)