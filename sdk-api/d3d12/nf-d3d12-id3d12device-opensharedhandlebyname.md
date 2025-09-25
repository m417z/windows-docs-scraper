# ID3D12Device::OpenSharedHandleByName

## Description

Opens a handle for shared resources, shared heaps, and shared fences, by using Name and Access.

## Parameters

### `Name` [in]

Type: **LPCWSTR**

The name that was optionally passed as the *Name* parameter in the call to
[ID3D12Device::CreateSharedHandle](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createsharedhandle).

### `Access`

Type: **DWORD**

The access level that was specified in the *Access* parameter in the call to
[ID3D12Device::CreateSharedHandle](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createsharedhandle).

### `pNTHandle` [out]

Type: **HANDLE***

Pointer to the shared handle.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## See also

[ID3D12Device](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device)