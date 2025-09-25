# IFileSourceFilter::Load

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Load` method causes a source filter to load a media file.

## Parameters

### `pszFileName` [in]

Pointer to the name of the file to open.

### `pmt` [in]

Pointer to the media type of the file. This can be **NULL**.

## Return value

Returns an **HRESULT** value.

## Remarks

This method initializes the interface. It is not designed to load multiple files, and any calls to this method after the first call will fail.

For the [File Source (Async)](https://learn.microsoft.com/windows/desktop/DirectShow/file-source--async--filter) filter, *pszFileName* specifies the absolute path name of a local file. For the [File Source (URL)](https://learn.microsoft.com/windows/desktop/DirectShow/file-source--url--filter) filter, *pszFileName* specifies the URL of a file to download. For other filter implementations, *pszFileName* might require a file name or a URL, depending on the filter.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFileSourceFilter Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifilesourcefilter)