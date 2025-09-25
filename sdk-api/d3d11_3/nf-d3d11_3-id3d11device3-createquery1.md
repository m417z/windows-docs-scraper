# ID3D11Device3::CreateQuery1

## Description

Creates a query object for querying information from the graphics processing unit (GPU).

## Parameters

### `pQueryDesc1` [in]

Type: **const [D3D11_QUERY_DESC1](https://learn.microsoft.com/windows/desktop/api/d3d11_3/ns-d3d11_3-cd3d11_query_desc1)***

Pointer to a [D3D11_QUERY_DESC1](https://learn.microsoft.com/windows/desktop/api/d3d11_3/ns-d3d11_3-cd3d11_query_desc1) structure that represents a query description.

### `ppQuery1` [out, optional]

Type: **[ID3D11Query1](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nn-d3d11_3-id3d11query1)****

A pointer to a memory block that receives a pointer to a [ID3D11Query1](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nn-d3d11_3-id3d11query1) interface for the created query object. Set this parameter to **NULL** to validate the other input parameters (the method will return **S_FALSE** if the other input parameters pass validation).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns E_OUTOFMEMORY if there is insufficient memory to create the query object.
See [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues) for other possible return values.

## See also

[ID3D11Device3](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nn-d3d11_3-id3d11device3)