# IWMReaderNetworkConfig::GetLoggingUrl

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetLoggingUrl** method retrieves a URL from the list of servers that receive logging information from the reader object. Use the **IWMReaderNetworkConfig::GetLoggingUrl** method to add servers to the list.

## Parameters

### `dwIndex` [in]

Specifies which URL to retrieve, indexed from zero. To get the number of URLs, call the [IWMReaderNetworkConfig::GetLoggingUrlCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig-getloggingurlcount) method.

### `pwszUrl` [out]

Pointer to a buffer that receives a string containing the URL. The caller must allocate the buffer.

### `pcchUrl` [in, out]

On input, specifies the length of the *pwszUrl* buffer, in characters. On output, receives the length of the URL, including the terminating **null** character.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | **NULL** or invalid argument passed in. |
| **ASF_E_BUFFERTOOSMALL** | Size passed in to *pcchUrl* is too small. |

## Remarks

You should make two calls to **GetLoggingUrl**. On the first call, pass **NULL** for *pwszUrl*. On return, the value pointed to by *pcchUrl* is set to the number of wide characters, including the terminating **null**, required to hold the URL. Then you can allocate the required amount of memory for the string and pass a pointer to it as *pwszUrl* on the second call.

## See also

[Client Logging](https://learn.microsoft.com/windows/desktop/wmformat/client)

[IWMReaderNetworkConfig Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadernetworkconfig)