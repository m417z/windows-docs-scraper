# Dhcpv6CApiInitialize function

## Description

The
**Dhcpv6CApiInitialize** function must be the first function call made by users of DHCPv6. The function prepares the system for all other DHCPv6 function calls. Other DHCPv6 functions should only be called if the
**Dhcpv6CApiInitialize** function executes successfully.

## Parameters

### `Version` [out]

Pointer to the DHCPv6 version implemented by the client. If a valid pointer is passed, the DHCPv6 client will be returned through it.

## Return value

Returns ERROR_SUCCESS upon successful completion.

## See also

[DHCP Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-functions)

[Dhcpv6CApiCleanup](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpv6csdk/nf-dhcpv6csdk-dhcpv6capicleanup)