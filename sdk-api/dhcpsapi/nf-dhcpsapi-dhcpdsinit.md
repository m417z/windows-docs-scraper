# DhcpDsInit function

## Description

The **DhcpDsInit** function initializes memory within the directory service for a new DHCP server process.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

## Remarks

This function is called once per process.

## See also

[DhcpDsCleanup](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpdscleanup)