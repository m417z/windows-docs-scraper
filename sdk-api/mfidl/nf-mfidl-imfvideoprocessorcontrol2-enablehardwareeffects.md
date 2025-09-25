# IMFVideoProcessorControl2::EnableHardwareEffects

## Description

Enables effects that were implemented with [IDirectXVideoProcessor::VideoProcessorBlt](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-videoprocessorblt).

## Parameters

### `fEnabled` [in]

Type: **BOOL**

Specifies whether effects are to be enabled. **TRUE** specifies to enable effects. **FALSE** specifies to disable effects.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFVideoProcessorControl2](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfvideoprocessorcontrol2)