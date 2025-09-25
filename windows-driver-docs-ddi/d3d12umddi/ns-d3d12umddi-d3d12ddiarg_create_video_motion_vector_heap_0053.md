# D3D12DDIARG_CREATE_VIDEO_MOTION_VECTOR_HEAP_0053 structure

## Description

Arguments used by the [PFND3D12DDI_CREATEVIDEOMOTIONVECTORHEAP_0053](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createvideomotionvectorheap_0053) callback function to create a motion vector heap.

## Members

### `NodeMask`

For a single GPU operation, set this to zero. If there are multiple GPU nodes, set a bit to identify the node (the device's physical adapter) to which the command queue applies. Each bit in the mask corresponds to a single node. Only 1 bit may be set.

### `InputFormat`

The DXGI_FORMAT of the input and reference frames.

### `BlockSize`

The search block size to use with this motion vector heap.

### `Precision`

The precision of motion vector components.

### `DifferencesMetric`

Indicates the differences metric to capture during motion vector heap creation.

### `SizeRange`

Indicates the minimum and maximum size of the inputs to the motion vector heap creation.

### `hDrvProtectedResourceSession`

Indicates the protected resource session to use for the motion vector heap creation.

## Remarks

## See also