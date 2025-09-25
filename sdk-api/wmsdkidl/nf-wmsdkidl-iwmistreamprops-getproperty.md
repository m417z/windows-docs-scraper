# IWMIStreamProps::GetProperty

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetProperty** method retrieves a named property from the **IStream**.

## Parameters

### `pszName` [in]

Pointer to a **null**-terminated string containing the name of the property to retrieve. You should use the global identifier to refer to properties so that any error will appear at compile time. The following table lists the available **IStream** properties.

| Property name | Global identifier |
| --- | --- |
| **ReloadIndexOnSeek** | g_wszReloadIndexOnSeek |
| **StreamNumIndexObjects** | g_wszStreamNumIndexObjects |
| **FailSeekOnError** | g_wszFailSeekOnError |
| **PermitSeeksBeyondEndOfStream** | g_wszPermitSeeksBeyondEndOfStream |
| **UsePacketAtSeekPoint** | g_wszUsePacketAtSeekPoint |
| **SourceBufferTime** | g_wszSourceBufferTime |
| **SourceMaxBytesAtOnce** | g_wszSourceMaxBytesAtOnce |

### `pType` [out]

Pointer to a variable that will receive one member of the [WMT_ATTR_DATATYPE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_attr_datatype) enumeration type. This value indicates the type of data in the buffer at *pValue*.

### `pValue` [out]

Pointer to a byte buffer that will receive the property value. The type of data returned to the buffer is indicated by the value pointed to by *pType*.

### `pdwSize` [in, out]

Pointer to a **DWORD** containing the size of the buffer at *pValue*. On return, this value will be set to the correct size of the property value.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *pType*, *pValue*, or *pdwSize* is **NULL**.<br><br>OR<br><br>The buffer is not big enough to hold the requested value. |
| **E_FAIL** | *pszName* specifies an invalid property name. |

## Remarks

You should make two calls to **GetProperty** for each property you want to retrieve. On the first call, pass **NULL** as *pValue*. On return, the value pointed to by *pdwSize* will be set to the buffer size required to hold the property value. Then you can allocate the required amount of memory for the buffer and pass a pointer to it as *pValue* on the second call.

## See also

[IWMIStreamProps Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmistreamprops)