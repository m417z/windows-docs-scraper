# IWMStreamConfig2::AddDataUnitExtension

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AddDataUnitExtension** method adds a data unit extension system to the stream. You can use data unit extension systems to attach custom data to samples in an output file.

## Parameters

### `guidExtensionSystemID` [in]

A GUID that identifies the data unit extension system. This can be one of the predefined GUIDs listed in [INSSBuffer3::SetProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nf-wmsbuffer-inssbuffer3-setproperty), or a GUID whose value is understood by a custom player application.

### `cbExtensionDataSize` [in]

Size, in bytes, of the data unit extensions that will be attached to the packets in the stream. Set to 0xFFFF to specify data unit extensions of variable size. Each individual data unit extension can then be set to any size ranging from 0 to 65534.

### `pbExtensionSystemInfo` [in]

Pointer to a byte buffer containing information about the data unit extension system. If you have no information, you can pass **NULL**. When passing **NULL**, *cbExtensionSystemInfo* must be zero.

### `cbExtensionSystemInfo` [in]

Count of bytes in the buffer at *pbExtensionSystemInfo*. If you have no data unit extension system information, you can pass zero. When passing zero, *pbExtensionSystemInfo* must be **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *cbExtensionSystemInfo* specifies a non-zero value, but *pbExtensionSystemInfo* is **NULL**. |
| **E_OUTOFMEMORY** | The method cannot allocate memory to hold the new data unit extension. |

## Remarks

Passing the GUID of an existing data unit extension system does not cause an error. The old system is destroyed and replaced by the new one.

The new value will not take effect in the profile until you call [IWMProfile::ReconfigStream](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofile-reconfigstream).

## See also

[IWMStreamConfig2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstreamconfig2)

[IWMStreamConfig2::GetDataUnitExtension](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstreamconfig2-getdataunitextension)