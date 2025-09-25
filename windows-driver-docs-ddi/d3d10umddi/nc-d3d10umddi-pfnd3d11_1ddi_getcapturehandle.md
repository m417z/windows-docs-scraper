# PFND3D11_1DDI_GETCAPTUREHANDLE callback function

## Description

Returns the handle for a specified resource that was allocated by the driver. This function also returns the size and location of specified data within the resource.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `pHandleData`

A pointer to a [D3D11_1DDI_GETCAPTUREHANDLEDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-_d3d11_1ddi_getcapturehandledata) structure that defines the resource allocation.

## Remarks

Before the Microsoft Direct3D runtime calls the *GetCaptureHandle* function, it sets the **hResource** and **ArrayIndex** members of the [D3D11_1DDI_GETCAPTUREHANDLEDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-_d3d11_1ddi_getcapturehandledata) structure to specify a resource. When this function is called, the driver updates the structure with the kernel mode allocation handle associated with the specified resource, as well as the size of the resource data and its offset within an allocated block of memory.

**Note** The Direct3D runtime calls this function only for resources that were created with the **D3D11_DDI_BIND_CAPTURE** flag.

## See also

[D3D11_1DDI_GETCAPTUREHANDLEDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-_d3d11_1ddi_getcapturehandledata)