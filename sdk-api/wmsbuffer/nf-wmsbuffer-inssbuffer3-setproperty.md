# INSSBuffer3::SetProperty

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetProperty** method is used to specify a property for the sample in the buffer. Buffer properties are used to pass information along with the sample to the writer object when writing ASF files. Sample properties are GUID values.

## Parameters

### `guidBufferProperty` [in]

**GUID** value identifying the property you want to set. The predefined buffer properties are described in the [Sample Extension Types](https://learn.microsoft.com/windows/desktop/wmformat/sample-extension-types) section of this documentation. You can also define your own sample extension schemes using your own GUID values.

### `pvBufferProperty` [in]

Pointer to a buffer containing the property value.

### `dwBufferPropertySize` [in]

**DWORD** value containing the size of the buffer pointed to by *pvBufferProperty*.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | The method was unable to allocate memory for the new property. |

## Remarks

If you set a buffer property with a size larger than that specified in your call to [IWMStreamConfig2::AddDataUnitExtension](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstreamconfig2-adddataunitextension), you will not get an error from **SetProperty**. However, when the writer writes the sample, NS_E_DATA_UNIT_EXTENSION_TOO_LARGE will be returned.

## See also

[INSSBuffer3 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nn-wmsbuffer-inssbuffer3)

[INSSBuffer3::GetProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nf-wmsbuffer-inssbuffer3-getproperty)