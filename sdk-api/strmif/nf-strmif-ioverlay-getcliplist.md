# IOverlay::GetClipList

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetClipList` method retrieves the clipping list.

## Parameters

### `pSourceRect` [out]

Pointer to the bounding client rectangle.

### `pDestinationRect` [in]

Pointer to the destination rectangle.

### `ppRgnData` [out]

Address of a pointer to the header and data describing clipping. If successful, free the allocated memory by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Return value

Returns S_OK if successful. If the method fails, it returns an **HRESULT** error code.

## Remarks

The [IOverlay](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ioverlay) implementation allocates the memory for the clipping rectangles, because it can vary in length. The filter calling this method should free the memory (using **CoTaskMemFree**) when it is finished with it.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IOverlay Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ioverlay)