## Description

Unwraps a Direct3D 11 resource object, and retrieves it as a Direct3D 12 resource object.

## Parameters

### `pResource11` [in]

Type: **[ID3D11Resource](https://learn.microsoft.com/windows/win32/api/d3d11/nn-d3d11-id3d11resource)\***

The Direct3D 11 resource object to unwrap.

### `pCommandQueue` [in]

Type: **[ID3D12CommandQueue](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12commandqueue)\***

The command queue on which your application plans to use the resource. Any pending work accessing the resource causes fence waits to be scheduled on this queue. You can then queue further work on this queue, including a signal on a caller-owned fence.

### `riid` [in]

Type: **REFIID**

A reference to the globally unique identifier (GUID) of the interface that you wish to be returned in `ppvResource12`.

### `ppvResource12` [out]

Type: **[void](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)\*\***

A pointer to a memory block that receives a pointer to the Direct3D 12 resource.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/desktop/com/com-error-codes-10).

## Remarks

The resource is transitioned to **D3D12_RESOURCE_STATE_COMMON** (if it wasn't already in that state), and appropriate waits are inserted into the command queue (*pCommandQueue*).

There are some restrictions on what can be unwrapped: no keyed mutex resources, no GDI-compatible resources, and no buffers. However, you can use **UnwrapUnderlyingResource** to unwrap resources created through the **[ID3D11On12Device::CreateWrappedResource](https://learn.microsoft.com/windows/win32/api/d3d11on12/nf-d3d11on12-id3d11on12device-createwrappedresource)** method, as well as resources created through [ID3D11Device::CreateTexture2D](https://learn.microsoft.com/windows/win32/api/d3d11/nf-d3d11-id3d11device-createtexture2d).

In general, you must return the object to Direct3D11on12 before using it again in Direct3D 11 (see [ID3D11On12Device2::ReturnUnderlyingResource](https://learn.microsoft.com/windows/win32/api/d3d11on12/nf-d3d11on12-id3d11on12device2-returnunderlyingresource)).

You can also use **UnwrapUnderlyingResource** to unwrap a swapchain buffer. You must also return the resource to Direct3D11on12 before calling **Present** (or otherwise using the resource).

Unwrapping a resource checks out the resource from the Direct3D11On12 translation layer. You may not schedule any translation layer usage (through either version of the API) while the resource is checked out. Check the resource back in (also known as *returning* the resource) with [ID3D11On12Device2::ReturnUnderlyingResource](https://learn.microsoft.com/windows/win32/api/d3d11on12/nf-d3d11on12-id3d11on12device2-returnunderlyingresource).

**UnwrapUnderlyingResource** doesn't flush, and it may schedule GPU work. You should flush after calling **UnwrapUnderlyingResource** if you externally wait for completion.

## See also

* [ID3D12Device interface](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device)
* [ID3D11On12Device2::ReturnUnderlyingResource](https://learn.microsoft.com/windows/win32/api/d3d11on12/nf-d3d11on12-id3d11on12device2-returnunderlyingresource)