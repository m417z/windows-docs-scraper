# IMFMediaEngineEx::FrameStep

## Description

Steps forward or backward one frame.

## Parameters

### `Forward` [in]

Specify **TRUE** to step forward or **FALSE** to step backward.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The frame-step direction is independent of the current playback direction.

This method completes asynchronously. When the operation completes, the Media Engine sends an **MF_MEDIA_ENGINE_EVENT_FRAMESTEPCOMPLETED** event and enters the paused state.

## See also

[IMFMediaEngineEx](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineex)