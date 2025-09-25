# MCAST_LEASE_RESPONSE structure

## Description

The
**MCAST_LEASE_RESPONSE** structure is used to respond to multicast lease requests.

## Members

### `LeaseStartTime`

Start time, in seconds, for the multicast scope lease elapsed since midnight of January 1, 1970, coordinated universal time.

### `LeaseEndTime`

Expiration time, in seconds of the multicast scope lease elapsed since midnight of January 1, 1970, coordinated universal time.

### `ServerAddress`

Internet Protocol (IP) address of the server on which the lease request has been granted or renewed, in the form of an
[IPNG_ADDRESS](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-ipng_address) structure.

### `AddrCount`

Number of IP addresses that are granted or renewed with the lease. Note that the value of this member dictates the size of **pAddrBuf**.

### `pAddrBuf`

Pointer to a buffer containing the granted IP addresses. For IPv4 addresses, the **pAddrBuf** member points to 4-byte addresses; for IPv6 addresses, the **pAddrBuf** member points to 16-byte addresses.

## See also

[IPNG_ADDRESS](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-ipng_address)

[MCAST_CLIENT_UID](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_client_uid)

[MCAST_LEASE_REQUEST](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_lease_request)

[MCAST_SCOPE_CTX](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_scope_ctx)

[MCAST_SCOPE_ENTRY](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_scope_entry)

[McastApiCleanup](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastapicleanup)

[McastApiStartup](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastapistartup)

[McastEnumerateScopes](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastenumeratescopes)

[McastGenUID](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastgenuid)

[McastRequestAddress](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastrequestaddress)