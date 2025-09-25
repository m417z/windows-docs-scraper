# ID3D11DeviceContext::OMSetDepthStencilState

## Description

Sets the depth-stencil state of the output-merger stage.

## Parameters

### `pDepthStencilState` [in, optional]

Type: **[ID3D11DepthStencilState](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11depthstencilstate)***

Pointer to a depth-stencil state interface (see [ID3D11DepthStencilState](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11depthstencilstate)) to bind to the device. Set this to **NULL** to use the default state listed in [D3D11_DEPTH_STENCIL_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_depth_stencil_desc).

### `StencilRef` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Reference value to perform against when doing a depth-stencil test. See remarks.

## Remarks

To create a depth-stencil state interface, call [ID3D11Device::CreateDepthStencilState](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createdepthstencilstate).

The method will hold a reference to the interfaces passed in.
This differs from the device state behavior in Direct3D 10.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)