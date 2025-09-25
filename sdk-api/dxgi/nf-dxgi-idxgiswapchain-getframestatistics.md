# IDXGISwapChain::GetFrameStatistics

## Description

Gets performance statistics about the last render frame.

## Parameters

### `pStats` [out]

Type: **[DXGI_FRAME_STATISTICS](https://learn.microsoft.com/windows/desktop/api/dxgi/ns-dxgi-dxgi_frame_statistics)***

A pointer to a [DXGI_FRAME_STATISTICS](https://learn.microsoft.com/windows/desktop/api/dxgi/ns-dxgi-dxgi_frame_statistics) structure for the frame statistics.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) values.

## Remarks

You cannot use **GetFrameStatistics** for swap chains that both use the bit-block transfer (bitblt) presentation model and draw in windowed mode.

You can only use **GetFrameStatistics** for swap chains that either use the flip presentation model or draw in full-screen mode. You set the [DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_effect) value in the **SwapEffect** member of the [DXGI_SWAP_CHAIN_DESC1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_swap_chain_desc1) structure to specify that the swap chain uses the flip presentation model.

Statistics are not reliable in many multiple monitor scenarios, as well as scenarios where other fullscreen apps are running.

It may be necessary to call **DwmFlush** before frame statistics are updated on systems that support Hardware Flip Queue.

## See also

[IDXGISwapChain](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiswapchain)