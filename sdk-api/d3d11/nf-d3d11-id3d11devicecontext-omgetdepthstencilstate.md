# ID3D11DeviceContext::OMGetDepthStencilState

## Description

Gets the depth-stencil state of the output-merger stage.

## Parameters

### `ppDepthStencilState` [out, optional]

Type: **[ID3D11DepthStencilState](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11depthstencilstate)****

Address of a pointer to a depth-stencil state interface (see [ID3D11DepthStencilState](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11depthstencilstate)) to be filled with information from the device.

### `pStencilRef` [out, optional]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to the stencil reference value used in the depth-stencil test.

## Remarks

Any returned interfaces will have their reference count incremented by one. Applications should call IUnknown::Release on the returned interfaces when they are no longer needed to avoid memory leaks.

**Windows Phone 8:** This API is supported.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)