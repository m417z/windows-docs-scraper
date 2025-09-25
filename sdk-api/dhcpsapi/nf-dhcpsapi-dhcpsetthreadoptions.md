# DhcpSetThreadOptions function

## Description

The **DhcpSetThreadOptions** function sets options on the currently executing DHCP thread.

## Parameters

### `Flags` [in]

Set of bit flags indicating thread settings. If no thread options are set, the value is 0. Currently, the only bit flag that can be set is as follows.

| Value | Meaning |
| --- | --- |
| **DHCP_FLAGS_DONT_ACCESS_DS** | Do not access the directory service while the DHCP thread is executing. After this option is set, the only functions that can access the domain directory service are as follows:<br><br>* [DhcpEnumServers](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpenumservers)<br>* [DhcpAddServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpaddserver)<br>* [DhcpDeleteServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpdeleteserver) |

### `Reserved` [in]

Reserved. This parameter must be set to **NULL**.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

## Remarks

**DhcpSetThreadOptions** currently allows only one option to be set.

## See also

[DhcpGetThreadOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpgetthreadoptions)