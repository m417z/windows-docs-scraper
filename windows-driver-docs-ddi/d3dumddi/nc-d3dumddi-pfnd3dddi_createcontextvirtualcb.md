# PFND3DDDI_CREATECONTEXTVIRTUALCB callback function

## Description

**pfnCreateContextVirtualCb** should be used with contexts that support virtual addressing.

## Parameters

### `hDevice`

A handle to the display device.

### `unnamedParam2`

pData [in, out]

A pointer to a [D3DDDICB_CREATECONTEXTVIRTUAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_createcontextvirtual) structure that describes the context to create.

## Return value

|Return code|Description|
|--- |--- |
|S_OK|The context was successfully created.|
|E_OUTOFMEMORY|Could not allocate memory that was required for the operation to complete.|
|E_INVALIDARG|Parameters were validated and determined to be incorrect.|

This function might also return other **HRESULT** values.