# D3D12DDI_VIDEO_MOTION_ESTIMATOR_INPUT_0053 structure

## Description

Describes the input to the motion estimation operation.

## Members

### `hDrvInputTexture2D`

The handle of the current frame.

### `InputSubresourceIndex`

Specifies the start coordinates of the motion estimation operation for hDrvInputTexture2D.

### `hDrvReferenceTexture2D`

The handle of the reference frame, or Past frame, used for motion estimation.

### `ReferenceSubresourceIndex`

A 256-byte aligned offset into the hDrvPreviousMotionVectorHeap buffer indicating the start of the hardware dependent data.

### `hDrvPreviousMotionVectorHeap`

This parameter may be NULL, indicating that the previous motion estimator output should not be considered for this operation. If non-NULL, this buffer contains the hardware dependent output of the previous motion estimator operation and may be used for hinting the current operation.

## Remarks

## See also