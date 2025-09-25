# MCAST_SCOPE_ENTRY structure

## Description

The
**MCAST_SCOPE_ENTRY** structure provides a complete set of information about a given multicast scope.

## Members

### `ScopeCtx`

Handle for the multicast scope, in the form of an
[MCAST_SCOPE_CTX](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_scope_ctx) structure.

### `LastAddr`

Internet Protocol (IP) address of the last address in the scope, in the form of an
[IPNG_ADDRESS](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-ipng_address) structure.

### `TTL`

Time To Live (TTL) value of the scope.

### `ScopeDesc`

Description of the scope, in human readable, user-friendly format.

## See also

[IPNG_ADDRESS](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-ipng_address)

[MCAST_CLIENT_UID](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_client_uid)

[MCAST_LEASE_REQUEST](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_lease_request)

[MCAST_LEASE_RESPONSE](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_lease_response)

[MCAST_SCOPE_CTX](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_scope_ctx)

[McastApiCleanup](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastapicleanup)

[McastApiStartup](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastapistartup)

[McastEnumerateScopes](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastenumeratescopes)

[McastGenUID](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastgenuid)

[McastReleaseAddress](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastreleaseaddress)

[McastRenewAddress](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastrenewaddress)

[McastRequestAddress](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastrequestaddress)

[UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string)