# IDXGIOutput::GetFrameStatistics

## Description

Gets statistics about recently rendered frames.

## Parameters

### `pStats` [out]

Type: **[DXGI_FRAME_STATISTICS](https://learn.microsoft.com/windows/desktop/api/dxgi/ns-dxgi-dxgi_frame_statistics)***

A pointer to frame statistics (see [DXGI_FRAME_STATISTICS](https://learn.microsoft.com/windows/desktop/api/dxgi/ns-dxgi-dxgi_frame_statistics)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this function succeeds, it returns S_OK. Otherwise, it might return [DXGI_ERROR_INVALID_CALL](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

## Remarks

This API is similar to [IDXGISwapChain::GetFrameStatistics](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-getframestatistics).

**Note** Calling this method is only supported while in full-screen mode.

## See also

[IDXGIOutput](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgioutput)