# DHCPV6PrefixLeaseInformation structure

## Description

The **DHCPV6PrefixLeaseInformation** structure contains information about a prefix lease.

## Members

### `nPrefixes`

Number of prefixes.

### `prefixArray`

Pointer to a list [DHCPV6Prefix](https://learn.microsoft.com/windows/desktop/api/dhcpv6csdk/ns-dhcpv6csdk-dhcpv6prefix) structures that contain the prefixes requested or returned by the server.

### `iaid`

Identity Association identifier for the prefix operation.

### `T1`

The renewal time for the prefix, in seconds.

### `T2`

The rebind time of the prefix, in seconds.

### `MaxLeaseExpirationTime`

The maximum lease expiration time of all the prefix leases in this structure.

### `LastRenewalTime`

The time at which the last renewal for the prefixes occurred.

### `status`

Status code returned by the server for the IAPD. The following codes can be returned by the DHCP server for prefix delegation scenarios:

| Value | Meaning |
| --- | --- |
| **STATUS_NO_ERROR**<br><br>0 | The prefix was successfully leased or renewed. |
| **STATUS_UNSPECIFIED_FAILURE**<br><br>1 | The lease or renewal action failed for an unspecified reason. |
| **STATUS_NO_BINDING**<br><br>3 | The DHCPv6 server does not have a binding for the prefix. |
| **STATUS_NOPREFIX_AVAIL**<br><br>6 | The DHCPv6 server does not have a prefix available to offer the requesting client. |

### `ServerId`

The server DUID from which the prefix is received. This data is used in subsequent renews.

### `ServerIdLen`

The length of the above DUID data.

## Remarks

In a prefix delegation scenario, the validation of lease lifetime values (specific status codes, **T1**, **T2**, **MaxLeaseExpirationTime**, and **LastRenewalTime**) are performed by the calling API, rather than the application consuming the data, as the latter might interpret these values differently.