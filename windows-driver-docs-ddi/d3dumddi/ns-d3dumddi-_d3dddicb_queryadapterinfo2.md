# D3DDDICB_QUERYADAPTERINFO2 structure

## Description

The **D3DDDICB_QUERYADAPTERINFO2** structure describes the graphics adapter.

## Members

### `QueryType` [in]

A [**D3DDDI_QUERYADAPTERTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_d3dddi_queryadaptertype) enumeration value that specifies the type of query.

### `pPrivateDriverData` [out]

A pointer to a buffer that receives the requested information. The format of the information is defined by **QueryType**.

### `PrivateDriverDataSize` [in/out]

The size, in bytes, of the buffer that **pPrivateDriverData** points to.

## See also

[**D3DDDI_QUERYADAPTERTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_d3dddi_queryadaptertype)

[**pfnQueryAdapterInfoCb2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryadapterinfocb2)