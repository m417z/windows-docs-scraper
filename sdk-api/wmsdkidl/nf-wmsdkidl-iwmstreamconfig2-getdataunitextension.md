# IWMStreamConfig2::GetDataUnitExtension

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetDataUnitExtension** method retrieves information about an existing data unit extension system.

## Parameters

### `wDataUnitExtensionNumber` [in]

**WORD** containing the data unit extension number. This number is assigned to a data unit extension system when it is added to the stream.

### `pguidExtensionSystemID` [out]

Pointer to a GUID that receives the identifier of the data unit extension system.

### `pcbExtensionDataSize` [out]

Pointer to the size, in bytes, of the data unit extensions that will be attached to the packets in the stream.

If this value is 0xFFFF, the system uses data unit extensions of variable size. Each individual data unit extension can then be set to any size ranging from 0 to 65534.

### `pbExtensionSystemInfo` [out]

Pointer to a byte buffer that receives information about the data unit extension system.

### `pcbExtensionSystemInfo` [in, out]

Pointer to the size, in bytes, of the data stored at *pbExtensionSystemInfo*.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *pguidExtensionSystemID* or *pcbExtensionDataSize* is **NULL**.<br><br>OR<br><br>*wDataUnitExtensionNumber* specifies an invalid data unit extension number. |

## Remarks

To retrieve the total number of data unit extension systems associated with the stream, call [GetDataUnitExtensionCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstreamconfig2-getdataunitextensioncount).

## See also

[IWMStreamConfig2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstreamconfig2)

[IWMStreamConfig2::AddDataUnitExtension](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstreamconfig2-adddataunitextension)