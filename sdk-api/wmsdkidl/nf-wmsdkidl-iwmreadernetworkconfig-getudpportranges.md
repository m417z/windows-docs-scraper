# IWMReaderNetworkConfig::GetUDPPortRanges

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetUDPPortRanges** method retrieves the UDP port number ranges used for receiving data.

## Parameters

### `pRangeArray` [out]

Pointer to an array of [WM_PORT_NUMBER_RANGE](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wm_port_number_range) structures allocated by the caller. Pass **NULL** to get the size of the array.

### `pcRanges` [in, out]

On input, pointer to a **DWORD** containing the length of the array passed in *pRangeArray*. On output, pointer to the required array size.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **ASF_E_BUFFERTOOSMALL** | The buffer is too small. |
| **E_INVALIDARG** | The *pcRanges* parameter is **NULL**. |

## Remarks

You should make two calls to this method. On the first call, pass **NULL** for *pRangeArray*. On return, the value pointed to by *pcRanges* is set to the size of the array that you should allocate. Then you can allocate the required amount of memory for the array and pass a pointer to it as *pRangeArray* on the second call.

## See also

[IWMReaderNetworkConfig Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadernetworkconfig)

[IWMReaderNetworkConfig::SetUDPPortRanges](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig-setudpportranges)