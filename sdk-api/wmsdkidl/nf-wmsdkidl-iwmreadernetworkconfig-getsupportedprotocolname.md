# IWMReaderNetworkConfig::GetSupportedProtocolName

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetSupportedProtocolName** method retrieves a protocol name by index.

## Parameters

### `dwProtocolNum` [in]

Specifies protocol name to retrieve, indexed from zero. To get the number of supported protocols, call the [IWMReaderNetworkConfig::GetNumProtocolsSupported](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig-getnumprotocolssupported) method.

### `pwszProtocolName` [out]

Pointer to a wide-character **null**-terminated string containing the protocol name. Pass **NULL** to retrieve the length of the name.

### `pcchProtocolName` [in, out]

On input, pointer to a **DWORD** containing the length of the *pwszProtocolName*, in characters. On output, pointer to the length of the protocol name, including the terminating **null** character.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | **NULL** or invalid argument passed in. |

## Remarks

You should make two calls to **GetSupportedProtocolName**. On the first call, pass **NULL** for *pwszProtocoName*. On return, the value pointed to by *pcchProtocolName* is set to the number of wide characters, including the terminating **null**, required to hold the protocol name. Then you can allocate the required amount of memory for the string and pass a pointer to it as *pwszProtocolName* on the second call.

Use this method along with **GetNumProtocolsSupported** to iterate through the network protocols supported by the reader object.

This method only returns a list of protocols that are used to receive content from Windows Media servers. Protocols that are only used for retrieving content from local sources, or non-Windows Media servers (such as Web servers) are not included in this list.

**Note** The HTTPS support works only when downloading content from a Web server (because the player is using WININET). Streaming protocols supported are HTTP, RTSP, MMS, and, for multicasting, ASFM (by opening an ASF file with an .nsc extension). Download support includes HTTP, HTTPS, and FTP.

## See also

[IWMReaderNetworkConfig Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadernetworkconfig)