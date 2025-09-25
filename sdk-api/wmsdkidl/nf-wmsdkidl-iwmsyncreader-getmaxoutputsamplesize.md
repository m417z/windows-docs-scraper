# IWMSyncReader::GetMaxOutputSampleSize

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetMaxOutputSampleSize** method retrieves the maximum sample size for a specified output of the file open in the synchronous reader.

## Parameters

### `dwOutput` [in]

**DWORD** containing the output number for which you want to retrieve the maximum sample size.

### `pcbMax` [out]

Pointer to a **DWORD** value that receives the maximum sample size, in bytes, for the output specified in *dwOutput*.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *pcbMax* is **NULL**.<br><br>OR<br><br>*dwOutput* specifies an invalid output number. |
| **ASF_E_INVALIDSTATE** | No file is opened in the synchronous reader. |
| **NS_E_NOT_CONFIGURED** | The specified output is not currently configured for playback. |
| **E_UNEXPECTED** | The synchronous reader failed to initialize an internal object. |

## Remarks

In some scenarios, such as multiple bit rate streaming, the output encompasses several streams. The size returned is the maximum sample size for all of the streams associated with the specified output.

You can retrieve the maximum sample size for a specific stream by using [IWMSyncReader::GetMaxStreamSampleSize](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmsyncreader-getmaxstreamsamplesize).

## See also

[IWMSyncReader Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmsyncreader)