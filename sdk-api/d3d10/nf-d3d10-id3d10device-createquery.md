# ID3D10Device::CreateQuery

## Description

This interface encapsulates methods for querying information from the GPU.

## Parameters

### `pQueryDesc` [in]

Type: **const [D3D10_QUERY_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_query_desc)***

Pointer to a query description (see [D3D10_QUERY_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_query_desc)).

### `ppQuery` [out]

Type: **[ID3D10Query](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10query)****

Address of a pointer to the query object created (see [ID3D10Query Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10query)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)