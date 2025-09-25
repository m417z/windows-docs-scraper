# IAMCrossbar::get_PinCounts

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_PinCounts` method retrieves the number of input and output pins on the crossbar filter.

## Parameters

### `OutputPinCount` [out]

Pointer to variable that receives the number of output pins.

### `InputPinCount` [out]

Pointer to variable that receives the number of input pins.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | **NULL** pointer argument. |

## Remarks

The other [IAMCrossbar](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamcrossbar) methods take parameters that specify pins by index number. For these methods, output pins and input pins are both indexed from zero. Use the `get_PinCounts` method to determine the upper bounds for each.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMCrossbar Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamcrossbar)

[Working with Crossbars](https://learn.microsoft.com/windows/desktop/DirectShow/working-with-crossbars)