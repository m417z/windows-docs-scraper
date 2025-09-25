# IGraphBuilder::SetLogFile

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetLogFile` method sets the file for logging actions taken when attempting to perform an operation.

## Parameters

### `hFile`

Handle to the log file.

## Return value

Returns S_OK.

## Remarks

This method is for use in debugging; it is intended to help you determine the cause of any failure to automatically build a filter graph.

The *hFile* parameter must be an open file handle. Your application is responsible for opening the file and for closing it when you are done logging. Before closing the file handle, call `SetLogFile` with a **NULL** file handle. This will ensure that the component does not attempt to use the file handle after you have closed it.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IGraphBuilder Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-igraphbuilder)