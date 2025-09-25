# D3DDDI_SEGMENTPREFERENCE structure

## Description

The **D3DDI_SEGMENTPREFERENCE** structure describes the preferred segment for this allocation being created.

## Members

### `SegmentId0`

The identifier of the highest priority preferred segment, or zero if no preferred segment is required. Valid values are from 0 through 31. This member is equivalent to the first 5 bits of the **Value** member.

### `Direction0`

Set to zero to indicate that *VidMm* chooses which end of **SegmentId0** to do the allocation from. This member is equivalent to the sixth bit of the **Value** member.

### `SegmentId1`

The identifier of the next highest priority preferred segment, or zero if no preferred segment is required. Valid values are from 0 through 31. This member is equivalent to bits 7 through 11 of the **Value** member.

### `Direction1`

Set to zero to indicate that *VidMm* chooses which end of **SegmentId1** to do the allocation from. This member is equivalent to the 12th bit of the **Value** member.

### `SegmentId2`

The identifier of the next highest priority preferred segment, or zero if no preferred segment is required. Valid values are from 0 through 31. This member is equivalent to bits 13 through 17 of the **Value** member.

### `Direction2`

Set to zero to indicate that *VidMm* chooses which end of **SegmentId2** to do the allocation from. This member is equivalent to the 18th bit of the **Value** member.

### `SegmentId3`

The identifier of the next highest priority preferred segment, or zero if no preferred segment is required. Valid values are from 0 through 31. This member is equivalent to bits 19 through 23 of the **Value** member.

### `Direction3`

Set to zero to indicate that *VidMm* chooses which end of **SegmentId3** to do the allocation from. This member is equivalent to the 24th bit of the **Value** member.

### `SegmentId4`

The identifier of the next highest priority preferred segment, or zero if no preferred segment is required. Valid values are from 0 through 31. This member is equivalent to bits 25 through 29 of the **Value** member.

### `Direction4`

Set to zero to indicate that *VidMm* chooses which end of **SegmentId4** to do the allocation from. This member is equivalent to the 30th bit of the **Value** member.

### `Reserved`

Reserved (bits 31-32).

### `Value`

An alternative way to access the segment preference information.

## Remarks

The segment preference is used when allocating memory. When user mode (for example, the D3D runtime) calls [**D3DKMTCreateAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreateallocation), the UMD provides private driver data describing the allocation. *Dxgkrnl* takes this private driver data and passes it to the KMD who then fills out a description of each allocation in a way understood by *VidMm*. The UMD data contains information such as the resource type (texture, swapchain, etc). The KMD translates this data to things like size, alignment, a set of memory segments that the allocation can be located, preferences for these segments (as indicated by this structure), and so forth.

## See also

[**D3DKMTCreateAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreateallocation)

[**D3DKMTUpdateAllocationProperty**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtupdateallocationproperty)