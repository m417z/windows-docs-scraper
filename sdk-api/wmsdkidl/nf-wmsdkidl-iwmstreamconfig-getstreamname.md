# IWMStreamConfig::GetStreamName

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetStreamName** method retrieves the stream name.

## Parameters

### `pwszStreamName` [out]

Pointer to a wide-character **null**-terminated string containing the stream name. Pass **NULL** to retrieve the length of the name.

### `pcchStreamName` [in, out]

On input, a pointer to a variable containing the length of the *pwszStreamName* array in wide characters (2 bytes). On output, if the method succeeds, the variable contains the actual length of the name, including the terminating **null** character.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *pcchStreamName* parameter is **NULL**. |
| **ASF_E_BUFFERTOOSMALL** | The name value contained in the *pcchStreamName* parameter is too large for the *pwszStreamName* array. |

## Remarks

You should make two calls to **GetStreamName**. On the first call, pass **NULL** as *pwszStreamName*. On return, the value pointed to by *pcchStreamName* is set to the number of wide characters, including the terminating **null** character, required to hold the stream name. Then you can allocate the required amount of memory for the string and pass a pointer to it as *pwszStreamName* on the second call.

The stream name is not written to the header section of an ASF file. If you obtain the [IWMStreamConfig](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstreamconfig) interface from the reader object or synchronous reader object, you cannot retrieve the original stream name.

## See also

[IWMStreamConfig Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstreamconfig)

[IWMStreamConfig::GetStreamType](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstreamconfig-getstreamtype)

[IWMStreamConfig::SetStreamName](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstreamconfig-setstreamname)