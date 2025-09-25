# IWMWriterNetworkSink::GetHostURL

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetHostURL** method retrieves the URL from which the stream is broadcast. Clients will access the stream from this URL.

## Parameters

### `pwszURL` [out]

Pointer to buffer that receives a string containing the URL. To retrieve the length of the string, set this parameter to **NULL**.

### `pcchURL` [in, out]

On input, pointer to the size of *pwszURL*, in characters. On output, this parameter receives the length of the URL in characters, including the terminating **null** character.

## Return value

The method returns an HRESULT. Possible values include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **ASF_E_BUFFERTOOSMALL** | The buffer is too small. |
| **E_INVALIDARG** | Invalid argument; *pcchURL* cannot be **NULL**. |
| **NS_E_INVALID_REQUEST** | The network sink is not connected. |

## Remarks

You should make two calls to **GetHostURL**. On the first call, pass **NULL** as *pwszURL*. On return, the value pointed to by *pcchURL* is set to the number of characters, including the terminating **null** character, required to hold the URL. Then you can allocate the required amount of memory for the string and pass a pointer to it as *pwszURL* on the second call.

## See also

[IWMWriterNetworkSink Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriternetworksink)