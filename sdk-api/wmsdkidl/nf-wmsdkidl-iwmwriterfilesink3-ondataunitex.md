# IWMWriterFileSink3::OnDataUnitEx

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **OnDataUnitEx** method is called when the writer has finished sending a data unit.

**OnDataUnitEx** is an enhanced version of [IWMWriterSink::OnDataUnit](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwritersink-ondataunit). The difference between these two methods is that **OnDataUnitEx** delivers very granular data unit information. You can examine individual payload headers, payload data fragments, and the packet header.

## Parameters

### `pFileSinkDataUnit` [in]

Pointer to a [WMT_FILESINK_DATA_UNIT](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wmt_filesink_data_unit) structure containing the data unit information.

## Return value

This method always returns S_OK.

## Remarks

Applications do not call this method. If you are implementing the **IWMWriterFileSink3** interface on a custom sink, you have the option of implementing this method. If you do so, your implementation of [GetMode](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriterfilesink3-getmode) should return WMT_FM_FILESINK_DATA_UNITS.

## See also

[IWMWriterFileSink3 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriterfilesink3)