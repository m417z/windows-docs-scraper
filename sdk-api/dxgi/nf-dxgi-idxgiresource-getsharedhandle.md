# IDXGIResource::GetSharedHandle

## Description

[Starting with Direct3D 11.1, we recommend not to use **GetSharedHandle** anymore to retrieve the handle to a shared resource. Instead, use [IDXGIResource1::CreateSharedHandle](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgiresource1-createsharedhandle) to get a handle for sharing. To use **IDXGIResource1::CreateSharedHandle**, you must create the resource as shared and specify that it uses NT handles (that is, you set the [D3D11_RESOURCE_MISC_SHARED_NTHANDLE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_resource_misc_flag) flag). We also recommend that you create shared resources that use NT handles so you can use [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle), [DuplicateHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-duplicatehandle), and so on on those shared resources.]

Gets the handle to a shared resource.

## Parameters

### `pSharedHandle` [out]

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to a handle.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) values.

## Remarks

**GetSharedHandle** returns a handle for the resource that you created as shared (that is, you set the [D3D11_RESOURCE_MISC_SHARED](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_resource_misc_flag) with or without the [D3D11_RESOURCE_MISC_SHARED_KEYEDMUTEX](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_resource_misc_flag) flag). You can pass this handle to the [ID3D11Device::OpenSharedResource](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-opensharedresource) method to give another device access to the shared resource. You can also marshal this handle to another process to share a resource with a device in another process. However, this handle is not an NT handle. Therefore, don't use the handle with [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle), [DuplicateHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-duplicatehandle), and so on.

The creator of a shared resource must not destroy the resource until all intended entities have opened the resource. The validity of the handle is tied to the lifetime of the underlying video memory. If no resource objects exist on any devices that refer to this resource, the handle is no longer valid. To extend the lifetime of the handle and video memory, you must open the shared resource on a device.

**GetSharedHandle** can also return handles for resources that were passed into [ID3D11Device::OpenSharedResource](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-opensharedresource) to open those resources.

**GetSharedHandle** fails if the resource to which it wants to get a handle is not shared.

## See also

[IDXGIResource](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiresource)