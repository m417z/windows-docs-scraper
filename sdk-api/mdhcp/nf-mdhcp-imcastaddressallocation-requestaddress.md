# IMcastAddressAllocation::RequestAddress

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**RequestAddress** method obtains a new lease for one or more multicast addresses. The
[EnumerateScopes](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastaddressallocation-enumeratescopes) or
[get_Scopes](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastaddressallocation-get_scopes) method must be called first.

## Parameters

### `pScope` [in]

Identifies the multicast scope from which the application needs an address. The application first calls
[get_Scopes](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastaddressallocation-get_scopes) or
[EnumerateScopes](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastaddressallocation-enumeratescopes) to obtain a list of available scopes.

### `LeaseStartTime` [in]

Requested time for the lease on these addresses to start. The start time that is actually granted may be different.

### `LeaseStopTime` [in]

Requested time for the lease on these addresses to stop. The stop time that is actually granted may be different.

### `NumAddresses` [in]

The number of addresses requested. Fewer addresses may actually be granted.

### `ppLeaseResponse` [out]

Pointer to an interface pointer that will be set to point to a new
[IMcastLeaseInfo](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-imcastleaseinfo) object. This interface can then be used to discover the actual attributes of the granted lease. See
[IMcastScope](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-imcastscope) for more information.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The caller passed in an invalid pointer argument. |
| **E_OUTOFMEMORY** | Not enough memory exists to create the required objects. |
| **E_INVALIDARG** | Requested stop time is prior to requested stop time. |

## Remarks

Although these COM interfaces and their implementation support allocation of multiple addresses at a time, multiple allocation is not currently supported by the underlying function calls. You may need to use a loop for multiple address allocation.

TAPI calls the **AddRef** method on the
[IMcastLeaseInfo](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-imcastleaseinfo) interface returned by **IMcastAddressAllocation::RequestAddress**. The application must call **Release** on the
**IMcastLeaseInfo** interface to free resources associated with it.

## See also

[IMcastAddressAllocation](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-imcastaddressallocation)