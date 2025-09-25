## Description

A callback function that you implement in your app in order to be notified of changes to the timestamp capabilities of a network adapter. Pass a pointer to your implementation when you call [**RegisterInterfaceTimestampConfigChange**](https://learn.microsoft.com/windows/win32/api/iphlpapi/nf-iphlpapi-registerinterfacetimestampconfigchange).

For more info, and code examples, see [Packet timestamping](https://learn.microsoft.com/windows/win32/iphlp/packet-timestamping).

## Parameters

### `CallerContext`

Type: \_In\_ **PVOID**

The caller-allocated context that you passed to [**RegisterInterfaceTimestampConfigChange**](https://learn.microsoft.com/windows/win32/api/iphlpapi/nf-iphlpapi-registerinterfacetimestampconfigchange), or **NULL** if you didn't pass a context.

## See also

[Packet timestamping](https://learn.microsoft.com/windows/win32/iphlp/packet-timestamping)