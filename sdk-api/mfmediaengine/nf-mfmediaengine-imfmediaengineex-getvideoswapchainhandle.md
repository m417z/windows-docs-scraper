# IMFMediaEngineEx::GetVideoSwapchainHandle

## Description

Gets a handle to the windowless swap chain.

## Parameters

### `phSwapchain` [out]

Receives a handle to the swap chain.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To enable windowless swap-chain mode, call [IMFMediaEngineEx::EnableWindowlessSwapchainMode](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengineex-enablewindowlessswapchainmode).

## See also

[IMFMediaEngineEx](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineex)