# ID3D11Device2::CreateDeferredContext2

## Description

Creates a deferred context, which can record [command lists](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-render-multi-thread-command-list).

## Parameters

### `ContextFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Reserved for future use.
Pass 0.

### `ppDeferredContext` [out, optional]

Type: **[ID3D11DeviceContext2](https://learn.microsoft.com/windows/desktop/api/d3d11_2/nn-d3d11_2-id3d11devicecontext2)****

Upon completion of the method, the passed pointer to an [ID3D11DeviceContext2](https://learn.microsoft.com/windows/desktop/api/d3d11_2/nn-d3d11_2-id3d11devicecontext2) interface pointer is initialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; otherwise, returns one of the following:

* Returns **DXGI_ERROR_DEVICE_REMOVED** if the video card has been physically removed from the system, or a driver upgrade for the video card has occurred.
  If this error occurs, you should destroy and recreate the device.
* Returns **DXGI_ERROR_INVALID_CALL** if the **CreateDeferredContext2** method can't be called from the current context.
  For example, if the device was created with the [D3D11_CREATE_DEVICE_SINGLETHREADED](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_create_device_flag) value, **CreateDeferredContext2** returns **DXGI_ERROR_INVALID_CALL**.
* Returns **E_INVALIDARG** if the *ContextFlags* parameter is invalid.
* Returns **E_OUTOFMEMORY** if the app has exhausted available memory.

## Remarks

A deferred context is a thread-safe context that you can use to record graphics commands on a thread other than the main rendering thread.
By using a deferred context, you can record graphics commands into a command list that is encapsulated by the [ID3D11CommandList](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11commandlist) interface.
After you record all scene items, you can then submit them to the main render thread for final rendering.
In this manner, you can perform rendering tasks concurrently across multiple threads and potentially improve performance in multi-core CPU scenarios.

You can create multiple deferred contexts.

**Note** If you use the [D3D11_CREATE_DEVICE_SINGLETHREADED](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_create_device_flag) value to create the device,
**CreateDeferredContext2** fails with **DXGI_ERROR_INVALID_CALL**, and you can't create a deferred context.

For more information about deferred contexts, see [Immediate and Deferred Rendering](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-render-multi-thread-render).

## See also

[ID3D11Device1::CreateDeferredContext1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11device1-createdeferredcontext1)

[ID3D11Device2](https://learn.microsoft.com/windows/desktop/api/d3d11_2/nn-d3d11_2-id3d11device2)

[ID3D11Device3::CreateDeferredContext3](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nf-d3d11_3-id3d11device3-createdeferredcontext3)

[ID3D11Device::CreateDeferredContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createdeferredcontext)