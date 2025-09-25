# ID3D11Device3::CreateDeferredContext3

## Description

Creates a deferred context, which can record [command lists](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-render-multi-thread-command-list).

## Parameters

### `ContextFlags`

Type: **UINT**

Reserved for future use. Pass 0.

### `ppDeferredContext` [out, optional]

Type: **ID3D11DeviceContext3****

Upon completion of the method, the passed pointer to an [ID3D11DeviceContext3](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nn-d3d11_3-id3d11devicecontext3) interface pointer is initialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; otherwise, returns one of the following:

* Returns **DXGI_ERROR_DEVICE_REMOVED** if the video card has been physically removed from the system, or a driver upgrade for the video card has occurred.
  If this error occurs, you should destroy and recreate the device.
* Returns **DXGI_ERROR_INVALID_CALL** if the
  **CreateDeferredContext3** method can't be called from the current context.
  For example, if the device was created with the [D3D11_CREATE_DEVICE_SINGLETHREADED](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_create_device_flag) value, **CreateDeferredContext3** returns **DXGI_ERROR_INVALID_CALL**.
* Returns **E_INVALIDARG** if the *ContextFlags* parameter is invalid.
* Returns **E_OUTOFMEMORY** if the app has exhausted available memory.

## See also

[ID3D11Device1::CreateDeferredContext1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11device1-createdeferredcontext1)

[ID3D11Device2::CreateDeferredContext2](https://learn.microsoft.com/windows/desktop/api/d3d11_2/nf-d3d11_2-id3d11device2-createdeferredcontext2)

[ID3D11Device3](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nn-d3d11_3-id3d11device3)

[ID3D11Device::CreateDeferredContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createdeferredcontext)