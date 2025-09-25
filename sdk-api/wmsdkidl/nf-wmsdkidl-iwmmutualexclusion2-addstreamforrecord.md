# IWMMutualExclusion2::AddStreamForRecord

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AddStreamForRecord** method adds a stream to a record created with [IWMMutualExclusion2::AddRecord](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmmutualexclusion2-addrecord).

## Parameters

### `wRecordNumber` [in]

**WORD** containing the number of the record to which to add the stream.

### `wStreamNumber` [in]

**WORD** containing the stream number you want to add.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | The method is unable to allocate memory for the new stream number. |
| **E_INVALIDARG** | *wRecordNumber* contains an invalid record number. |
| **E_FAIL** | The method is unable to access the record for an unspecified reason. |

## Remarks

Record numbers are assigned sequentially.

## See also

[IWMMutualExclusion2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmmutualexclusion2)

[IWMMutualExclusion2::RemoveStreamForRecord](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmmutualexclusion2-removestreamforrecord)