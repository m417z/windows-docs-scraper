# IWiaVideo::ResizeVideo

## Description

The **IWiaVideo::ResizeVideo** method resizes the video playback to the largest supported resolution that fits inside the parent window. Call this method whenever the parent window is moved or resized.

## Parameters

### `bStretchToFitParent` [in]

Type: **BOOL**

Specifies whether the video playback is stretched to fill the parent window.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

By default, the video is displayed in a supported resolution smaller than the parent window. If *bStretchToFitParent* is set to **TRUE**, the video display fills the window.