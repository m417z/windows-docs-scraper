# IWMWriterPostView::SetAllocateForPostView

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetAllocateForPostView** method specifies whether the application, and not the writer, must supply the buffers.

## Parameters

### `wStreamNumber` [in]

**WORD** containing the stream number.

### `fAllocate` [in]

Boolean value. Set to True if the application allocates buffers, and False if this is left to the reader.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_INVALID_STREAM** | The stream number specified by *wStreamNumber* is not valid. |
| **E_OUTOFMEMORY** | The method was unable to create an internal structure. |

## Remarks

The application can provide buffers for any of the outputs, rather than use those allocated by the reader. For example, some applications can allocate Microsoft DirectDraw® buffers.

The actual allocation of buffers is handled by the [IWMReaderCallbackAdvanced](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadercallbackadvanced) interface.

## See also

[IWMWriterPostView Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriterpostview)

[IWMWriterPostView::GetAllocateForPostView](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriterpostview-getallocateforpostview)