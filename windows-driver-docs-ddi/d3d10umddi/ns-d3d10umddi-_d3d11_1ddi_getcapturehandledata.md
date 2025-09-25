# _D3D11_1DDI_GETCAPTUREHANDLEDATA structure

## Description

Defines a resource allocation in a call to the [GetCaptureHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getcapturehandle) function.

## Members

### `hResource` [in]

The handle to the resource for which the allocation handle is to be obtained.

The Direct3D version 11 and later runtime will have already verified that this resource was created using the **D3D11_DDI_BIND_CAPTURE** value in the [D3D10_DDI_RESOURCE_BIND_FLAG](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_resource_bind_flag) enumeration.

### `ArrayIndex` [in]

The array element from which the data is to be obtained.

If the resource was not created as a texture array, this value is zero. For a texture array, the Direct3D version 11 and later runtime will have already verified that the array is valid.

### `hAllocation` [out]

The driver-provided address of the kernel mode allocation handle associated with this allocation.

### `DataOffset` [out]

The driver-provided offset of the requested data within the allocation.

If the resource was not created as a texture array, this value is typically zero. For a texture array, this value is the offset of the array element data within the allocation.

### `DataSize` [out]

The driver-provided size of the requested data within the allocation.

If the resource was not created as a texture array, this value is typically the size of the allocation, in bytes. For a texture array, this value is the size of the element data within the allocation.

## Remarks

When the [GetCaptureHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getcapturehandle) function is called, the driver updates the structure with the kernel mode allocation handle associated with the specified resource, as well as the size of the resource data and its offset within an allocated block of memory.

## See also

[D3D10_DDI_RESOURCE_BIND_FLAG](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_resource_bind_flag)

[GetCaptureHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getcapturehandle)