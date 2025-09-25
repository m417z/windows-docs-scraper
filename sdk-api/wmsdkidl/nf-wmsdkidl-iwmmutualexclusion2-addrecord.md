# IWMMutualExclusion2::AddRecord

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AddRecord** method adds a record to the mutual exclusion object. Records can hold groups of streams. You can add streams with calls to [IWMMutualExclusion2::AddStreamForRecord](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmmutualexclusion2-addstreamforrecord). You can assign a name to a record with a call to [IWMMutualExclusion2::SetName](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmmutualexclusion2-setname).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | The method was unable to allocate memory for the new record. |
| **E_FAIL** | There was a problem adding the new record to the collection of records for this mutual exclusion object. |

## Remarks

Record numbers, which are used by other methods, are assigned to records sequentially.

## See also

[IWMMutualExclusion2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmmutualexclusion2)

[IWMMutualExclusion2::AddStreamForRecord](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmmutualexclusion2-addstreamforrecord)

[IWMMutualExclusion2::RemoveRecord](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmmutualexclusion2-removerecord)

[IWMMutualExclusion2::SetName](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmmutualexclusion2-setname)