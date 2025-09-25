# ID3D11Device::GetImmediateContext

## Description

Gets an immediate context, which can play back command lists.

## Parameters

### `ppImmediateContext` [out]

Type: **[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)****

Upon completion of the method, the passed pointer to an [ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext) interface pointer is initialized.

## Remarks

The **GetImmediateContext** method returns an [ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext) object that represents an immediate context which is used to perform rendering that you want immediately submitted to a device. For most applications, an immediate context is the primary object that is used to draw your scene.

The **GetImmediateContext** method increments the reference count of the immediate context by one. Therefore, you must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the returned interface pointer when you are done with it to avoid a memory leak.

## See also

[ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device)