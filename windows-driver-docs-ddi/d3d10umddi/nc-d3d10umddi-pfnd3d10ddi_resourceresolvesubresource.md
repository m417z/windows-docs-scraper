# PFND3D10DDI_RESOURCERESOLVESUBRESOURCE callback function

## Description

The *ResourceResolveSubresource* function resolves multiple samples to one pixel.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hDstResource* [in]

A handle to the destination resource to resolve to. This resource must have been created as D3D10_USAGE_DEFAULT and single sampled.

### `unnamedParam3`

*DstSubresource* [in]

An index that indicates the destination subresource to resolve to.

### `unnamedParam4`

*hSrcResource* [in]

A handle to the source resource to resolve from.

### `unnamedParam5`

*SrcSubresource* [in]

An index that indicates the source subresource to resolve from.

### `unnamedParam6`

*ResolveFormat* [in]

A DXGI_FORMAT-typed value that indicates how to interpret the contents of the resolved resource.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The algorithm to resolve multiple samples to one pixel depends on the implementation.

The resolve operation shares similar restrictions to copy operations that occur in calls to the [ResourceCopy](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcecopy) and [ResourceCopyRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcecopyregion) functions. That is, both source and destination resources must be the same type (for example, Texture2D), and no stretching or format conversions can occur. The driver can resolve only a whole subresource; therefore, both the source and destination subresources must be equal in dimensions. Because of typeless resources, the following interactions can exist with either the source or destination resource format:

* If each resource is prestructured plus typed, both resources must have the same format type, and that format type must match the format type that was passed in the *ResolveFormat* parameter (for example, all R32_FLOAT).
* If one resource is prestructured plus typeless, the prestructured-plus-typed resource's format must be compatible with the typeless format, and the format type that was passed in the *ResolveFormat* parameter must match the prestructured-plus-typed format (for example, if the source format is R32_TYPELESS, and the destination format and *ResolveFormat* are R32_FLOAT).
* If both resources are prestructured plus typeless, they must be equal formats, and the format type that was passed in the *ResolveFormat* parameter can be any format that is compatible with the typeless format. (for example, if the source and destination format are R32_TYPELESS, and *ResolveFormat* is R32_FLOAT or R32_UINT).

## See also

[ResourceCopy](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcecopy)

[ResourceCopyRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcecopyregion)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)