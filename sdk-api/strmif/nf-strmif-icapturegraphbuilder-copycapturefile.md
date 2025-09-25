# ICaptureGraphBuilder::CopyCaptureFile

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** The **ICaptureGraphBuilder** interface is deprecated. Use [ICaptureGraphBuilder2](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icapturegraphbuilder2) instead.

Copies the valid media data from the preallocated capture file.

## Parameters

### `lpwstrOld` [in]

Pointer to a Unicode™ string containing the source file name.

### `lpwstrNew` [in]

Pointer to a Unicode string containing the destination file name. Valid data is copied to this file.

### `fAllowEscAbort` [in]

Value indicating whether pressing the ESC key will cancel the copy operation. **TRUE** indicates that it will; **FALSE** indicates that this method will ignore that keystroke.

### `pCallback` [in]

Optional pointer to an [IAMCopyCaptureFileProgress](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamcopycapturefileprogress) show the progress (percentage complete) of the copy operation.

## Return value

Returns an **HRESULT** value.

## Remarks

The new file will contain only valid data and therefore can be much shorter than the source file. Typically, you will always capture to the same huge preallocated file and use this method to copy the data you want to save from each capture to a new file.

If you specify *pCallback*, the [Progress](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamcopycapturefileprogress-progress) method on the [IAMCopyCaptureFileProgress](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamcopycapturefileprogress) interface will be called periodically with an integer between 0 and 100 representing the percentage complete.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[ICaptureGraphBuilder Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icapturegraphbuilder)