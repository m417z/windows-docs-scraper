# ID3D11Device3::GetImmediateContext3

## Description

Gets an immediate context, which can play back [command lists](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-render-multi-thread-command-list).

## Parameters

### `ppImmediateContext` [out]

Type: **[ID3D11DeviceContext3](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nn-d3d11_3-id3d11devicecontext3)****

Upon completion of the method, the passed pointer to an [ID3D11DeviceContext3](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nn-d3d11_3-id3d11devicecontext3) interface pointer is initialized.

## Remarks

The
**GetImmediateContext3** method outputs an
[ID3D11DeviceContext3](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nn-d3d11_3-id3d11devicecontext3) object that represents an immediate context, which is used to perform rendering that you want immediately submitted to a device.
For most apps, an immediate context is the primary object that is used to draw your scene.

The **GetImmediateContext3** method increments the reference count of the immediate context by one.
Therefore, you must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the returned interface pointer when you are done with it to avoid a memory leak.

## See also

[ID3D11Device1::GetImmediateContext1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11device1-getimmediatecontext1)

[ID3D11Device2::GetImmediateContext2](https://learn.microsoft.com/windows/desktop/api/d3d11_2/nf-d3d11_2-id3d11device2-getimmediatecontext2)

[ID3D11Device3](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nn-d3d11_3-id3d11device3)

[ID3D11Device::GetImmediateContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-getimmediatecontext)