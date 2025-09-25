# IWMSyncReader::GetStreamSelected

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetStreamSelected** method retrieves a flag indicating whether a particular stream is currently selected.

## Parameters

### `wStreamNum` [in]

**WORD** containing the stream number.

### `pSelection` [out]

Pointer to a variable that receives one member of the [WMT_STREAM_SELECTION](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_stream_selection) enumeration type on output. This value specifies the selection status for the specified stream.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_UNEXPECTED** | The method failed for an unspecified reason. |
| **E_INVALIDARG** | The *pSelection* parameter is **NULL**, or the stream number is invalid. |
| **NS_E_INVALID_REQUEST** | No file is open in the synchronous reader. |

## Remarks

This method is identical to [IWMReaderAdvanced::GetStreamSelected](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced-getstreamselected).

## See also

[IWMSyncReader Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmsyncreader)