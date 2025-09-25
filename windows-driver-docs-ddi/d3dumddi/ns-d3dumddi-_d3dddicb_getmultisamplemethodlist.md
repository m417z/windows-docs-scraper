# _D3DDDICB_GETMULTISAMPLEMETHODLIST structure

## Description

The D3DDDICB_GETMULTISAMPLEMETHODLIST structure describes parameters to retrieve the list of multiple-sample methods for an allocation.

## Members

### `VidPnSourceId` [in]

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology that the allocation is on.

### `Width` [in]

The width of the allocation, in pixels.

### `Height` [in]

The height of the allocation, in pixels.

### `Format` [in]

A [D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)-typed value that indicates the pixel format of the allocation.

### `pMethodList` [out]

An array of [D3DDDI_MULTISAMPLINGMETHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_multisamplingmethod) structures that describe the list of multiple-sampling methods that are used for the allocation or **NULL**.

### `MethodCount` [in/out]

On input, the number of elements that the buffer at **pMethodList** can hold. On output, this member specifies the required number of elements that the buffer at **pMethodList** should hold.

## Remarks

If the runtime returns a non-**NULL** value in the **pMethodList** member, the runtime returns a value in the **MethodCount** member that represents the number of elements that the array can hold. If the runtime returns **NULL** at **pMethodList**, the runtime returns a value in **MethodCount** that represents the size of the array buffer that is required, in number of elements.

## See also

[D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)

[D3DDDI_MULTISAMPLINGMETHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_multisamplingmethod)

[pfnGetMultisampleMethodListCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getmultisamplemethodlistcb)