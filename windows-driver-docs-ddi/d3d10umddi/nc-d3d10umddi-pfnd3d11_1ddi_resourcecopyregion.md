# PFND3D11_1DDI_RESOURCECOPYREGION callback function

## Description

Copies a source subresource region to a location on a destination subresource.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hDstResource* [in]

A handle to the destination resource to copy to.

### `unnamedParam3`

*DstSubresource* [in]

An index that indicates the destination subresource to copy to.

### `unnamedParam4`

*DstX* [in]

The x-coordinate of the destination subresource.

### `unnamedParam5`

*DstY* [in]

The y-coordinate of the destination subresource. For one-dimensional (1-D) subresources, *DstY* is set to zero.

### `unnamedParam6`

*DstZ* [in]

The z-coordinate of the destination subresource. For one-dimensional (1-D) and two-dimensional (2-D) subresources, *DstZ* is set to zero.

### `unnamedParam7`

*hSrcResource* [in]

A handle to the source resource to copy from.

### `unnamedParam8`

*SrcSubresource* [in]

An index that indicates the source subresource to copy from.

### `unnamedParam9`

*pSrcBox* [in, optional]

A pointer to a [D3D10_DDI_BOX](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_box) structure that specifies a box that fits on either the source or destination subresource. If *pSrcBox* is **NULL**, the driver should copy the entire source subresource to the destination.

If the members of the [D3D10_DDI_BOX](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_box) structure are such that **left**>=**right**, **top**>=**bottom**, or **front**>=**back**, then *pSrcBox* is considered empty, and *ResourceCopyRegion(D3D11_1)* must not perform any copy operation.

### `CopyFlags` [in]

A value that specifies characteristics of copy operation as a bitwise **OR** of the values in the [D3D11_1_DDI_COPY_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1_ddi_copy_flags) enumeration type.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The Microsoft Direct3D runtime calls the user-mode display driver's *ResourceCopyRegion(D3D11_1)* function to inform the driver to copy from the specified source subresource region to a location on the specified destination subresource. The source and destination subresources can be the same subresource of the same resource. Both source and destination resources must be the same type of resource and must have format types (DXGI_FORMAT-typed values) that are convertible to each other.

For buffers, all the coordinates must be in bytes; whereas for textures, all the coordinates must be in pixels. The box that the *pSrcBox* parameter points to must not extend over the edges of the source subresource region or the destination subresource. The source and the destination resource must not be currently mapped. In addition, the resource creation flags restrict whether the resource can participate in the copy operation.

The driver should not encounter any error, except for D3DDDIERR_DEVICEREMOVED. Therefore, if the driver passes any error, except for D3DDDIERR_DEVICEREMOVED, in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function, the Direct3D runtime will determine that the error is critical. Even if the device was removed, the driver is not required to return D3DDDIERR_DEVICEREMOVED; however, if device removal interfered with the operation of (which typically should not happen), the driver can return D3DDDIERR_DEVICEREMOVED.

The driver can implement a *ResourceCopyRegion(D3D11_1)* function that can contain a **switch** statement to process copying and conversion. That is, the driver can implement one *ResourceCopyRegion(D3D11_1)* and can set the **pfnResourceConvertRegion** member of the [D3D11_1DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_devicefuncs) structure to point to *ResourceCopyRegion(D3D11_1)* along with the **pfnResourceCopyRegion** member of **D3D11_1DDI_DEVICEFUNCS**. However, to improve performance, the driver can implement separate *ResourceCopyRegion(D3D11_1)* and *ResourceConvertRegion(D3D11_1)* functions.

The following sections list conditions for copying and converting:

**Copying**

For copying, *ResourceCopyRegion(D3D11_1)* ensures that the source and destination resources were created through the driver's [CreateResource(D3D11)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createresource) function with the following conditions:

* The destination resource was not created with the D3D10_DDI_USAGE_IMMUTABLE value set in the **Usage** member of the [D3D11DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createresource) structure.
* If either the source or destination resource has the D3D10_DDI_BIND_DEPTH_STENCIL bit set in the **BindFlags** member of the D3D10DDIARG_CREATERESOURCE or is a multi-sampled resource, *ResourceCopyRegion(D3D11_1)* verifies that the **pSrcBox** parameter is **NULL**, while the *DstX*, *DstY*, and *DstZ* parameters are 0.
* The subresource indices are in range.
* Alignment restrictions apply to coordinates.
* The source and destination resources are not part of the exact same subresource.
* Each source and destination resource format that is specified in the **Format** member of [D3D11DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createresource) is in the same typeless group.
* The source and destination resources must have the same number of samples and quality levels; except for single-sampled resources, which must only have the same number of samples.

*ResourceCopyRegion(D3D11_1)* does not ensure that the source box that is offset by the destination offsets fits entirely on the resource. *ResourceCopyRegion(D3D11_1)* also does not ensure that no subresources are currently mapped.

**Converting**

For conversion, *ResourceCopyRegion(D3D11_1)* ensures that the source and destination resources were created through the driver's [CreateResource(D3D11)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createresource) function with the following conditions:

* The destination resource was not created with the D3D10_DDI_USAGE_IMMUTABLE value set in the **Usage** member of the [D3D11DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createresource) structure.
* If either the source or destination resource has the D3D10_DDI_BIND_DEPTH_STENCIL bit set in the **BindFlags** member of [D3D11DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createresource) or is a multi-sampled resource, *ResourceCopyRegion(D3D11_1)* verifies that the *pSrcBox* parameter is **NULL**, while the *DstX*, *DstY*, and *DstZ* parameters are 0.
* The subresource indices are in range.
* Alignment restrictions apply to coordinates.
* The source and destination resources are not part of the exact same subresource.
* Each source and destination resource format that is specified in the **Format** member of [D3D11DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createresource) is in the same typeless group.
* Each source and destination resource format that is specified in the **Format** member of [D3D11DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createresource) supports the appropriate conversion operation.
* The source and destination resources must have the same number of samples and quality levels; except for single-sampled resources, which must only have the same number of samples.

*ResourceCopyRegion(D3D11_1)*
does not ensure that no subresources are currently mapped. *ResourceCopyRegion(D3D11_1)* also does not ensure that the source box that is offset by the destination offsets fits entirely on the resource.

## See also

[CreateResource(D3D11)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createresource)

[D3D10_DDI_BOX](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_box)

[D3D11DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createresource)

[D3D11_1DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_devicefuncs)

[D3D11_1_DDI_COPY_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1_ddi_copy_flags)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)