# D3DKMT_CREATECONTEXTVIRTUAL structure

## Description

**D3DKMT_CREATECONTEXTVIRTUAL** is used with [**D3DKMTCreateContextVirtual**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatecontextvirtual) to create a kernel-mode device context that supports virtual addressing.

## Members

### `hDevice`

[in] A handle to the device that owns the context being created.

### `NodeOrdinal`

[in] The zero-based index for the node that the context is scheduled on.

### `EngineAffinity`

[in] The zero-based index for the engine, within the node that **NodeOrdinal** specifies, that the context can run in.

### `Flags`

[in] A [**D3DDDI_CREATECONTEXTFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_createcontextflags) structure that indicates, in bit-field flags, how to create the context.

### `pPrivateDriverData`

[in] A pointer to private data that is passed to a display miniport driver.

### `PrivateDriverDataSize`

[in] The size, in bytes, of the private data that **pPrivateDriverData** points to.

### `ClientHint`

[in] A hint describing which graphics subsystem is creating the context.

### `hContext`

[out] A handle to the created device context.

## See also

[**D3DDDI_CREATECONTEXTFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_createcontextflags)

[**D3DKMTCreateContextVirtual**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatecontextvirtual)