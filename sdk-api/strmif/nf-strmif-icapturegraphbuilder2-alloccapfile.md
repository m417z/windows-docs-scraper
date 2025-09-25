# ICaptureGraphBuilder2::AllocCapFile

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `AllocCapFile` method preallocates a capture file to a specified size. For best results, always capture to a defragmented, preallocated capture file that is larger than the size of the capture data.

## Parameters

### `lpstr` [in]

Pointer to a wide-character string that contains the name of the file to create or resize.

### `dwlSize` [in]

Size of the file to allocate, in bytes.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method fails if the file is read-only.

It is best to allocate as much space as possible—ideally, more than needed. However, this can result in a very large file that contains relatively little data. For example, a 1-gigabyte (GB) capture file might contain a few megabytes of captured video. Use the [ICaptureGraphBuilder2::CopyCaptureFile](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-icapturegraphbuilder2-copycapturefile) method to copy the data into a new file. That method copies only the data and ignores the empty portion of the original file.

If you use this method to preallocate the file, call [IFileSinkFilter2::SetMode](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ifilesinkfilter2-setmode) on the file-writer filter with the value zero. If the filter is set to AM_FILE_OVERWRITE, it will delete the preallocated file. Note that some file-writer filters do not support mode 0.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[ICaptureGraphBuilder2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icapturegraphbuilder2)