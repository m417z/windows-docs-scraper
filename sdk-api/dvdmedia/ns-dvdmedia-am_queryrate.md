# AM_QueryRate structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AM_QueryRate** structure is used to query the decoder's maximum full-frame rate for forward and reverse playback.

## Members

### `lMaxForwardFullFrame`

Specifies the maximum forward full-frame rate, as rate x 10000.

### `lMaxReverseFullFrame`

Specifies the maximum reverse full-frame rate, as rate x 10000.

## Remarks

Rate is the inverse of speed. For example, if the playback speed is 2x, the rate is 1/2, so the **Rate** member is set to 5000. Reverse rates are negative.

## See also

[AM_RATE_QueryFullFrameRate Property](https://learn.microsoft.com/windows/desktop/DirectShow/am-rate-queryfullframerate-property)

[Rate Change Property Set](https://learn.microsoft.com/windows/desktop/DirectShow/rate-change-property-set)