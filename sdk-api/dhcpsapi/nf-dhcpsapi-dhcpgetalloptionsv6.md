# DhcpGetAllOptionsV6 function

## Description

The **DhcpGetAllOptionsV6** function returns an array that contains all options defined on the DHCP server.

## Parameters

### `ServerIpAddress` [in]

Pointer to a Unicode string that specifies the IP address or hostname of the DHCP server.

### `Flags` [in]

Specifies a bit flag that indicates whether or not the options are vendor-specific. If the qualification of vendor options is not necessary, this parameter should be 0.

| Value | Meaning |
| --- | --- |
| **DHCP_FLAGS_OPTION_IS_VENDOR** | This flag should be set if vendor-specific options are desired. |

### `OptionStruct` [out]

Pointer to a [DHCP_ALL_OPTIONS](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_all_options) structure containing every option defined on the DHCP server. If there are no options available on the server, this value will be null.

**Note**

The memory for this parameter must be free using [DhcpRpcFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcprpcfreememory).

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The parameters were invalid. |
| **ERROR_NO_MORE_ITEMS** | No more items to enumerate. |
| **ERROR_NOT_ENOUGH_MEMORY** | Memory failure. |
| **ERROR_MORE_DATA** | More data is available to enumerate. |