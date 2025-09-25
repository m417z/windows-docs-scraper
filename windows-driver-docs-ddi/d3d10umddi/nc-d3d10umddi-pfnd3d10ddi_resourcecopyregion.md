# PFND3D10DDI_RESOURCECOPYREGION callback function

## Description

The *ResourceCopyRegion* function copies a source subresource region to a location on a destination subresource.

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

If the members of the [D3D10_DDI_BOX](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_box) structure are such that **left**>=**right**, **top**>=**bottom**, or **front**>=**back**, then *pSrcBox* is considered empty, and *ResourceCopyRegion* must not perform any copy operation.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The Microsoft Direct3D runtime calls the user-mode display driver's *ResourceCopyRegion* function to inform the driver to copy from the specified source subresource region to a location on the specified destination subresource. The source and destination subresources cannot be the same subresource of the same resource. Both source and destination resources must be the same type of resource and must have format types (DXGI_FORMAT-typed values) that are convertible to each other.

For buffers, all the coordinates must be in bytes; whereas for textures, all the coordinates must be in pixels. The box that the *pSrcBox* parameter points to must not extend over the edges of the source subresource region or the destination subresource. The source and the destination resource must not be currently mapped. In addition, the resource creation flags restrict whether the resource can participate in the copy operation.

The driver should not encounter any error, except for D3DDDIERR_DEVICEREMOVED. Therefore, if the driver passes any error, except for D3DDDIERR_DEVICEREMOVED, in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function, the Direct3D runtime will determine that the error is critical. Even if the device was removed, the driver is not required to return D3DDDIERR_DEVICEREMOVED; however, if device removal interfered with the operation of *ResourceCopyRegion* (which typically should not happen), the driver can return D3DDDIERR_DEVICEREMOVED.

**Note** The following sections apply only to Microsoft Direct3D version 10.1 and later (that is, Windows Vista with Service Pack 1 (SP1) and later, and Windows Server 2008 and later).

The driver can implement a *ResourceCopyRegion* function that can contain a **switch** statement to process copying and conversion. That is, the driver can implement one *ResourceCopyRegion* and can set the **pfnResourceConvertRegion** member of the [D3D10_1DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_1ddi_devicefuncs) structure to point to *ResourceCopyRegion* along with the **pfnResourceCopyRegion** member of D3D10_1DDI_DEVICEFUNCS. However, to improve performance, the driver can implement separate *ResourceCopyRegion* and *ResourceConvertRegion* functions.

The Direct3D 10.1 version of *ResourceCopyRegion* has a major functionality difference from the Direct3D 10.0 version in regard to the **ResourceDimension** member of [D3D10DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createresource) for the source and destination resources that were created in calls to the driver's [CreateResource(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createresource) function. For the Direct3D 10.0 version of *ResourceCopyRegion*, the **ResourceDimension** member of D3D10DDIARG_CREATERESOURCE for the source and destination resources must match. The Direct3D 10.1 version of *ResourceCopyRegion* allows a slight relaxation for the **ResourceDimension** member of D3D10DDIARG_CREATERESOURCE for the source and destination resources. The Direct3D 10.1 version of *ResourceCopyRegion* allows for the copying of Tex2D source resources on TexCube destination resources or TexCube source resources on Tex2D destination resources. In addition, the distinction between TexCube at the resource level is gone in Direct3D version 10.1. The Direct3D 10.1 version of *ResourceCopyRegion* only represents whether it can copy a TexCube. In Direct3D version 10.0, copying a resource, validation of a multiple render target, and so on (that is, various operations that required the resource type to be identical) all included the distinction of TexCube to factor into the resource type. In Direct3D version 10.1, the runtime can determine only Tex2D.

The following sections list conditions for copying and converting:

**Copying**

For copying, *ResourceCopyRegion* ensures that the source and destination resources were created through the driver's [CreateResource(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createresource) function with the following conditions:

* The destination resource was not created with the D3D10_DDI_USAGE_IMMUTABLE value set in the **Usage** member of the [D3D10DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createresource) structure.
* If either the source or destination resource has the D3D10_DDI_BIND_DEPTH_STENCIL bit set in the **BindFlags** member of the D3D10DDIARG_CREATERESOURCE or is a multi-sampled resource, *ResourceCopyRegion* verifies that the *pSrcBox* parameter is **NULL**, while the *DstX*, *DstY*, and *DstZ* parameters are 0.
* The subresource indices are in range.
* Alignment restrictions apply to coordinates.
* The source and destination resources are not part of the exact same subresource.
* Each source and destination resource format that is specified in the **Format** member of D3D10DDIARG_CREATERESOURCE is in the same typeless group.
* The source and destination resources must have the same number of samples and quality levels; except for single-sampled resources, which must only have the same number of samples.

*ResourceCopyRegion* does not ensure that the source box that is offset by the destination offsets fits entirely on the resource. *ResourceCopyRegion* also does not ensure that no subresources are currently mapped.

**Converting**

For conversion, *ResourceCopyRegion* ensures that the source and destination resources were created through the driver's [CreateResource(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createresource) function with the following conditions:

* The destination resource was not created with the D3D10_DDI_USAGE_IMMUTABLE value set in the **Usage** member of the [D3D10DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createresource) structure.
* If either the source or destination resource has the D3D10_DDI_BIND_DEPTH_STENCIL bit set in the **BindFlags** member of the D3D10DDIARG_CREATERESOURCE or is a multi-sampled resource, *ResourceCopyRegion* verifies that the *pSrcBox* parameter is **NULL**, while the *DstX*, *DstY*, and *DstZ* parameters are 0.
* The subresource indices are in range.
* Alignment restrictions apply to coordinates.
* The source and destination resources are not part of the exact same subresource.
* Each source and destination resource format that is specified in the **Format** member of D3D10DDIARG_CREATERESOURCE is in the same typeless group.
* Each source and destination resource format that is specified in the **Format** member of D3D10DDIARG_CREATERESOURCE supports the appropriate conversion operation.
* The source and destination resources must have the same number of samples and quality levels; except for single-sampled resources, which must only have the same number of samples.

*ResourceCopyRegion* does not ensure that no subresources are currently mapped. *ResourceCopyRegion* also does not ensure that the source box that is offset by the destination offsets fits entirely on the resource.

## See also

[D3D10DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs)

[D3D10_DDI_BOX](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_box)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)