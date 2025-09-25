# ICaptureGraphBuilder::AllocCapFile

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** The **ICaptureGraphBuilder** interface is deprecated. Use [ICaptureGraphBuilder2](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icapturegraphbuilder2) instead.

Preallocates a capture file to a specified size.

## Parameters

### `lpstr` [in]

Pointer to a wide-character string containing the name of the file to create or resize.

### `dwlSize` [in]

Size, in bytes, of the file to be allocated.

## Return value

Returns an **HRESULT** value.

## Remarks

The call will fail if the file is read-only. For best capture results, always capture to a defragmented, preallocated capture file that is larger than the size of the capture data.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[ICaptureGraphBuilder Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icapturegraphbuilder)