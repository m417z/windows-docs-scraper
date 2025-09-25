# IWMWriterPostView::GetReceivePostViewSamples

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetReceivePostViewSamples** method retrieves a flag indicating whether delivery of postview samples has been turned on for the specified stream.

## Parameters

### `wStreamNum` [in]

**WORD** containing the stream number.

### `pfReceivePostViewSamples` [out]

Pointer to a flag; True indicates that postview samples are to be delivered.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | NULL value passed to *pfReceivePostViewSamples*. |

## See also

[IWMWriterPostView Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriterpostview)

[IWMWriterPostView::SetReceivePostViewSamples](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriterpostview-setreceivepostviewsamples)