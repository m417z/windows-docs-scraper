## Description

The **AcquireDirect3D12BufferResourceWithTimeout** method transitions ownership of a Direct3D 12 back buffer resource from the platform to your application, waiting up to the amount of time indicated by the *duration* argument for the resource to become available. If your application already owns control of the resource, then the acquisition is still considered to be a success, and the method returns immediately.

After committing a resource to a [HolographicFrame](https://learn.microsoft.com/uwp/api/windows.graphics.holographic.holographicframe) by calling [IHolographicQuadLayerUpdateParametersInterop::CommitDirect3D12Resource](https://learn.microsoft.com/windows/win32/api/windows.graphics.holographic.interop/nf-windows-graphics-holographic-interop-iholographicquadlayerupdateparametersinterop-commitdirect3d12resource), your application should consider control of that resource to be relinquished to the system until such a time as it is reacquired by your application using **AcquireDirect3D12BufferResourceWithTimeout**. The system owns the buffer until it is no longer needed for presenting the quad layer. To determine whether the system has relinquished control of the buffer, call **AcquireDirect3D12BufferResource** or **AcquireDirect3D12BufferResourceWithTimeout**. If the buffer can't be acquired by the time your application is ready to start rendering a new update for the quad layer, then you should create a new resource and add it to the buffer queue, or limit the queue size by waiting for a buffer to become available.

This method accepts an optional timeout value. When a non-zero value is present in the *duration* argument, the system waits for that many milliseconds for the buffer to become available. The default behavior is to not wait. When a timeout value of zero is specified, and the buffer is not ready to be acquired, the method call fails with the error code **E_NOTREADY**.

## Parameters

### `pResourceToAcquire`

Type: **[ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource)\***

The Direct3D 12 resource to acquire. The resource will be in the **D3D12_RESOURCE_STATE_COMMON** state when it is acquired.

### `pCommandQueue`

Type: **[ID3D12CommandQueue](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12commandqueue)\***

The Direct3D 12 command queue to use for transitioning the state of this resource when acquiring it for your application.

### `duration`

Type: **[UINT64](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

If this parameter is set, the call will wait for that amount of time for the buffer to be acquired. If the timeout period elapses before the buffer can be acquired, the method fails with the error code **E_TIMEOUT**. This parameter is in 100-nanosecond units, similar to the [TimeSpan.Duration](https://learn.microsoft.com/uwp/api/windows.foundation.timespan.duration) field.

## Return value

**S_OK** if successful, otherwise returns an [HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) error code indicating the reason for failure. Also see [COM Error Codes (UI, Audio, DirectX, Codec)](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

When no timeout value is specified, if this method is called and the buffer is not ready to be acquired, the method call will fail with the error code **E_NOTREADY**.

## See also

[AcquireDirect3D12BufferResource](https://learn.microsoft.com/windows/win32/api/windows.graphics.holographic.interop/nf-windows-graphics-holographic-interop-iholographicquadlayerinterop-acquiredirect3d12bufferresource)