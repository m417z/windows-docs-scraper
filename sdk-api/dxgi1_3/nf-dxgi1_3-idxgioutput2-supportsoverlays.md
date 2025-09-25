# IDXGIOutput2::SupportsOverlays

## Description

Queries an adapter output for multiplane overlay support. If this API returns ‘TRUE’, multiple swap chain composition takes place in a performant manner using overlay hardware. If this API returns false, apps should avoid using foreground swap chains (that is, avoid using swap chains created with the [DXGI_SWAP_CHAIN_FLAG_FOREGROUND_LAYER](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_chain_flag) flag).

## Return value

TRUE if the output adapter is the primary adapter and it supports multiplane overlays, otherwise returns FALSE.

## Remarks

See [CreateSwapChainForCoreWindow](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforcorewindow) for info on creating a foreground swap chain.

## See also

[IDXGIOutput2](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nn-dxgi1_3-idxgioutput2)