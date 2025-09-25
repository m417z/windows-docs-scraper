# ICaptureGraphBuilder2::CopyCaptureFile

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `CopyCaptureFile` method copies the valid media data from a capture file.

## Parameters

### `lpwstrOld` [in]

Pointer to a wide-character string that contains the source file name.

### `lpwstrNew` [in]

Pointer to a wide-character string that contains the destination file name. Valid data is copied to this file.

### `fAllowEscAbort` [in]

Boolean value that specifies whether pressing the ESC key cancels the copy operation. If the value is **TRUE** and the user presses the ESC key, the operation halts. If the value is **FALSE**, the method ignores the ESC key.

### `pCallback` [in]

Pointer to an [IAMCopyCaptureFileProgress](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamcopycapturefileprogress) interface to display progress information, or **NULL**. See Remarks for more information.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | User canceled the operation before it completed. |
| **S_OK** | Success. |
| **E_FAIL** | Failure. |
| **E_INVALIDARG** | Could not open the source file or destination file. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_POINTER** | **NULL** pointer argument. |

## Remarks

Typically, you will first capture to a large preallocated file. This method copies just the valid data to a new file. As a result, the new file can be much smaller than the original file.

The source and destination files must be AVI files. Other file types are not supported.

To display the progress of the copy operation, implement the [IAMCopyCaptureFileProgress](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamcopycapturefileprogress) interface and pass a pointer to the interface in the *pCallback* parameter. If *pCallback* is non-**NULL**, this method periodically calls the [IAMCopyCaptureFileProgress::Progress](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamcopycapturefileprogress-progress) method with an integer between 0 and 100 that specifies the percentage complete.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[ICaptureGraphBuilder2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icapturegraphbuilder2)