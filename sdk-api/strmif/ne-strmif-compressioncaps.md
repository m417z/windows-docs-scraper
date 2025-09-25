# CompressionCaps enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Indicates video compression capabilities.

## Constants

### `CompressionCaps_CanQuality:0x1`

Video compressor supports the [IAMVideoCompression::put_Quality](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamvideocompression-put_quality) and [IAMVideoCompression::get_Quality](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamvideocompression-get_quality) methods.

### `CompressionCaps_CanCrunch:0x2`

Video compressor can compress video to a specified data rate. If the compressor has this capability then the output pins media type will contain the data rate in the [VIDEOINFOHEADER](https://learn.microsoft.com/previous-versions/windows/desktop/api/amvideo/ns-amvideo-videoinfoheader) structure's **dwBitRate** member. The only way to set the data rate is to set **dwBitRate**.

### `CompressionCaps_CanKeyFrame:0x4`

Video compressor supports the [IAMVideoCompression::put_KeyFrameRate](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamvideocompression-put_keyframerate) and [IAMVideoCompression::get_KeyFrameRate](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamvideocompression-get_keyframerate) methods.

### `CompressionCaps_CanBFrame:0x8`

Video compressor supports the [IAMVideoCompression::put_PFramesPerKeyFrame](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamvideocompression-put_pframesperkeyframe) and [IAMVideoCompression::get_PFramesPerKeyFrame](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamvideocompression-get_pframesperkeyframe) methods.

### `CompressionCaps_CanWindow:0x10`

Video compressor supports the [IAMVideoCompression::put_WindowSize](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamvideocompression-put_windowsize) and [IAMVideoCompression::get_WindowSize](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamvideocompression-get_windowsize) methods.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IAMVideoCompression Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamvideocompression)