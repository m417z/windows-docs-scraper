# McastEnumerateScopes function

## Description

The
**McastEnumerateScopes** function enumerates multicast scopes available on the network.

## Parameters

### `AddrFamily` [in]

Specifies the address family to be used in enumeration, in the form of an
[IPNG_ADDRESS](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-ipng_address) structure. Use AF_INET for IPv4 addresses and AF_INET6 for IPv6 addresses.

### `ReQuery` [in]

Enables a caller to query a list again. Set this parameter to **TRUE** if the list is to be queried more than once. Otherwise, set it to **FALSE**.

### `pScopeList` [in, out]

Pointer to a buffer used for storing scope list information, in the form of an
[MCAST_SCOPE_ENTRY](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_scope_entry) structure. The return value of *pScopeList* depends on its input value, and on the value of the buffer to which it points:

If *pScopeList* is a valid pointer on input, the scope list is returned.

If *pScopeList* is **NULL** on input, the length of the buffer required to hold the scope list is returned.

If the buffer pointed to in *pScopeList* is **NULL** on input,
**McastEnumerateScopes** forces a repeat querying of scope lists from MCAST servers.

To determine the size of buffer required to hold scope list data, set *pScopeList* to **NULL** and *pScopeLen* to a non-**NULL** value. The
**McastEnumerateScopes** function will then return ERROR_SUCCESS and store the size of the scope list data, in bytes, in *pScopeLen*.

### `pScopeLen` [in, out]

Pointer to a value used to communicate the size of data or buffer space in *pScopeList*. On input, *pScopeLen* points to the size, in bytes, of the buffer pointed to by *pScopeList*. On return, *pScopeLen* points to the size of the data copied to *pScopeList*.

The *pScopeLen* parameter cannot be **NULL**. If the buffer pointed to by *pScopeList* is not large enough to hold the scope list data,
**McastEnumerateScopes** returns ERROR_MORE_DATA and stores the required buffer size, in bytes, in *pScopeLen*.

To determine the size of buffer required to hold scope list data, set *pScopeList* to **NULL** and *pScopeLen* to a non-**NULL** value. The
**McastEnumerateScopes** function will then return ERROR_SUCCESS and store the size of the scope list data, in bytes, in *pScopeLen*.

### `pScopeCount` [out]

Pointer to the number of scopes returned in *pScopeList*.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the buffer pointed to by *pScopeList* is too small to hold the scope list, the
**McastEnumerateScopes** function returns ERROR_MORE_DATA, and stores the required buffer size, in bytes, in *pScopeLen*.

If the
[McastApiStartup](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastapistartup) function has not been called (it must be called before any other MADCAP client functions may be called), the
**McastEnumerateScopes** function returns ERROR_NOT_READY.

## Remarks

The
**McastEnumerateScopes** function queries multicast scopes for each network interface, and the interface on which the scope is retrieved is returned as part of the *pScopeList* parameter. Therefore, on multihomed computers it is possible that some scopes will get listed multiple times, once for each interface.

## See also

[IPNG_ADDRESS](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-ipng_address)

[MCAST_CLIENT_UID](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_client_uid)

[MCAST_LEASE_REQUEST](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_lease_request)

[MCAST_LEASE_RESPONSE](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_lease_response)

[MCAST_SCOPE_CTX](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_scope_ctx)

[MCAST_SCOPE_ENTRY](https://learn.microsoft.com/windows/desktop/api/madcapcl/ns-madcapcl-mcast_scope_entry)

[McastApiCleanup](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastapicleanup)

[McastApiStartup](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastapistartup)

[McastGenUID](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastgenuid)

[McastReleaseAddress](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastreleaseaddress)

[McastRenewAddress](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastrenewaddress)

[McastRequestAddress](https://learn.microsoft.com/previous-versions/windows/desktop/api/madcapcl/nf-madcapcl-mcastrequestaddress)