# INSNetSourceCreator::GetNetSourceAdminInterface

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetNetSourceAdminInterface** method retrieves a pointer to the **IDispatch** interface of the administrative network source object.

## Parameters

### `pszStreamName` [in]

Pointer to a wide-character **null**-terminated string containing the desired network protocol. Typically, this value is either "http\0" or "mms\0".

### `pVal` [out]

Pointer to a **VARIANT** that receives the address of the **IDispatch** interface on successful return. Use this interface pointer to obtain the interface pointer of the desired network admin interface: [IWMSInternalAdminNetSource](https://learn.microsoft.com/windows/desktop/api/wmsinternaladminnetsource/nn-wmsinternaladminnetsource-iwmsinternaladminnetsource), [IWMSInternalAdminNetSource2](https://learn.microsoft.com/windows/desktop/api/wmsinternaladminnetsource/nn-wmsinternaladminnetsource-iwmsinternaladminnetsource2), or [IWMSInternalAdminNetSource3](https://learn.microsoft.com/windows/desktop/api/wmsinternaladminnetsource/nn-wmsinternaladminnetsource-iwmsinternaladminnetsource3).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | One or both of the parameters are **NULL**. |
| **E_OUTOFMEMORY** | Unable to allocate memory for an internal resource. |
| **NS_E_UNKNOWN_PROTOCOL** | The protocol specified by *pwszStreamName* is not supported. |

## See also

[INSNetSourceCreator Interface](https://learn.microsoft.com/windows/desktop/api/wmnetsourcecreator/nn-wmnetsourcecreator-insnetsourcecreator)