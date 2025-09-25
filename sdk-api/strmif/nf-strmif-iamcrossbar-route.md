# IAMCrossbar::Route

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Route` method routes an input pin to an output pin.

## Parameters

### `OutputPinIndex` [in]

Specifies the index of the output pin.

### `InputPinIndex` [in]

Specifies the index of the input pin.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | Cannot route these two pins. |
| **S_OK** | Success. |

## Remarks

Routing two pins causes the output pin to deliver data from that input pin. Only one input pin at a time can be routed to a given output pin.

Output pins and input pins are both indexed from zero. To determine the number of output and input pins, call the [IAMCrossbar::get_PinCounts](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamcrossbar-get_pincounts) method.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMCrossbar Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamcrossbar)

[Working with Crossbars](https://learn.microsoft.com/windows/desktop/DirectShow/working-with-crossbars)