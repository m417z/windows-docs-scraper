# ID3D10Device::OMGetDepthStencilState

## Description

Gets the [depth-stencil](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage) state of the output-merger stage.

## Parameters

### `ppDepthStencilState` [out]

Type: **[ID3D10DepthStencilState](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10depthstencilstate)****

Address of a pointer to a depth-stencil state interface (see [ID3D10DepthStencilState](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10depthstencilstate)) to be filled with information from the device.

### `pStencilRef` [out]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to the stencil reference value used in the [depth-stencil](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage) test.

## Remarks

Any returned interfaces will have their reference count incremented by one. Applications should call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the returned interfaces when they are no longer needed to avoid memory leaks.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)