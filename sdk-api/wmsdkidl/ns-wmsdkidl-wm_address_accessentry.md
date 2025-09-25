# WM_ADDRESS_ACCESSENTRY structure

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WM_ADDRESS_ACCESSENTRY** structure specifies an entry in an IP address access list.

## Members

### `dwIPAddress`

An IPv4 address, in network byte order.

### `dwMask`

An IPv4 address, in network byte order, to use as a bitmask. The bitmask defines which bits in the **dwIPAddress** field are matched against. For example, if the IP address is 206.73.118.1 and the mask is 255.255.255.0, only the first 24 bits of the address are examined. Thus, any IP addresses in the range 206.73.118.*XXX* would match this entry.

## Remarks

You can use the **inet_addr** function to convert a standard dotted-format string (such as "255.255.255.255") to the correct binary number in network byte order.

## See also

[IWMAddressAccess Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmaddressaccess)

[Structures](https://learn.microsoft.com/windows/desktop/wmformat/structures)