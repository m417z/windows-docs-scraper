# IWMWriterAdvanced3::GetStatisticsEx

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetStatisticsEx** method retrieves extended statistics for the writer.

## Parameters

### `wStreamNum` [in]

**WORD** containing the stream number for which you want to get statistics. You can pass 0 to obtain extended statistics for the entire file. Stream numbers are in the range of 1 through 63.

### `pStats` [out]

Pointer to the [WM_WRITER_STATISTICS_EX](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wm_writer_statistics_ex) structure that receives the statistics.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_INVALID_REQUEST** | The writer is in the configuration state, during which this method cannot be called. |

## Remarks

**GetStatisticsEx** is not an improved version of [IWMWriterAdvanced::GetStatistics](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced-getstatistics). The statistics retrieved by **GetStatistics** are not retrieved by **GetStatisticsEx**; if you want to get all available statistics you must call both methods.

## See also

[IWMWriterAdvanced3 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriteradvanced3)