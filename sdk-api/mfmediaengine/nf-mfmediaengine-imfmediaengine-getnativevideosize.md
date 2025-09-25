# IMFMediaEngine::GetNativeVideoSize

## Description

Gets the size of the video frame, adjusted for aspect ratio.

## Parameters

### `cx` [out]

Receives the width in pixels.

### `cy` [out]

Receives the height in pixels.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method adjusts for the correct picture aspect ratio.
For example, if the encoded frame is 720 × 420 and the picture aspect ratio is 4:3, the method will return a size equal to 640 × 480 pixels.

## See also

[IMFMediaEngine](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengine)

[Picture Aspect Ratio](https://learn.microsoft.com/windows/desktop/medfound/picture-aspect-ratio)