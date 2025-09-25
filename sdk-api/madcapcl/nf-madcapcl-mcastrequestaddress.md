# McastRequestAddress function

## Description

The
**McastRequestAddress** function requests one or more multicast addresses from a MADCAP server.

## Parameters

### `AddrFamily` [in]

Specifies the address family to be used in the request, in the form of an
[IPNG_ADDRESS](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-ipng_address) structure. Use AF_INET for IPv4 addresses and AF_INET6 for IPv6 addresses.

### `pRequestID` [in]

Pointer to a unique identifier for the request, in the form of an
[MCAST_CLIENT_UID](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_client_uid) structure. Clients are responsible for ensuring that each request contains a unique identifier; unique identifiers can be obtained by calling the
[McastGenUID](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastgenuid) function.

### `pScopeCtx` [in]

Pointer to the context of the scope from which the address is to be allocated, in the form of an
[MCAST_SCOPE_CTX](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_scope_ctx) structure. The scope context must be retrieved by calling the
[McastEnumerateScopes](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastenumeratescopes) function prior to calling the
**McastRequestAddress** function.

### `pAddrRequest` [in]

Pointer to the
[MCAST_LEASE_REQUEST](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_lease_request) structure containing multicast lease–request parameters.

### `pAddrResponse` [in, out]

Pointer to a buffer containing response parameters for the multicast address request, in the form of an
[MCAST_LEASE_RESPONSE](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_lease_response) structure. The caller is responsible for allocating sufficient buffer space for the *pAddrBuf* member of the
**MCAST_LEASE_RESPONSE** structure to hold the requested number of addresses; the caller is also responsible for setting the pointer to that buffer.

## Return value

The
**McastRequestAddress** function returns the status of the operation.

## Remarks

Before the
**McastRequestAddress** function is called, the scope context must be retrieved by calling the
[McastEnumerateScopes](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastenumeratescopes) function.

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

[McastRenewAddress](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastrenewaddress)