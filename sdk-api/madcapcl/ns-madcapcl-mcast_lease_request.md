# MCAST_LEASE_REQUEST structure

## Description

The
**MCAST_LEASE_REQUEST** structure defines the request, renew, or release parameters for a given multicast scope. In the MCAST_API_VERSION_1 implementation, only one IP address may be allocated at a time.

## Members

### `LeaseStartTime`

Requested start time, in seconds, for the multicast scope lease elapsed since midnight of January 1, 1970, coordinated universal time. To request the current time as the lease start time, set **LeaseStartTime** to zero.

### `MaxLeaseStartTime`

Maximum start time, in seconds, elapsed since midnight of January 1, 1970, coordinated universal time, that the client is willing to accept.

### `LeaseDuration`

Duration of the lease request, in seconds. To request the default lease duration, set both **LeaseDuration** and **MinLeaseDuration** to zero.

### `MinLeaseDuration`

Minimum lease duration, in seconds, that the client is willing to accept.

### `ServerAddress`

Internet Protocol (IP) address of the server on which the lease is to be requested or renewed, in the form of an
[IPNG_ADDRESS](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-ipng_address) structure. If the IP address of the server is unknown, such as when using this structure in an
[McastRequestAddress](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastrequestaddress) function call, set **ServerAddress** to zero.

### `MinAddrCount`

Minimum number of IP addresses the client is willing to accept.

### `AddrCount`

Number of requested IP addresses. Note that the value of this member dictates the size of **pAddrBuf**.

### `pAddrBuf`

Pointer to a buffer containing the requested IP addresses. For IPv4 addresses, the **pAddrBuf** member points to 4-byte addresses; for IPv6 addresses, the **pAddrBuf** member points to 16-byte addresses. If no specific addresses are requested, set **pAddrBuf** to **NULL**.

## Remarks

In MCAST_API_VERSION_1 version, **MaxLeaseStartTime**, **MinLeaseDuration**, and **MinAddrCount** members are ignored. Clients should still set appropriate values for these members, however, to take advantage of their implementation in future updates.

## See also

[IPNG_ADDRESS](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-ipng_address)

[MCAST_CLIENT_UID](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_client_uid)

[MCAST_LEASE_RESPONSE](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_lease_response)

[MCAST_SCOPE_CTX](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_scope_ctx)

[MCAST_SCOPE_ENTRY](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_scope_entry)

[McastApiCleanup](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastapicleanup)

[McastApiStartup](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastapistartup)

[McastEnumerateScopes](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastenumeratescopes)

[McastGenUID](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastgenuid)

[McastRequestAddress](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastrequestaddress)