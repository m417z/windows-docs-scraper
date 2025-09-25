# _DD_GETD3DQUERYDATA structure

## Description

 DirectX 9.0 and later versions only.

DD_GETD3DQUERYDATA is the data structure pointed to by the **lpvData** field of [DD_GETDRIVERINFODATA](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_getdriverinfodata) for DD_GETDRIVERINFO2DATA queries with the type D3DGDI2_TYPE_GETD3DQUERY.

## Members

### `gdi2`

Specifies a [DD_GETDRIVERINFO2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_dd_getdriverinfo2data) structure that contains the **GetDriverInfo2** data.

### `dwQueryIndex`

Specifies the index of the query type to return.

### `QueryType`

Receives a value from the D3DQUERYTYPE enumeration that specifies the actual query capability.

## Remarks

The runtime identifies the query type to be returned with an integer index whose value varies between zero and one less than the number of supported query types that were reported earlier by the driver in a D3DGDI2_TYPE_GETD3DQUERYCOUNT query. How these indices are mapped to actual query types is left to the driver. However, each index must map uniquely to one supported query type. The order in which the query types are reported is not significant.

When processing this **GetDriverInfo2** request the driver should read the value in the union as if it were the **dwQueryIndex** member and map that value to one of the supported query types (probably by using the value in **dwQueryIndex** as an index into an array of D3DQUERYTYPE values). The driver should then copy that query type into the union as if it were the **QueryType** member. The runtime guarantees that it only passes an index to the driver that is in the range zero to one less than the number of query types reported by the driver. The range of the index should be validated in the debug driver build.

For more information about D3DQUERYTYPE, see the DirectX SDK documentation.

## See also

D3DDP2OP_CREATEQUERY

[DD_GETD3DQUERYCOUNTDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_dd_getd3dquerycountdata)

[DD_GETDRIVERINFO2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_dd_getdriverinfo2data)

[DD_GETDRIVERINFODATA](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_getdriverinfodata)