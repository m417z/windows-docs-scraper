# IMFMediaEngineEx::EnableWindowlessSwapchainMode

## Description

Enables or disables windowless swap-chain mode.

## Parameters

### `fEnable` [in]

If **TRUE**, windowless swap-chain mode is enabled.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

In windowless swap-chain mode, the Media Engine creates a windowless swap chain and presents video frames to the swap chain. To render the video, call [IMFMediaEngineEx::GetVideoSwapchainHandle](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengineex-getvideoswapchainhandle) to get a handle to the swap chain, and then associate the handle with a Microsoft DirectComposition visual.

## See also

[IMFMediaEngineEx](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineex)