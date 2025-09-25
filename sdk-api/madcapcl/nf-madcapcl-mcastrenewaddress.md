# McastRenewAddress function

## Description

The
**McastRenewAddress** function renews one or more multicast addresses from a MADCAP server.

## Parameters

### `AddrFamily` [in]

Designates the address family. Use AF_INET for Internet Protocol version 4 (IPv4), and AF_INET6 for Internet Protocol version 6 (IPv6).

### `pRequestID` [in]

Unique identifier used when the address or addresses were initially obtained.

### `pRenewRequest` [in]

Pointer to the
[MCAST_LEASE_REQUEST](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_lease_request) structure containing multicast renew–request parameters.

### `pRenewResponse` [in, out]

Pointer to a buffer containing response parameters for the multicast address–renew request, in the form of an
[MCAST_LEASE_RESPONSE](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_lease_response) structure. The caller is responsible for allocating sufficient buffer space for the **pAddrBuf** member of the
**MCAST_LEASE_RESPONSE** structure to hold the requested number of addresses; the caller is also responsible for setting the pointer to that buffer.

## Return value

The
**McastRenewAddress** function returns the status of the operation.

## See also

[IPNG_ADDRESS](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-ipng_address)

[MCAST_CLIENT_UID](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_client_uid)

[MCAST_LEASE_REQUEST](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_lease_request)

[MCAST_LEASE_RESPONSE](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_lease_response)

[MCAST_SCOPE_CTX](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_scope_ctx)

[MCAST_SCOPE_ENTRY](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_scope_entry)

[McastApiCleanup](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastapicleanup)

[McastApiStartup](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastapistartup)

[McastEnumerateScopes](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastenumeratescopes)

[McastGenUID](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastgenuid)

[McastReleaseAddress](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastreleaseaddress)

[McastRequestAddress](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastrequestaddress)