# IPin::QueryAccept

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `QueryAccept` method determines whether the pin accepts a specified media type.

## Parameters

### `pmt` [in]

Pointer to an [AM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_media_type) structure that specifies the media type.

## Return value

Returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_FALSE** | The pin rejects the media type. |
| **S_OK** | The pin accepts the media type. |

## Remarks

A return value of S_OK indicates that the pin will accept the media type, either on the next sample, or after a pin reconnection. The implementation should take into account the current state of the filter, including connections on other pins, and any properties that can be set on the filter.

Any other return value, including S_FALSE, means that the pin rejects the media type. Therefore, test for S_OK explicitly; do not use the **SUCCEEDED** macro.

If the filter is running, a return value of S_OK is ambiguous. The pin might accept a format change on the next media sample, without reconnecting; or it might need to reconnect. If the pin supports the [IPinConnection](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipinconnection) interface, call the [IPinConnection::DynamicQueryAccept](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipinconnection-dynamicqueryaccept) method, which specifically tests whether the pin can accept the new type without reconnecting.

## See also

[Data Flow in the Filter Graph](https://learn.microsoft.com/windows/desktop/DirectShow/data-flow-in-the-filter-graph)

[Dynamic Format Changes](https://learn.microsoft.com/windows/desktop/DirectShow/dynamic-format-changes)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IPin Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin)