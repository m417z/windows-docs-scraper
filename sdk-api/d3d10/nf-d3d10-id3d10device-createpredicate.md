# ID3D10Device::CreatePredicate

## Description

Creates a predicate.

## Parameters

### `pPredicateDesc` [in]

Type: **const [D3D10_QUERY_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_query_desc)***

Pointer to a query description where the type of query must be a D3D10_QUERY_SO_OVERFLOW_PREDICATE or D3D10_QUERY_OCCLUSION_PREDICATE (see [D3D10_QUERY_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_query_desc)).

### `ppPredicate` [out]

Type: **[ID3D10Predicate](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10predicate)****

Address of a pointer to a predicate (see [ID3D10Predicate Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10predicate)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)