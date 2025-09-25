# IWMWriterPreprocess::SetNumPreprocessingPasses

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetNumPreprocessingPasses** method sets the number of passes to perform on an input.

## Parameters

### `dwInputNum` [in]

**DWORD** containing the input number for which you want to set the number of passes.

### `dwFlags` [in]

Reserved. Set to zero.

### `dwNumPasses` [in]

**DWORD** containing the number of preprocessing passes.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *dwNumPasses* is zero.<br><br>OR<br><br>*dwInputNum* specifies an invalid input stream.<br><br>OR<br><br>*dwNumPasses* is greater than the maximum number of passes allowed for the specified input. |
| **NS_E_INVALID_REQUEST** | The writer is not running.<br><br>OR<br><br>The preprocessor has already been configured. |

## See also

[IWMWriterPreprocess Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriterpreprocess)