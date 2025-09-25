# IMFPMediaItem::SetStreamSink

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Sets a media sink for the media item. A *media sink* is an object that consumes the data from one or more streams.

## Parameters

### `dwStreamIndex` [in]

Zero-based index of a stream on the media source. The media sink will receive the data from this stream.

### `pMediaSink` [in]

**IUnknown** pointer that specifies the media sink. Pass in one of the following:

* A pointer to a stream sink. Every media sink contains one or more *stream sinks*. Each stream sink receives the data from one stream. The stream sink must expose the [IMFStreamSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfstreamsink) interface.
* A pointer to an activation object that creates the media sink. The activation object must expose the [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) interface. The media item uses the first stream sink on the media sink (that is, the stream sink at index 0).
* **NULL**. If you set *pMediaSink* to **NULL**, the default media sink for the stream type is used.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

By default, the MFPlay player object renders audio streams to the [Streaming Audio Renderer](https://learn.microsoft.com/windows/desktop/medfound/streaming-audio-renderer) (SAR) and video streams to the [Enhanced Video Renderer](https://learn.microsoft.com/windows/desktop/medfound/enhanced-video-renderer) (EVR). You can use the **SetStreamSink** method to provide a different media sink for an audio or video stream; or to support other stream types besides audio and video. You can also use it to configure the SAR or EVR before they are used.

Call this method before calling [IMFPMediaPlayer::SetMediaItem](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-setmediaitem). Calling this method after **SetMediaItem** has no effect, unless you stop playback and call **SetMediaItem** again.

To reset the media item to use the default media sink, set *pMediaSink* to **NULL**.

### Remote Playback Optimizations

If the application is running over Remote Desktop, and you call this method with a non-NULL value for an audio or video stream, MFPlay disables remote playback optimizations. This remark applies only to audio and video streams. It does not apply to streams that contain some other data type, such as text.

## See also

[IMFPMediaItem](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaitem)

[Media Sinks](https://learn.microsoft.com/windows/desktop/medfound/media-sinks)

[Using MFPlay for Audio/Video Playback](https://learn.microsoft.com/windows/desktop/medfound/using-mfplay-for-audio-video-playback)