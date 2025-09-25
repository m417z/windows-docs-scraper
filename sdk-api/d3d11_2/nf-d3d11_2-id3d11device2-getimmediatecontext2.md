# ID3D11Device2::GetImmediateContext2

## Description

Gets an immediate context, which can play back [command lists](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-render-multi-thread-command-list).

## Parameters

### `ppImmediateContext` [out]

Type: **[ID3D11DeviceContext2](https://learn.microsoft.com/windows/desktop/api/d3d11_2/nn-d3d11_2-id3d11devicecontext2)****

Upon completion of the method, the passed pointer to an [ID3D11DeviceContext2](https://learn.microsoft.com/windows/desktop/api/d3d11_2/nn-d3d11_2-id3d11devicecontext2) interface pointer is initialized.

## Remarks

The **GetImmediateContext2** method returns an [ID3D11DeviceContext2](https://learn.microsoft.com/windows/desktop/api/d3d11_2/nn-d3d11_2-id3d11devicecontext2) object that represents an immediate context, which is used to perform rendering that you want immediately submitted to a device. For most apps, an immediate context is the primary object that is used to draw your scene.

The **GetImmediateContext2** method increments the reference count of the immediate context by one. Therefore, you must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the returned interface pointer when you are done with it to avoid a memory leak.

## See also

[ID3D11Device2](https://learn.microsoft.com/windows/desktop/api/d3d11_2/nn-d3d11_2-id3d11device2)