# IWMWriterPreprocess::PreprocessSample

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **PreprocessSample** method delivers a sample to the writer for preprocessing.

## Parameters

### `dwInputNum` [in]

**DWORD** containing the input number of the sample.

### `cnsSampleTime` [in]

Specifies the presentation time of the sample in 100-nanosecond units.

### `dwFlags` [in]

Reserved. Set to zero.

### `pSample` [in]

Pointer to an [INSSBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nn-wmsbuffer-inssbuffer) interface on an object that contains the sample.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *dwInputNum* specifies an invalid input stream.<br><br>OR<br><br>*pSample* is **NULL**. |
| **NS_E_INVALID_REQUEST** | The writer is not running.<br><br>OR<br><br>The preprocessor is neither waiting to be run nor stopped in the middle of a pass.<br><br>OR<br><br>The preprocessor has already made as many passes as specified by [SetNumPreprocessingPasses](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriterpreprocess-setnumpreprocessingpasses).<br><br>OR<br><br>The input specified is not supported for preprocessing. |

## Remarks

When performing preprocessing, you should pass the samples for the stream to this method one at a time.

## See also

[IWMWriterPreprocess Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriterpreprocess)