# IWMWriterPostView::SetPostViewProps

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetPostViewProps** method specifies the format for the specified output stream.

## Parameters

### `wStreamNumber` [in]

**WORD** containing the stream number.

### `pOutput` [in]

Pointer to an [IWMMediaProps](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmmediaprops) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_INVALID_STREAM** | The stream number specified by *wStreamNumber* is not valid. |
| **E_OUTOFMEMORY** | The method was unable to create an internal structure. |

## Remarks

It is not possible to resize the video output using postview properties.

**SetPostViewProps** fails if [IWMWriter::BeginWriting](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriter-beginwriting) has been called. If any postview properties need to be changed, this should be done before calling **BeginWriting**.

## See also

[IWMWriterPostView Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriterpostview)

[IWMWriterPostView::GetPostViewProps](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriterpostview-getpostviewprops)