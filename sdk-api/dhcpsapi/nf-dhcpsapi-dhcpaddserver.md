# DhcpAddServer function

## Description

The **DhcpAddServer** function attempts to add a new server to the existing list of DHCP servers maintained in the domain directory service. If the specified DHCP server already exists in the directory service, an error is returned.

## Parameters

### `Flags` [in]

Reserved for future use. This field should be set to 0x00000000.

### `IdInfo` [in]

Pointer to an address containing the server's ID block. This field should be set to null.

### `NewServer` [in]

Pointer to a [DHCP_SERVER_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcpds_server) structure containing information about the new DHCP server. The **DsLocation** and **DsLocType** members present in this structure are not valid in this implementation, and they should be set to null. The **Version** member of this structure should be set to 0.

### `CallbackFn` [in]

Pointer to the callback function that will be called when the server add operation completes. This field should be null.

### `CallbackData` [in]

Pointer to a data block containing the formatted structure for callback information. This field should be null.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

## See also

[DHCP_SERVER_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcpds_server)

[DhcpDeleteServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpdeleteserver)