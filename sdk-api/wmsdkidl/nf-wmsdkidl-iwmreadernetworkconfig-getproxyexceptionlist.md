# IWMReaderNetworkConfig::GetProxyExceptionList

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetProxyExceptionList** method retrieves the list of computers, domains, or addresses for which the reader object bypasses the proxy server.

## Parameters

### `pwszProtocol` [in]

Pointer to a string that contains a protocol name, such as "http" or "mms". The string is not case-sensitive.

### `pwszExceptionList` [out]

Pointer to a buffer that receives a string containing the exception list. The returned string is a comma-separated list. For more information, see [SetProxyExceptionList](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig-setproxyexceptionlist). The list applies only to the protocol specified in *pwszProtocol*; the reader object supports separate settings for each protocol.

### `pcchExceptionList` [in, out]

On input, pointer to a variable specifying the size of the *pwszExceptionList* buffer, in characters. On output, the variable contains the length of the string, including the terminating **null** character.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | **NULL** or invalid argument passed in. |
| **ASF_E_BUFFERTOOSMALL** | The size of the buffer passed in is not large enough to hold the return string. |

## Remarks

Call this method twice. The first time, pass **NULL** as the value for *pwszExceptionList*. The method returns the size of the string in the *pcchExceptionList* parameter. Allocate the required amount of memory for the string and call the method again. This time, pass a pointer to the allocated buffer in the *pwszExceptionList* parameter.

For more information, see the Remarks for [SetProxyExceptionList](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig-setproxyexceptionlist).

## See also

[IWMReaderNetworkConfig Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadernetworkconfig)

[IWMReaderNetworkConfig::SetProxyExceptionList](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig-setproxyexceptionlist)