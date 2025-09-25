# IWMSyncReader::GetReadStreamSamples

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetReadStreamSamples** method ascertains whether a stream is configured to deliver compressed samples.

## Parameters

### `wStreamNum` [in]

**WORD** containing the stream number.

### `pfCompressed` [out]

Pointer to a flag that receives the status of compressed delivery for the stream specified.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *pfCompressed* is **NULL**.<br><br>OR<br><br>*wStreamNum* specifies an invalid stream number. |
| **E_UNEXPECTED** | No file is open in the synchronous reader. |

## Remarks

To configure a stream to deliver compressed samples, call [IWMSyncReader::SetReadStreamSamples](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmsyncreader-setreadstreamsamples).

## See also

[IWMSyncReader Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmsyncreader)