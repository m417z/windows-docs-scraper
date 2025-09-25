# IDXGIFactory3::GetCreationFlags

## Description

Gets the flags that were used when a Microsoft DirectX Graphics Infrastructure (DXGI) object was created.

## Return value

The creation flags.

## Remarks

The **GetCreationFlags** method returns flags that were passed to the [CreateDXGIFactory2](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nf-dxgi1_3-createdxgifactory2) function, or were implicitly constructed by [CreateDXGIFactory](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-createdxgifactory), [CreateDXGIFactory1](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-createdxgifactory1), [D3D11CreateDevice](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-d3d11createdevice), or [D3D11CreateDeviceAndSwapChain](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-d3d11createdeviceandswapchain).

## See also

[IDXGIFactory3](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nn-dxgi1_3-idxgifactory3)