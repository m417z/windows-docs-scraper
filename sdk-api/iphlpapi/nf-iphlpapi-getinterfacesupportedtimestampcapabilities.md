## Description

Retrieves the supported timestamp capabilities of a network adapter.

For more info, and code examples, see [Packet timestamping](https://learn.microsoft.com/windows/win32/iphlp/packet-timestamping).

## Parameters

### `InterfaceLuid`

Type: \_In\_ **CONST [NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh)\***

The network locally unique identifier (LUID) of the network adapter for which supported timestamp capabilities are to be retrieved.

### `TimestampCapabilites`

Type: \_Out\_ **[PINTERFACE_TIMESTAMP_CAPABILITIES](https://learn.microsoft.com/windows/win32/api/iphlpapi/ns-iphlpapi-interface_timestamp_capabilities)**

If the function succeeds, then *TimestampCapabilites* returns a structure that describes the supported timestamp capabilities.

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

If the function succeeds, then it returns **NO_ERROR**. If the network card corresponding to *InterfaceLuid* isn't timestamp-aware, then the function returns **ERROR_NOT_SUPPORTED**.

## Remarks

## See also

* [Packet timestamping](https://learn.microsoft.com/windows/win32/iphlp/packet-timestamping)