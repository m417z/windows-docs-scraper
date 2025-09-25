# IWMOutputMediaProps::GetConnectionName

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetConnectionName** method retrieves the name of the connection to be used for output.

## Parameters

### `pwszName` [out]

Pointer to a wide-character **null**-terminated string containing the name. Pass **NULL** to retrieve the length of the name.

### `pcchName` [in, out]

On input, a pointer to a variable containing the length of the *pwszName* array in wide characters. On output, if the method succeeds, it specifies a pointer to the length of the connection name, including the terminating **null** character.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *pwszName* parameter is **NULL**. |
| **ASF_E_BUFFERTOOSMALL** | The buffer pointed to by *pcchName* is not large enough for the requested name. |

## Remarks

The reader creates a default connection name for each output that is simply a string representation of the output number, for example "1", "2", "3" and so on.

You should make two calls to **GetConnectionName**. On the first call, pass **NULL** as *pwszName*. On return, the value pointed to by *pcchName* is set to the number of wide characters, including the terminating **null** character, required to hold the connection name. Then you can allocate the required amount of memory for the string and pass a pointer to it as *pwszName* on the second call.

This connection name is used to match stream numbers to output numbers. All streams in the file are associated with an **IWMStreamConfig** object whose connection name matches this one (which can be obtained by a call to **IWMStreamConfig::GetConnectionName**).

## See also

[IWMOutputMediaProps Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmoutputmediaprops)

[IWMStreamConfig Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstreamconfig)

[IWMStreamConfig::GetConnectionName](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstreamconfig-getconnectionname)

[Inputs, Streams and Outputs](https://learn.microsoft.com/windows/desktop/wmformat/inputs-streams-and-outputs)