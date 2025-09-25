# WM_PORT_NUMBER_RANGE structure

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WM_PORT_NUMBER_RANGE** structure describes the range of port numbers used by the **IWMReaderNetworkConfig** interface.

## Members

### `wPortBegin`

**WORD** containing the lowest port number.

### `wPortEnd`

**WORD** containing the highest port number.

## See also

[IWMReaderNetworkConfig Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadernetworkconfig)

[IWMReaderNetworkConfig::GetUDPPortRanges](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig-getudpportranges)

[IWMReaderNetworkConfig::SetUDPPortRanges](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadernetworkconfig-setudpportranges)

[Structures](https://learn.microsoft.com/windows/desktop/wmformat/structures)