# D3DDDI_QUERYADAPTERTYPE enumeration

## Description

The **D3DDDI_QUERYADAPTERTYPE** enumeration specifies the type of query for [**pfnQueryAdapterInfoCb2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryadapterinfocb2).

## Constants

### `D3DDDI_QUERYADAPTERTYPE_DRIVERPRIVATE`

Query the driver's private data.

### `D3DDDI_QUERYADAPTERTYPE_QUERYREGISTRY`

Query for information stored in the registry.

### `D3DDDI_QUERYADAPTERTYPE_APPLICATIONSPECIFICDRIVERBLOB`

Query for an application-specific driver blob.

## See also

[**D3DDDICB_QUERYADAPTERINFO2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_queryadapterinfo2)

[**pfnQueryAdapterInfoCb2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryadapterinfocb2)