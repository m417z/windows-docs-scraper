# IWMReaderNetworkConfig2::SetEnableFastCache

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetEnableFastCache** method enables or disables Fast Cache streaming. Fast Cache streaming enables network content to be streamed faster than the playback rate, if bandwidth allows.

## Parameters

### `fEnableFastCache` [in]

Specifies whether to enable or disable Fast Cache streaming. The value True enables Fast Cache, and the value False disables it.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method enables the reader to use Fast Cache streaming if the server also supports it. This feature is supported only when streaming content from a server running Windows Media Services. For more information, see [Enabling Fast Cache Streaming from the Client](https://learn.microsoft.com/windows/desktop/wmformat/enabling-fast-cache-streaming-from-the-client).

Regardless of the status of Fast Cache set by this method, a user can enable this feature by adding "?WMCache=1" to the end of the URL. However, Fast Cache cannot be activated at all unless caching is enabled with a call to [IWMReaderNetworkconfig2::SetEnableContentCaching](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig2-setenablecontentcaching).

## See also

[IWMReaderNetworkConfig2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadernetworkconfig2)

[IWMReaderNetworkConfig2::GetEnableFastCache](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig2-getenablefastcache)