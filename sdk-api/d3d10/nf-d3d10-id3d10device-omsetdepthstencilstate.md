# ID3D10Device::OMSetDepthStencilState

## Description

Sets the [depth-stencil](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage) state of
the output-merger stage.

## Parameters

### `pDepthStencilState` [in]

Type: **[ID3D10DepthStencilState](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10depthstencilstate)***

Pointer to a depth-stencil state interface (see [ID3D10DepthStencilState](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10depthstencilstate)) to bind to the device.

### `StencilRef` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Reference value to perform against when doing a depth-stencil test. See remarks.

## Remarks

To create a depth-stencil state interface, call [ID3D10Device::CreateDepthStencilState](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-createdepthstencilstate).

Depth-stencil state is used by the [output-merger](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage) stage to
setup depth-stencil testing.
The stencil reference value is the control value used in the depth-stencil test.

The method will not hold a reference to the interfaces passed in. For that reason, applications should be careful not to release an
interface currently in use by the device.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)