# IWMWriterPreprocess::EndPreprocessingPass

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **EndPreprocessingPass** method ends a preprocessing pass started with a call to [IWMWriterPreprocess::BeginPreprocessingPass](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriterpreprocess-beginpreprocessingpass).

## Parameters

### `dwInputNum` [in]

**DWORD** containing the input number for which you want to halt preprocessing.

### `dwFlags` [in]

Reserved. Set to zero.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *dwInputNum* specifies an invalid input number. |
| **NS_E_INVALID_REQUEST** | The writer is not running.<br><br>OR<br><br>The preprocessor is not started for the specified stream. |
| **E_FAIL** | There was an error ending the preprocessing path. |

## See also

[IWMWriterPreprocess Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriterpreprocess)