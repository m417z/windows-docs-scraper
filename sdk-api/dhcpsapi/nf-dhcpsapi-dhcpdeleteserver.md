# DhcpDeleteServer function

## Description

The **DhcpDeleteServer** function attempts to delete a DHCP server and any related objects (such as subnet information and IP reservations) from the directory service.

## Parameters

### `Flags` [in]

Set to zero.

### `IdInfo` [in]

Set to null.

### `NewServer` [in]

Pointer to a [DHCP_SERVER_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcpds_server) structure that contains the details of the DHCP server to delete from the directory service.

### `CallbackFn` [in]

Pointer to the function to call after this operation is executed. Set to null.

### `CallbackData` [in]

Pointer to the list of data that will be passed to the callback function specified in *CallbackFn*. Set to null.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

## See also

[DHCP_SERVER_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcpds_server)

[DhcpEnumServers](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpenumservers)