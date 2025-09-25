# ID3D11Device::CreatePredicate

## Description

Creates a predicate.

## Parameters

### `pPredicateDesc` [in]

Type: **const [D3D11_QUERY_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_query_desc)***

Pointer to a query description where the type of query must be a D3D11_QUERY_SO_OVERFLOW_PREDICATE or D3D11_QUERY_OCCLUSION_PREDICATE (see [D3D11_QUERY_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_query_desc)).

### `ppPredicate` [out, optional]

Type: **[ID3D11Predicate](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11predicate)****

Address of a pointer to a predicate (see [ID3D11Predicate](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11predicate)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## See also

[ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device)