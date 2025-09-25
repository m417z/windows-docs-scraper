# IWMWriterPostView::SetReceivePostViewSamples

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetReceivePostViewSamples** method enables or disables delivery of postview samples for the specified stream.

## Parameters

### `wStreamNum` [in]

**WORD** containing the stream number.

### `fReceivePostViewSamples` [in]

Boolean value that is True if postview samples must be delivered.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *wStreamNum* is less than 1 or greater than the maximum number of streams. |
| **NS_E_INVALID_STREAM** | Could not get the output for that stream. |
| **NS_E_INVALID_REQUEST** | Stream does not support postview. |

## See also

[IWMWriterPostView Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriterpostview)

[IWMWriterPostView::GetReceivePostViewSamples](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriterpostview-getreceivepostviewsamples)