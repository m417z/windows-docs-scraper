# ID3D11Device1::CreateDeferredContext1

## Description

Creates a deferred context, which can record command lists.

## Parameters

### `ContextFlags`

Reserved for future use.
Pass 0.

### `ppDeferredContext` [out, optional]

Upon completion of the method, the passed pointer to an [ID3D11DeviceContext1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11devicecontext1) interface pointer is initialized.

## Return value

Returns S_OK if successful; otherwise, returns one of the following:

* Returns **DXGI_ERROR_DEVICE_REMOVED** if the graphics adapter has been physically removed from the computer or a driver upgrade for the graphics adapter has occurred.
  If this error occurs, you should destroy and re-create the device.
* Returns **DXGI_ERROR_INVALID_CALL** if the **CreateDeferredContext1** method cannot be called from the current context.
  For example, if the device was created with the [D3D11_CREATE_DEVICE_SINGLETHREADED](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_create_device_flag) value, **CreateDeferredContext1** returns **DXGI_ERROR_INVALID_CALL**.
* Returns **E_INVALIDARG** if the *ContextFlags* parameter is invalid.
* Returns **E_OUTOFMEMORY** if the application has exhausted available memory.

## Remarks

A deferred context is a thread-safe context that you can use to record graphics commands on a thread other than the main rendering thread.
By using a deferred context, you can record graphics commands into a command list that is encapsulated by the [ID3D11CommandList](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11commandlist) interface.
After you record all scene items, you can then submit them to the main render thread for final rendering.
In this manner, you can perform rendering tasks concurrently across multiple threads and potentially improve performance in multi-core CPU scenarios.

You can create multiple deferred contexts.

**Note** If you use the [D3D11_CREATE_DEVICE_SINGLETHREADED](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_create_device_flag) value to create the device that is represented by [ID3D11Device1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11device1), the **CreateDeferredContext1** method will fail, and you will not be able to create a deferred context.

For more information about deferred contexts, see [Immediate and Deferred Rendering](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-render-multi-thread-render).

**Windows Phone 8:** This API is supported.

## See also

[ID3D11Device1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11device1)

[ID3D11Device2::CreateDeferredContext2](https://learn.microsoft.com/windows/desktop/api/d3d11_2/nf-d3d11_2-id3d11device2-createdeferredcontext2)

[ID3D11Device3::CreateDeferredContext3](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nf-d3d11_3-id3d11device3-createdeferredcontext3)

[ID3D11Device::CreateDeferredContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createdeferredcontext)