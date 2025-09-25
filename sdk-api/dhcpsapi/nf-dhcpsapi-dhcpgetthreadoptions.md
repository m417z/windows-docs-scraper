# DhcpGetThreadOptions function

## Description

The **DhcpGetThreadOptions** function retrieves the current thread options as set by [DhcpSetThreadOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpsetthreadoptions).

## Parameters

### `pFlags` [out]

Set of bit flags as set by a previous call to [DhcpSetThreadOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpsetthreadoptions). If no thread options are set, the return value is 0. Currently, the only bit flag that can be set is as follows.

| Value | Meaning |
| --- | --- |
| **DHCP_FLAGS_DONT_ACCESS_DS** | Do not access the directory service while the DHCP thread is executing. After this option is set, the only functions that can access the domain directory service are:<br><br>* [DhcpEnumServers](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpenumservers)<br>* [DhcpAddServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpaddserver)<br>* [DhcpDeleteServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpdeleteserver) |

### `Reserved` [out]

Reserved. This parameter must be set to null.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

## See also

[DhcpSetThreadOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpsetthreadoptions)