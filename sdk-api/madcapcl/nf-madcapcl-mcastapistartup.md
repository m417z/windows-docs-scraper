# McastApiStartup function

## Description

The
**McastApiStartup** function facilitates MADCAP-version negotiation between requesting clients and the version of MADCAP implemented on the system. Calling
**McastApiStartup** allocates necessary resources; it must be called before any other MADCAP client functions are called.

## Parameters

### `Version` [in]

Pointer to the version of multicast (MCAST) that the client wishes to use.

[out] Pointer to the version of MCAST implemented on the system.

## Return value

If the client requests a version of MADCAP that is not supported by the system, the
**McastApiStartup** function returns ERROR_NOT_SUPPORTED. If resources fail to be allocated for the function call, ERROR_NO_SYSTEM_RESOURCES is returned.

## Remarks

Clients can specify which version they want to use in the *pVersion* parameter. If the system's implementation supports the requested MCAST version, the function call succeeds. If the system's implementation does not support the requested version, the function fails with MCAST_API_CURRENT_VERSION.

The client can automatically negotiate the first version of MCAST (MCAST_API_VERSION_1) by setting the *pVersion* parameter to zero.

The
**McastApiStartup** function always returns the most recent version of MADCAP available on the system (MCAST_API_CURRENT_VERSION) in *pVersion*, enabling clients to discover the most recent version implemented on the system.

## See also

[IPNG_ADDRESS](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-ipng_address)

[MCAST_CLIENT_UID](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_client_uid)

[MCAST_LEASE_REQUEST](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_lease_request)

[MCAST_LEASE_RESPONSE](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_lease_response)

[MCAST_SCOPE_CTX](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_scope_ctx)

[MCAST_SCOPE_ENTRY](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_scope_entry)

[McastApiCleanup](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastapicleanup)

[McastEnumerateScopes](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastenumeratescopes)

[McastGenUID](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastgenuid)

[McastReleaseAddress](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastreleaseaddress)

[McastRenewAddress](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastrenewaddress)

[McastRequestAddress](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastrequestaddress)