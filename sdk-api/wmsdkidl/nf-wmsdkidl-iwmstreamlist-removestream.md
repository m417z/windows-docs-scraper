# IWMStreamList::RemoveStream

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **RemoveStream** method removes a stream from the list.

## Parameters

### `wStreamNum` [in]

**WORD** containing the stream number. Stream numbers are in the range of 1 through 63.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_NOMATCHING_ELEMENT** | The *wStreamNum* parameter is not valid. |

## Remarks

The **RemoveStream** method also removes the stream from any mutual exclusion objects that the stream belongs to.

## See also

[IWMStreamList Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstreamlist)

[IWMStreamList::AddStream](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstreamlist-addstream)