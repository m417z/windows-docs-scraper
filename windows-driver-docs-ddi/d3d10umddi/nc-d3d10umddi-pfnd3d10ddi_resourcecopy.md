# PFND3D10DDI_RESOURCECOPY callback function

## Description

The *ResourceCopy* function copies an entire source resource to a destination resource.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hDstResource* [in]

A handle to the destination resource to copy to.

### `unnamedParam3`

*hSrcResource* [in]

A handle to the source resource to copy from.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The Microsoft Direct3D runtime calls the user-mode display driver's *ResourceCopy* function to inform the driver to copy from the specified source resource to the specified destination resource. The source and destination resources cannot be the same resource. Both source and destination resources must be the same type of resource and have the same dimensions. The format types (DXGI_FORMAT-typed values) of both resources must be castable to each other. The source and the destination resource must not be currently mapped. In addition, the resource creation flags restrict whether the resource can participate in the copy operation.

The driver should not encounter any error, except for D3DDDIERR_DEVICEREMOVED. Therefore, if the driver passes any error, except for D3DDDIERR_DEVICEREMOVED, in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function, the Direct3D runtime will determine that the error is critical. Even if the device was removed, the driver is not required to return D3DDDIERR_DEVICEREMOVED; however, if device removal interfered with the operation of *ResourceCopy* (which typically should not happen), the driver can return D3DDDIERR_DEVICEREMOVED.

**Note** The following sections apply only to Microsoft Direct3D version 10.1 and later (that is, Windows Vista with Service Pack 1 (SP1) and later, and Windows Server 2008 and later).

The driver can implement a *ResourceCopy* function that can contain a **switch** statement to process copying and conversion. That is, the driver can implement one *ResourceCopy* and can set the **pfnResourceConvert** member of the [D3D10_1DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_1ddi_devicefuncs) structure to point to *ResourceCopy* along with the **pfnResourceCopy** member of D3D10_1DDI_DEVICEFUNCS. However, to improve performance, the driver can implement separate *ResourceCopy* and *ResourceConvert* functions.

The Direct3D 10.1 version of *ResourceCopy* has a major functionality difference from the Direct3D 10.0 version in regard to the **ResourceDimension** member of [D3D10DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createresource) for the source and destination resources that were created in calls to the driver's [CreateResource(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createresource) function. For the Direct3D 10.0 version of *ResourceCopy*, the **ResourceDimension** member of D3D10DDIARG_CREATERESOURCE for the source and destination resources must match. The Direct3D 10.1 version of *ResourceCopy* allows a slight relaxation for the **ResourceDimension** member of D3D10DDIARG_CREATERESOURCE for the source and destination resources. The Direct3D 10.1 version of *ResourceCopy* allows for the copying of Tex2D source resources on TexCube destination resources or TexCube source resources on Tex2D destination resources. In addition, the distinction between TexCube at the resource level is gone in Direct3D version 10.1. The Direct3D 10.1 version of *ResourceCopy* only represents whether it can copy a TexCube. In Direct3D version 10.0, copying a resource, validation of a multiple render target, and so on (that is, various operations that required the resource type to be identical) all included the distinction of TexCube to factor into the resource type. In Direct3D version 10.1, the runtime can determine only Tex2D.

The following sections list conditions for copying and converting:

**Copying**

For copying, *ResourceCopy* ensures that the source and destination resources were created through the driver's [CreateResource(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createresource) function with the following conditions:

* The destination resource was not created with the D3D10_DDI_USAGE_IMMUTABLE value set in the **Usage** member of the [D3D10DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createresource) structure.
* The source and destination resources were created with the same resource type and dimensionality (buffer, one-dimensional (1-D) texture, and so on) by setting the same value in the **ResourceDimension** member of D3D10DDIARG_CREATERESOURCE.
* The source and destination resources are not part of the exact same resource.
* Each source and destination resource format that is specified in the **Format** member of D3D10DDIARG_CREATERESOURCE is in the same typeless group.
* The source and destination resources must have the same number of samples and quality levels; except for single-sampled resources, which must only have the same number of samples.

*ResourceCopy* does not ensure that no subresources are currently mapped.

**Converting**

For conversion, *ResourceCopy* ensures that the source and destination resources were created through the driver's [CreateResource(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createresource) function with the following conditions:

* The destination resource was not created with the D3D10_DDI_USAGE_IMMUTABLE value set in the **Usage** member of the [D3D10DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createresource) structure.
* The source and destination resources were created with the same resource type (buffer, one-dimensional (1-D) texture, and so on) by setting the same value in the **ResourceDimension** member of D3D10DDIARG_CREATERESOURCE.
* The dimensions of the source and destination resources match up for conversion.
* The source and destination resources are not part of the exact same resource.
* Each source and destination resource format that is specified in the **Format** member of D3D10DDIARG_CREATERESOURCE supports the appropriate conversion operation. For mipped-block compressed resources, the dimensions are all validated to be a power of two.
* The source and destination resources must have the same number of samples and quality levels; except for single-sampled resources, which must only have the same number of samples.

*ResourceCopy* does not ensure that no subresources are currently mapped.

## See also

[CreateResource(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createresource)

[D3D10DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createresource)

[D3D10DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs)

[D3D10_1DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_1ddi_devicefuncs)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)