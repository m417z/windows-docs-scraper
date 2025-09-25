# IConfigAsfWriter::SetIndexMode

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetIndexMode` method controls whether the WM ASF Writer filter creates a file with a temporal index.

## Parameters

### `bIndexFile` [in]

Specifies the index mode. If **TRUE**, the file will be indexed.

## Return value

Returns S_OK if successful, or an **HRESULT** error code otherwise.

## Remarks

By default, the WM ASF Writer filter creates temporally indexed ASF files. It performs the indexing when the graph stops. You can disable this behavior if you want to do your own frame-based indexing as a post-processing step. To create a frame-indexed file, call `SetIndexMode` with the value **FALSE**, create the file, and then use the Windows Media Format SDK methods to create a frame-based index for the file.

## See also

[Creating ASF Files in DirectShow](https://learn.microsoft.com/windows/desktop/DirectShow/creating-asf-files-in-directshow)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IConfigAsfWriter Interface](https://learn.microsoft.com/windows/desktop/api/dshowasf/nn-dshowasf-iconfigasfwriter)