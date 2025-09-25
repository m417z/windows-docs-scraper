# ID3D11Device1::GetImmediateContext1

## Description

Gets an immediate context, which can play back command lists.

## Parameters

### `ppImmediateContext` [out]

Upon completion of the method, the passed pointer to an [ID3D11DeviceContext1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11devicecontext1) interface pointer is initialized.

## Remarks

**GetImmediateContext1** returns an [ID3D11DeviceContext1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11devicecontext1) object that represents an immediate context. You can use this immediate context to perform rendering that you want immediately submitted to a device. For most applications, an immediate context is the primary object that is used to draw your scene.

**GetImmediateContext1** increments the reference count of the immediate context by one. So, call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the returned interface pointer when you are done with it to avoid a memory leak.

## See also

[ID3D11Device1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11device1)