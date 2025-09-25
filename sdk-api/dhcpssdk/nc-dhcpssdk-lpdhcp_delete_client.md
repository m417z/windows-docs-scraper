# LPDHCP_DELETE_CLIENT callback function

## Description

The
**DhcpDeleteClientHook** function is called by Microsoft DHCP Server directly before a client lease is deleted from the active leases database.

The
**DhcpDeleteClientHook** function should not block.

## Parameters

### `IpAddress` [in]

Internet Protocol (IP) address of the client lease being deleted. The IP address is in host order.

### `HwAddress` [in]

Buffer holding the Hardware address of the client, often referred to as the MAC address.

### `HwAddressLength` [in]

Length of the *HwAddress* buffer, in bytes.

### `Reserved` [in]

Reserved for future use.

### `ClientType` [in]

Reserved for future use.

## Return value

Return values are defined by the application providing the callback.

## Remarks

The
**DhcpDeleteClientHook** function should not block.

## See also

[DHCP_CALLOUT_TABLE](https://learn.microsoft.com/windows/desktop/api/dhcpssdk/ns-dhcpssdk-dhcp_callout_table)