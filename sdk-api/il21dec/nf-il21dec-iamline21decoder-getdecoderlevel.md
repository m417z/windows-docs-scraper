# IAMLine21Decoder::GetDecoderLevel

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetDecoderLevel` method retrieves the closed-captioned decoder level.

## Parameters

### `lpLevel`

Pointer to a variable that receives a member of the [AM_LINE21_CCLEVEL](https://learn.microsoft.com/previous-versions/windows/desktop/api/il21dec/ne-il21dec-am_line21_cclevel) enumeration. The returned value is always **AM_L21_CCLEVEL_TC2** (TeleCaption II).

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument |
| **S_OK** | Success |

## Remarks

TeleCaption I and TeleCaption II are standards for closed caption decoders. The [Line 21 Decoder](https://learn.microsoft.com/windows/desktop/DirectShow/line-21-decoder-filter) filter supports TeleCaption II, which is backward compatible with TeleCaption I.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMLine21Decoder Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/il21dec/nn-il21dec-iamline21decoder)