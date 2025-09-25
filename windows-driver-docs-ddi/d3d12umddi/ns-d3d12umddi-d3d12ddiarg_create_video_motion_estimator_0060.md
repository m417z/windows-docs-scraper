# D3D12DDIARG_CREATE_VIDEO_MOTION_ESTIMATOR_0060 structure

## Description

Specifies the creation arguments for the video motion estimator.

## Members

### `NodeMask`

For a single GPU operation, set this to zero. If there are multiple GPU nodes, set a bit to identify the node (the device's physical adapter) to which the command queue applies. Each bit in the mask corresponds to a single node. Only 1 bit may be set.

### `InputFormat`

The DXGI_FORMAT of the input and reference frames. This motion estimator may only be used with input textures of this format.

### `BlockSize`

The search block size to use with this motion estimator. This parameter determines the number of motion vectors and difference metrics output during the resolve step. This must be a block size reported as supported by the driver.

### `Precision`

The precision of motion vector components. This must be a precision reported as supported by the driver.

### `SizeRange`

Indicates the minimum and maximum size of the inputs to the motion estimation operation. Actual size is provided at motion estimation time. Driver should allocate at the creation of the motion estimator to support any size within the range. This size range must be a subset of the size range supported by the driver.

### `hDrvProtectedResourceSession`

Indicates the protected resource session to use for the motion estimator. This can inform internal allocations for the motion estimator. This value is NULL if the motion estimator will operate on unprotected resources.

## Remarks

## See also