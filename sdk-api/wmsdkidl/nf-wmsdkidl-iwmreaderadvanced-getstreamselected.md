# IWMReaderAdvanced::GetStreamSelected

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetStreamSelected** method ascertains whether a particular stream is currently selected. This method can be used only when manual stream selection has been specified.

## Parameters

### `wStreamNum` [in]

**WORD** containing the stream number. Stream numbers are in the range of 1 through 63.

### `pSelection` [out]

Pointer to one member of the [WMT_STREAM_SELECTION](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_stream_selection) enumeration type.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *pSelection* parameter is **NULL**, or the stream number is invalid. |
| **E_UNEXPECTED** | The method failed for an unspecified reason. |
| **NS_E_INVALID_REQUEST** | The reader object has not opened a file yet. |

## See also

[IWMReaderAdvanced Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced)

[IWMReaderAdvanced::SetStreamsSelected](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced-setstreamsselected)

[To Use Manual Stream Selection](https://learn.microsoft.com/windows/desktop/wmformat/to-use-manual-stream-selection)

[WMT_STREAM_SELECTION](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_stream_selection)