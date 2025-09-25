# ID3D11Device::CreateQuery

## Description

This interface encapsulates methods for querying information from the GPU.

## Parameters

### `pQueryDesc` [in]

Type: **const [D3D11_QUERY_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_query_desc)***

Pointer to a query description (see [D3D11_QUERY_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_query_desc)).

### `ppQuery` [out, optional]

Type: **[ID3D11Query](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11query)****

Address of a pointer to the query object created (see [ID3D11Query](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11query)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns E_OUTOFMEMORY if there is insufficient memory to create the query object.
See [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues) for other possible return values.

## See also

[ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device)