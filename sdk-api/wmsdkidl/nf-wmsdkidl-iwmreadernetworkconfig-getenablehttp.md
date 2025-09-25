# IWMReaderNetworkConfig::GetEnableHTTP

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetEnableHTTP** method queries whether HTTP is enabled for protocol rollover.

## Parameters

### `pfEnableHTTP` [out]

Pointer to a variable that receives a Boolean value. If the value is **TRUE**, the reader object includes HTTP when it performs protocol rollover. If the value is **FALSE**, the reader does not use HTTP for protocol rollover. However, the reader will still use HTTP if it is explicitly specified in the URL.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | NULL or invalid argument passed in. |

## See also

[IWMReaderNetworkConfig Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadernetworkconfig)

[IWMReaderNetworkConfig::SetEnableHTTP](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig-setenablehttp)