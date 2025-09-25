# IWMReaderNetworkConfig2::GetEnableFastCache

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetEnableFastCache** method queries whether Fast Cache streaming is enabled. Fast Cache streaming enables network content to be streamed faster than the playback rate, if bandwidth allows.

## Parameters

### `pfEnableFastCache` [out]

Pointer to a variable that receives a Boolean value. The value is True if Fast Cache streaming is enabled, or False otherwise.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | NULL pointer argument. |

## Remarks

This feature requires content caching to be enabled as well. Fast Cache applies only to content being streamed from a server running Windows Media Services.

## See also

[Enabling Fast Cache Streaming from the Client](https://learn.microsoft.com/windows/desktop/wmformat/enabling-fast-cache-streaming-from-the-client)

[IWMReaderNetworkConfig2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadernetworkconfig2)

[IWMReaderNetworkConfig2::SetEnableFastCache](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig2-setenablefastcache)