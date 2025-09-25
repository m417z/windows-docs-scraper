# DhcpServerQueryDnsRegCredentials function

## Description

The **DhcpServerQueryDnsRegCredentials** function retrieves the current Domain Name System (DNS) credentials used by the DHCP server for client dynamic DNS registration.

## Parameters

### `ServerIpAddress` [in]

[DHCP_SRV_HANDLE](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) that specifies the RPC binding to the DHCP server that will be queried.

### `UnameSize` [in]

Unsigned 32-bit integer that indicates the size, in bytes, to allocate for the data returned in the *Uname* buffer.

### `Uname` [out]

Pointer to a null-terminated Unicode string that contains the user name for the DNS server credentials. The size of this value cannot be larger than the size specified in *UnameSize*.

### `DomainSize` [in]

Unsigned 32-bit integer that indicates the size, in bytes, to allocate for the data returned in the *Domain* buffer.

### `Domain` [out]

Pointer to a null-terminated Unicode string that contains the domain name for the DNS server credentials. The size of this value cannot be larger than the size specified in *DomainSize*.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

## Remarks

DNS credentials can be set on the DHCP server by calling the [DhcpServerSetDnsRegCredentialsV5](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpserversetdnsregcredentialsv5) function.

## See also

[DhcpServerSetDnsRegCredentialsV5](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpserversetdnsregcredentialsv5)