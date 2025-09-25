# _D3DKMT_GETMULTISAMPLEMETHODLIST structure

## Description

The D3DKMT_GETMULTISAMPLEMETHODLIST structure describes parameters to retrieve the list of multiple-sample methods for an allocation.

## Members

### `hAdapter` [in]

A handle to the graphics adapter.

### `VidPnSourceId` [in]

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology that the allocation is on.

### `Width` [in]

The width of the allocation, in pixels.

### `Height` [in]

The height of the allocation, in pixels.

### `Format` [in]

A [D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)-typed value that indicates the pixel format of the allocation.

### `pMethodList` [out]

An array of [D3DKMT_MULTISAMPLEMETHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_multisamplemethod) structures that describe the list of multiple-sampling methods used for the allocation; otherwise, this member is **NULL**.

### `MethodCount` [in/out]

On input, the number of elements that the array that is specified by **pMethodList** can hold. On output, this member specifies the required number of elements that the array that is specified by **pMethodList** should hold.

## Remarks

If the runtime returns a non-**NULL** value in **pMethodList**, the runtime returns a value in **MethodCount** that represents the number of elements that the array can hold. If the runtime returns **NULL** in **pMethodList**, the runtime returns a value in **MethodCount** that represents the size of the array buffer that is required, in number of elements.

## See also

[D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)

[D3DKMTGetMultisampleMethodList](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtgetmultisamplemethodlist)

[D3DKMT_MULTISAMPLEMETHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_multisamplemethod)