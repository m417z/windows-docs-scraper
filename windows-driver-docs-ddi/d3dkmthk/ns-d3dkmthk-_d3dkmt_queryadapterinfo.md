# D3DKMT_QUERYADAPTERINFO structure

## Description

The **D3DKMT_QUERYADAPTERINFO** structure retrieves various information that describes the adapter.

## Members

### `hAdapter`

[in] A handle to the adapter that information is retrieved about.

### `Type`

[in] A [**KMTQUERYADAPTERINFOTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_kmtqueryadapterinfotype) enumeration value that indicates the type of information to retrieve.

### `pPrivateDriverData`

[in/out] Pointer to a memory region that is interpreted based on the value of **Type**.

### `PrivateDriverDataSize`

[in/out] The size, in bytes, of the buffer that **pPrivateDriverData** points to.

## See also

[**KMTQUERYADAPTERINFOTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_kmtqueryadapterinfotype)

[**D3DKMTQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryadapterinfo)

[**PFND3DKMT_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nc-d3dkmthk-pfnd3dkmt_queryadapterinfo)