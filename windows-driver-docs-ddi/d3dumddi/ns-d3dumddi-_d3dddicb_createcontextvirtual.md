# _D3DDDICB_CREATECONTEXTVIRTUAL structure

## Description

**D3DDDICB_CREATECONTEXTVIRTUAL** is used with [pfnCreateContextVirtualCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createcontextvirtualcb) to create contexts that support virtual addressing.

## Members

### `NodeOrdinal` [in]

The zero-based index for the node that the context is scheduled on.

### `EngineAffinity` [in]

The zero-based index for the engine, within the node that **NodeOrdinal** specifies, that the context can run in.

### `Flags` [in]

A [D3DDDI_CREATECONTEXTFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_createcontextflags) structure that indicates, in bit-field flags, how to create the context.

### `pPrivateDriverData` [in]

A pointer to private data that is passed to a display miniport driver.

### `PrivateDriverDataSize` [in]

The size, in bytes, of the private data that **pPrivateDriverData** points to.

### `hContext` [out]

A handle to the context that the [pfnCreateContextVirtualCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createcontextvirtualcb) function creates.

## See also

[D3DDDI_CREATECONTEXTFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_createcontextflags)

[pfnCreateContextVirtualCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createcontextvirtualcb)