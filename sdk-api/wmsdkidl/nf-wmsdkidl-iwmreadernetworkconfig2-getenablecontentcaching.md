# IWMReaderNetworkConfig2::GetEnableContentCaching

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetEnableContentCaching** method queries whether content caching is enabled. If content caching is enabled, streaming content can be cached locally.

## Parameters

### `pfEnableContentCaching` [out]

Pointer to a Boolean value that is True if content caching is enabled.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | NULL pointer argument. |

## Remarks

This method applies only to content being streamed from a server running Windows Media Services.

## See also

[IWMReaderNetworkConfig2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadernetworkconfig2)

[IWMReaderNetworkConfig2::SetEnableContentCaching](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig2-setenablecontentcaching)