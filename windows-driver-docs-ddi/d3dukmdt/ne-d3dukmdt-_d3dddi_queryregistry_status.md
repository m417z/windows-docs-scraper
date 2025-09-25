# D3DDDI_QUERYREGISTRY_STATUS enumeration

## Description

The **D3DDDI_QUERYREGISTRY_STATUS** enumeration contains retrieved status codes via a *QueryAdapterInfo* call for [**KMTQAITYPE_QUERYREGISTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_kmtqueryadapterinfotype).

## Constants

### `D3DDDI_QUERYREGISTRY_STATUS_SUCCESS`

Indicates full success, and *QueryAdapterInfo* succeeded as well.
All **D3DDDI_QUERYREGISTRY_INFO** fields starting with **Output*Xxx*** and the [**D3DDDI_QUERYREGISTRY_INFO::Status**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_queryregistry_info) field are updated by *QueryAdapterInfo*.

### `D3DDDI_QUERYREGISTRY_STATUS_BUFFER_OVERFLOW`

**D3DKMT_QUERYADAPTERINFO::PrivateDriverDataSize** wasn't large enough to retrieve all the requested data.
Only **D3DDDI_QUERYREGISTRY_INFO\::OutputValueSize** is updated by *QueryAdapterInfo*, in addition to the **D3DDDI_QUERYREGISTRY_INFO::Status** field.

### `D3DDDI_QUERYREGISTRY_STATUS_FAIL`

An unspecified error occurred, and *QueryAdapterInfo* failed as well.
All other **D3DDDI_QUERYREGISTRY_INFO** fields are left unmodified upon return from QueryAdapterInfo.
Since **D3DDDI_QUERYREGISTRY_INFO** is a variable-sized struct,
**D3DDDI_QUERYREGISTRY_STATUS_FAIL** will reliably occur when **D3DKMT_QUERYADAPTERINFO::PrivateDriverDataSize** is smaller than the size of **D3DDDI_QUERYREGISTRY_INFO**.

### `D3DDDI_QUERYREGISTRY_STATUS_MAX`

**D3DDDI_QUERYREGISTRY_STATUS_MAX** is invalid to use, and exists only to simplify maintaining the implementation.

## See also

[**D3DDDI_QUERYREGISTRY_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_queryregistry_info)

[**D3DKMT_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryadapterinfo)

[**Pfnd3dddiQueryadapterinfocb2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryadapterinfocb2)