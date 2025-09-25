# IMFMediaEngine::GetVideoAspectRatio

## Description

Gets the picture aspect ratio of the video stream.

## Parameters

### `cx` [out]

Receives the x component of the aspect ratio.

### `cy` [out]

Receives the y component of the aspect ratio.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The Media Engine automatically converts the pixel aspect ratio to 1:1 (square pixels).

## See also

[IMFMediaEngine](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengine)

[Picture Aspect Ratio](https://learn.microsoft.com/windows/desktop/medfound/picture-aspect-ratio)