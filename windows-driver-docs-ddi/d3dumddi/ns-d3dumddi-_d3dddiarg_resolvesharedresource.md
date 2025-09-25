# _D3DDDIARG_RESOLVESHAREDRESOURCE structure

## Description

The D3DDDIARG_RESOLVESHAREDRESOURCE structure specifies the resource that the user-mode display driver's [ResolveSharedResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_resolvesharedresource) function uses as a synchronized shared surface or a GDI interoperable surface.

## Members

### `hResource` [in]

A handle to the surface that the driver uses as a shared surface or in GDI interoperability.

## See also

[ResolveSharedResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_resolvesharedresource)