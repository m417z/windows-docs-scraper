# D3DKMT_ADAPTER_VERIFIER_VIDMM_FLAGS structure

## Description

The **D3DKMT_ADAPTER_VERIFIER_VIDMM_FLAGS** structure contains Verifier flags for the video memory manager (*VidMm*).

## Members

### `AlwaysRepatch`

Always repatch.

### `FailSharedPrimary`

Fail shared primary.

### `FailProbeAndLock`

Fail probe and lock.

### `AlwaysDiscardOffer`

Always discard offer.

### `NeverDiscardOffer`

Never discard offer.

### `ForceComplexLock`

Force complex lock.

### `NeverPrepatch`

Never prepatch.

### `ExpectPreparationFailure`

Expect preparation failure.

### `TakeSplitPoint`

Take split point.

### `FailAcquireSwizzlingRange`

Fail acquire swizzling range.

### `PagingPathLockSubrange`

Paging path lock subrange.

### `PagingPathLockMinrange`

Paging path lock min-range.

### `FailVaRotation`

Fail VA rotation.

### `NoDemotion`

No demotion.

### `FailDefragPass`

Fail defragmentation pass.

### `AlwaysProcessOfferList`

Always process offer list.

### `AlwaysDecommitOffer`

Always decommit offer.

### `NeverMoveDefrag`

Never move defragmentation.

### `AlwaysRelocateDisplayableResources`

Always relocate displayable resources.

### `AlwaysFailGrowVPRMoves`

Always fail grow VPR moves.

### `NeverFlushTemporaryResources`

Instructs *VidMm* to not flush any temporary resources unless it's required to do so.

### `AllocateTemporaryResourcesInAperture`

Instructs *VidMm* to allocate temporary resources in the aperture.

### `Reserved`

Reserved for internal use.

### `Value`

An alternative way to access the flags.

## Remarks

## See also

[D3DKMT_ADAPTER_VERIFIER_OPTION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_adapter_verifier_option_data)