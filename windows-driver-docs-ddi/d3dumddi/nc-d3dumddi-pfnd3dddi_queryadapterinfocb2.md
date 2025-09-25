# PFND3DDDI_QUERYADAPTERINFOCB2 callback function

## Description

A user-mode display driver (UMD) can call the Direct3D runtime's **pfnQueryAdapterInfoCb2** callback to retrieve information about the adapter.

## Parameters

### `hAdapter`

[in] A handle to the graphics adapter object.

### `unnamedParam2`

[in/out] Pointer to a [**D3DDDICB_QUERYADAPTERINFO2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_queryadapterinfo2) structure that receives information about the graphics hardware.

## Return value

**pfnQueryAdapterInfoCb2** returns S_OK if it successfully retrieves the information. Otherwise, it returns an error code such as the following:

| Error code | Description |
|--|--|
| E_INVALIDARG | Parameters were validated and determined to be incorrect.|

## See also

[**D3DDDI_ADAPTERCALLBACKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_adaptercallbacks)