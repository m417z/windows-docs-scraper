# IWMSyncReader::GetMaxStreamSampleSize

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetMaxStreamSampleSize** method retrieves the maximum sample size for a specified stream in the file that is open in the synchronous reader.

## Parameters

### `wStream` [in]

**WORD** containing the stream number for which you want to retrieve the maximum sample size.

### `pcbMax` [out]

Pointer to a **DWORD** value that receives the maximum sample size, in bytes, for the stream specified in *wStream*.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *pcbMax* is **NULL**.<br><br>OR<br><br>*wStream* specifies an invalid stream number. |
| **ASF_E_INVALIDSTATE** | No file is open in the synchronous reader. |

## Remarks

This method retrieves the maximum sample size for an individual stream. The stream may be one of several in an output. If you are using output numbers, you should use [IWMSyncReader::GetMaxOutputSampleSize](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmsyncreader-getmaxoutputsamplesize) to retrieve the maximum sample size for the entire output.

## See also

[IWMSyncReader Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmsyncreader)