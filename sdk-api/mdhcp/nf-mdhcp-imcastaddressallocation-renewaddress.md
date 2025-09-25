# IMcastAddressAllocation::RenewAddress

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

 The
**RenewAddress** method renews an address lease. Call
[CreateLeaseInfo](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastaddressallocation-createleaseinfo) to specify the parameters of the renewal request, and then call this method to make the request.

## Parameters

### `lReserved` [in]

Reserved parameter. An application should pass in a value of 0.

### `pRenewRequest` [in]

Pointer to an
[IMcastLeaseInfo](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-imcastleaseinfo) object specifying the attributes of the requested renewal, such as which address(es) to renew. This is obtained by calling
[CreateLeaseInfo](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastaddressallocation-createleaseinfo).

### `ppRenewResponse` [out]

Pointer to an interface pointer that will be set to point to a new
[IMcastLeaseInfo](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-imcastleaseinfo) object. This interface can then be used to discover the attributes of the renewed lease. See
[IMcastScope](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-imcastscope) for more information.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The caller passed in an invalid pointer argument. |
| **E_INVALIDARG** | Requested stop time is prior to the requested stop time. |
| **E_OUTOFMEMORY** | Not enough memory to create the required objects. |

## See also

[IMcastAddressAllocation](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-imcastaddressallocation)