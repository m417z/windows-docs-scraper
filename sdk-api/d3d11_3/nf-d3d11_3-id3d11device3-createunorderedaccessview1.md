# ID3D11Device3::CreateUnorderedAccessView1

## Description

Creates a view for accessing an [unordered access](https://learn.microsoft.com/windows/desktop/direct3d11/direct3d-11-advanced-stages-cs-resources) resource.

## Parameters

### `pResource` [in]

Type: **[ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)***

Pointer to an [ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource) that represents a resources that will serve as an input to a shader.

### `pDesc1` [in, optional]

Type: **const [D3D11_UNORDERED_ACCESS_VIEW_DESC1](https://learn.microsoft.com/windows/desktop/api/d3d11_3/ns-d3d11_3-cd3d11_unordered_access_view_desc1)***

Pointer to a [D3D11_UNORDERED_ACCESS_VIEW_DESC1](https://learn.microsoft.com/windows/desktop/api/d3d11_3/ns-d3d11_3-cd3d11_unordered_access_view_desc1) structure that represents an unordered-access view description. Set this parameter to **NULL** to create a view that accesses the entire resource (using the format the resource was created with).

### `ppUAView1` [out, optional]

Type: **[ID3D11UnorderedAccessView1](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nn-d3d11_3-id3d11unorderedaccessview1)****

A pointer to a memory block that receives a pointer to a [ID3D11UnorderedAccessView1](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nn-d3d11_3-id3d11unorderedaccessview1) interface for the created unordered-access view. Set this parameter to **NULL** to validate the other input parameters (the method will return **S_FALSE** if the other input parameters pass validation).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns E_OUTOFMEMORY if there is insufficient memory to create the unordered-access view. See [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues) for other possible return values.

## See also

[ID3D11Device3](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nn-d3d11_3-id3d11device3)