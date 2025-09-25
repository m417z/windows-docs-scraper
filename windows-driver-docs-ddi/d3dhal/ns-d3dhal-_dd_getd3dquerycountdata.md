# _DD_GETD3DQUERYCOUNTDATA structure

## Description

 DirectX 9.0 and later versions only.

DD_GETD3DQUERYCOUNTDATA is the data structure pointed to by the **lpvData** field of [DD_GETDRIVERINFODATA](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_getdriverinfodata) for DD_GETDRIVERINFO2DATA queries with the type D3DGDI2_TYPE_GETD3DQUERYCOUNT.

## Members

### `gdi2`

Specifies a [DD_GETDRIVERINFO2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_dd_getdriverinfo2data) structure that contains the **GetDriverInfo2** data for the query.

### `dwNumQueries`

Receives the number of supported query types.

## Remarks

To handle D3DGDI2_TYPE_GETD3DQUERYCOUNT, the driver must store the number of query types that it supports in the **dwNumQueries** member of DD_GETD3DQUERYCOUNTDATA. Query types are represented by values in the D3DQUERYTYPE enumeration.

## See also

D3DDP2OP_CREATEQUERY

[DD_GETD3DQUERYDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_dd_getd3dquerydata)

[DD_GETDRIVERINFO2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_dd_getdriverinfo2data)

[DD_GETDRIVERINFODATA](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_getdriverinfodata)