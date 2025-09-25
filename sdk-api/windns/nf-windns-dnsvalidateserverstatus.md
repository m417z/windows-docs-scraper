# DnsValidateServerStatus function

## Description

The
**DnsValidateServerStatus** function validates an IP address as a suitable DNS server.

## Parameters

### `server` [in]

A pointer to a [SOCKADDR](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) that contains the DNS server IPv4 or IPv6 address to be examined.

### `queryName` [in]

 A pointer to a Unicode string that represents the fully qualified domain name (FQDN) of the owner of the record set that is queried.

### `serverStatus` [out]

 A pointer to a DWORD that represents the query validation status.

| Value | Meaning |
| --- | --- |
| **ERROR_SUCCESS** | No errors. The call was successful. |
| **DNS_VALSVR_ERROR_INVALID_ADDR** | *server* IP address was invalid. |
| **DNS_VALSVR_ERROR_INVALID_NAME** | *queryName* FQDN was invalid. |
| **DNS_VALSVR_ERROR_UNREACHABLE** | DNS server was unreachable. |
| **DNS_VALSVR_ERROR_NO_RESPONSE** | Timeout waiting for the DNS server response. |
| **DNS_VALSVR_ERROR_NO_AUTH** | DNS server was not authoritative or *queryName* was not found. |
| **DNS_VALSVR_ERROR_REFUSED** | DNS server refused the query. |
| **DNS_VALSVR_ERROR_NO_TCP** | The TCP query did not return ERROR_SUCCESS after the validation system had already completed a successful query to the DNS server using UDP. |
| **DNS_VALSVR_ERROR_UNKNOWN** | An unknown error occurred. |

## Return value

The
**DnsValidateServerStatus** function has the following possible return values:

## See also

[DNS Functions](https://learn.microsoft.com/windows/desktop/DNS/dns-functions)