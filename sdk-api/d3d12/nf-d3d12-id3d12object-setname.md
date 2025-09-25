# ID3D12Object::SetName

## Description

Associates a name with the device object.
This name is for use in debug diagnostics and tools.

## Parameters

### `Name` [in]

Type: **LPCWSTR**

A **NULL**-terminated **UNICODE** string that contains the name to associate with the device object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## Remarks

This method takes UNICODE names.

Note that this is simply a convenience wrapper around [ID3D12Object::SetPrivateData](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12object-setprivatedata) with **WKPDID_D3DDebugObjectNameW**.
Therefore names which are set with `SetName` can be retrieved with [ID3D12Object::GetPrivateData](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12object-getprivatedata) with the same GUID.
Additionally, D3D12 supports narrow strings for names, using the **WKPDID_D3DDebugObjectName** GUID directly instead.

## See also

[Direct3D 12 Programming Environment Setup](https://learn.microsoft.com/windows/desktop/direct3d12/directx-12-programming-environment-set-up)

[ID3D12Object](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12object)