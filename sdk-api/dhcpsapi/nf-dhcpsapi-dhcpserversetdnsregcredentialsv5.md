# DhcpServerSetDnsRegCredentialsV5 function

## Description

The **DhcpServerSetDnsRegCredentialsV5** function sets the credentials used by the DHCP server to create Domain Name System (DNS) registrations for the DHCP client lease record.

## Parameters

### `ServerIpAddress` [in]

[DHCP_SRV_HANDLE](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) that specifies the RPC binding to the DHCP server on which the DNS credentials will be set.

### `Uname` [in]

Pointer to a null-terminated Unicode string that specifies the user name for the DNS credentials.

### `Domain` [in]

Pointer to a null-terminated Unicode string that specifies the domain name for the DNS credentials.

### `Passwd` [in]

Pointer to a null-terminated Unicode string that specifies the password for the DNS credentials. The password can be unencrypted.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

## See also

[DhcpServerQueryDnsRegCredentials](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpserverquerydnsregcredentials)