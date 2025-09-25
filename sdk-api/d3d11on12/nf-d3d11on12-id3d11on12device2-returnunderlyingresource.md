## Description

With this method, you can return a Direct3D 11 resource object to Direct3D11On12, and indicate (by way of fences and fence signal values) when the resource will be ready for Direct3D11On12 to consume. You should call **ReturnUnderlyingResource** once Direct3D 12 work has been scheduled.

## Parameters

### `pResource11` [in]

Type: **[ID3D11Resource](https://learn.microsoft.com/windows/win32/api/d3d11/nn-d3d11-id3d11resource)\***

The Direct3D 11 resource object that you wish to return.

### `NumSync` [in]

Type: **[UINT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of elements in the arrays pointed to by *pSignalValues* and *ppFences*.

### `pSignalValues` [in]

Type: **[UINT64](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

A pointer to an array of fence signal values.

### `ppFences` [in]

Type: **[ID3D12Fence](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12fence)\*\***

A pointer to an array of fence objects.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/desktop/com/com-error-codes-10).

## Remarks

When you return a resource, you provide a set of fences and fence signal values whose completion indicates that the resource is back in the **D3D12_RESOURCE_STATE_COMMON** state, and ready for Direct3D11On12 to consume it.

In the parallel arrays *pSignalValues* and *ppFences*, include any pending work against the resource. The Direct3D11On12 translation layer defers the waits for these arguments until work is scheduled against the resource.

## See also

* [ID3D11On12Device2::UnwrapUnderlyingResource](https://learn.microsoft.com/windows/win32/api/d3d11on12/nf-d3d11on12-id3d11on12device2-unwrapunderlyingresource)