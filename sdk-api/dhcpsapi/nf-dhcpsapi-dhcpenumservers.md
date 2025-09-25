# DhcpEnumServers function

## Description

The **DhcpEnumServers** function returns an enumerated list of DHCP servers found in the directory service.

## Parameters

### `Flags` [in]

Reserved for future use. This field should be set to 0.

### `IdInfo` [in]

Pointer to an address containing the server's ID block. This field should be set to null.

### `Servers` [out]

Pointer to a [DHCP_SERVER_INFO_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcpds_servers) structure that contains the output list of DHCP servers.

### `CallbackFn` [in]

Pointer to the callback function that will be called when the server add operation completes. This field should be null.

### `CallbackData` [in]

Pointer to a data block containing the formatted structure for callback information. This field should be null.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

## See also

[DHCP_SERVER_INFO_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcpds_servers)