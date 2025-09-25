# IWMSyncReader::GetOutputNumberForStream

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetOutputNumberForStream** method retrieves the output number that corresponds with the specified stream.

## Parameters

### `wStreamNum` [in]

**WORD** containing the stream number for which you want to retrieve the corresponding output number.

### `pdwOutputNum` [out]

Pointer to a **DWORD** that will receive the output number that corresponds to the stream number specified in *wStreamNum*.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_INVALID_REQUEST** | *wStreamNum* specifies an invalid stream number. |

## Remarks

More than one stream can be encompassed by an output, as in the case of multiple bit rate files.

## See also

[IWMSyncReader Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmsyncreader)