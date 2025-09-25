# IWMBandwidthSharing::GetBandwidth

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetBandwidth** method retrieves the bandwidth and maximum buffer size of a combined stream.

## Parameters

### `pdwBitrate` [out]

Pointer to a **DWORD** containing the bit rate in bits per second. The combined bandwidths of the streams cannot exceed this value.

### `pmsBufferWindow` [out]

Pointer to **DWORD** containing the buffer window in milliseconds. The combined buffer sizes of the streams cannot exceed this value.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | One or both of the parameters are **NULL**. |

## Remarks

The settings of a bandwidth sharing object are purely informational. They are not checked for accuracy.

## See also

[IWMBandwidthSharing Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmbandwidthsharing)

[IWMBandwidthSharing::SetBandwidth](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmbandwidthsharing-setbandwidth)