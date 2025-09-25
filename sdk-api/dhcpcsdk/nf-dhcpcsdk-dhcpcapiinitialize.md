# DhcpCApiInitialize function

## Description

The
**DhcpCApiInitialize** function must be the first function call made by users of DHCP; it prepares the system for all other DHCP function calls. Other DHCP functions should only be called if the
**DhcpCApiInitialize** function executes successfully.

## Parameters

### `Version` [out]

Pointer to the DHCP version implemented by the client.

## Return value

Returns ERROR_SUCCESS upon successful completion.

## See also

[DHCP Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-functions)

[DhcpCApiCleanup](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpcsdk/nf-dhcpcsdk-dhcpcapicleanup)