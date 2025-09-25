# D3D12DDIARG_CREATE_VIDEO_MOTION_VECTOR_HEAP_0060 structure

## Description

Arguments used to create a video motion vector heap.

## Members

### `NodeMask`

For a single GPU operation, set this to zero. If there are multiple GPU nodes, set a bit to identify the node (the device's physical adapter) to which the command queue applies. Each bit in the mask corresponds to a single node. Only 1 bit may be set.

### `InputFormat`

The DXGI_FORMAT of the input and reference frames.

### `BlockSize`

The search block size to use with this motion vector heap.

### `Precision`

The precision of motion vector components.

### `SizeRange`

Indicates the minimum and maximum size of the inputs to the motion vector heap creation.

### `hDrvProtectedResourceSession`

Indicates the protected resource session to use for the motion vector heap creation.

## Remarks

## See also