# IWMStreamConfig::GetConnectionName

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetConnectionName** method retrieves the input name given to the stream.

## Parameters

### `pwszInputName` [out]

Pointer to a wide-character **null**-terminated string containing the input name. Pass **NULL** to retrieve the length of the name.

### `pcchInputName` [in, out]

On input, a pointer to a variable containing the length of the *pwszInputName* array in wide characters (2 bytes). On output, if the method succeeds, the variable contains the length of the name, including the terminating **null** character.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *pcchInputName* parameter is **NULL**. |
| **ASF_E_BUFFERTOOSMALL** | The name value contained in the *pcchInputName* parameter is too large for the *pwszInputName* array. |

## Remarks

You should make two calls to **GetConnectionName**. On the first call, pass **NULL** as *pwszInputName*. On return, the value pointed to by *pcchInputName* is set to the number of wide characters, including the terminating **null** character, required to hold the connection name. Then you can allocate the required amount of memory for the string and pass a pointer to it as *pwszInputName* on the second call.

The connection name is not written to the header section of an ASF file. If you obtain the [IWMStreamConfig](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstreamconfig) interface from the reader object or synchronous reader object, you cannot retrieve the original connection name.

## See also

[IWMStreamConfig Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstreamconfig)

[IWMStreamConfig::SetConnectionName](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstreamconfig-setconnectionname)