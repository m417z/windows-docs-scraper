# MCAST_SCOPE_CTX structure

## Description

The
**MCAST_SCOPE_CTX** structure defines the scope context for programmatic interaction with multicast addresses. The
**MCAST_SCOPE_CTX** structure is used by various MADCAP functions as a handle for allocating, renewing, or releasing MADCAP addresses.

## Members

### `ScopeID`

Identifier for the multicast scope, in the form of an
[IPNG_ADDRESS](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-ipng_address) structure.

### `Interface`

Interface on which the multicast scope is available, in the form of an
[IPNG_ADDRESS](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-ipng_address) structure.

### `ServerID`

Internet Protocol (IP) address of the MADCAP server, in the form of an
[IPNG_ADDRESS](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-ipng_address) structure.

## See also

[IPNG_ADDRESS](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-ipng_address)

[MCAST_CLIENT_UID](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_client_uid)

[MCAST_LEASE_REQUEST](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_lease_request)

[MCAST_LEASE_RESPONSE](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_lease_response)

[MCAST_SCOPE_ENTRY](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_scope_entry)

[McastApiCleanup](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastapicleanup)

[McastApiStartup](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastapistartup)

[McastEnumerateScopes](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastenumeratescopes)

[McastGenUID](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastgenuid)

[McastReleaseAddress](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastreleaseaddress)

[McastRenewAddress](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastrenewaddress)

[McastRequestAddress](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastrequestaddress)