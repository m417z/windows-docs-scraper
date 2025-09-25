# IMFMediaEngine::SetLoop

## Description

Specifies whether the Media Engine loops playback.

## Parameters

### `Loop` [in]

Specify **TRUE** to enable looping, or **FALSE** to disable looping.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If *Loop* is **TRUE**, playback loops back to the beginning when it reaches the end of the source.

This method corresponds to setting the **loop** attribute of the **HTMLMediaElement** interface in HTML5.

## See also

[IMFMediaEngine](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengine)