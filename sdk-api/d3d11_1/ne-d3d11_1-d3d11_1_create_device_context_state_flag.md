# D3D11_1_CREATE_DEVICE_CONTEXT_STATE_FLAG enumeration

## Description

Describes flags that are used to create a device context state object ([ID3DDeviceContextState](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3ddevicecontextstate)) with the [ID3D11Device1::CreateDeviceContextState](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11device1-createdevicecontextstate) method.

## Constants

### `D3D11_1_CREATE_DEVICE_CONTEXT_STATE_SINGLETHREADED:0x1`

You use this flag if your application will only call methods of Direct3D 11 and Direct3D 10 interfaces from a single thread. By default, Direct3D 11 and Direct3D 10 are [thread-safe](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-render-multi-thread-differences).
By using this flag, you can increase performance. However, if you use this flag and your application calls methods from multiple threads, undefined behavior might result.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-enums)

[ID3D11Device1::CreateDeviceContextState](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11device1-createdevicecontextstate)