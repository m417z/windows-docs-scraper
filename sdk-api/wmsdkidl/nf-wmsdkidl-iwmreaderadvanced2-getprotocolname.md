# IWMReaderAdvanced2::GetProtocolName

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetProtocolName** method retrieves the name of the protocol that is being used.

## Parameters

### `pwszProtocol` [out]

Pointer to a buffer that receives a string containing the protocol name. Pass **NULL** to retrieve the length of the name.

### `pcchProtocol` [in, out]

On input, pointer to a variable containing the length of *pwszProtocol*, in characters. On output, the variable contains the length of the name, including the terminating **null** character.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **ASF_E_BUFFERTOOSMALL** | The buffer is too small. |
| **ASF_E_INVALIDSTATE** | The protocol has not been determined, or no file is open. |
| **E_INVALIDARG** | The *pcchProtocol* parameter is **NULL**. |

## Remarks

You should make two calls to **GetProtocolName**. On the first call, pass **NULL** for *pwszProtocol*. On return, the value pointed to by *pcchProtocol* is set to the number of wide characters, including the terminating **null**, required to hold the protocol name. Then you can allocate the required amount of memory for the string and pass a pointer to it as *pwszProtocol* on the second call.

The protocol name is a URL scheme, such as *mmsu*, *http*, or *file*. However, the protocol name can differ from the URL scheme specified in [IWMReader::Open](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreader-open), because the reader object might use protocol rollover to find the best protocol. Also, the returned string might be "File" for local file content, or "Cache" for content saved in the cache.

This method can return an empty string if the protocol name cannot be determined.

## See also

[IWMReaderAdvanced2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced2)