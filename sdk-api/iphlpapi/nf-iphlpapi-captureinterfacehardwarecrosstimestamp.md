## Description

Retrieves cross timestamp info for a network adapter.

For more info, and code examples, see [Packet timestamping](https://learn.microsoft.com/windows/win32/iphlp/packet-timestamping).

> [!IMPORTANT]
> On Windows 10, version 2004 (10.0; Build 19041) and earlier, this function is reserved for system use, and you should not call it from your code. On later versions, this function *is* supported.

## Parameters

### `InterfaceLuid`

Type: \_In\_ **CONST [NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh)\***

The network locally unique identifier (LUID) of the network adapter from which a cross timestamp is to be retrieved.

### `CrossTimestamp`

Type: \_Inout\_ **[PINTERFACE_HARDWARE_CROSSTIMESTAMP](https://learn.microsoft.com/windows/win32/api/iphlpapi/ns-iphlpapi-interface_hardware_crosstimestamp)**

The timestamp is returned by the network adapter in the form of an [**INTERFACE_HARDWARE_CROSSTIMESTAMP**](https://learn.microsoft.com/windows/win32/api/iphlpapi/ns-iphlpapi-interface_hardware_crosstimestamp) object.

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A **DWORD** return code indicating success or failure.

## See also

[Packet timestamping](https://learn.microsoft.com/windows/win32/iphlp/packet-timestamping)