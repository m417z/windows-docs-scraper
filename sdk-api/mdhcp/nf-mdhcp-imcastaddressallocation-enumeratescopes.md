# IMcastAddressAllocation::EnumerateScopes

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**EnumerateScopes** method creates an enumeration of multicast scopes available. This method is primarily for C++ programmers. Visual Basic and other scripting languages use
[get_Scopes](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastaddressallocation-get_scopes) instead.

## Parameters

### `ppEnumMcastScope` [out]

Returns a pointer to a new
[IEnumMcastScope](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-ienummcastscope) object.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The caller passed in an invalid pointer argument. |
| **E_FAIL** | There are no scopes available. |
| **E_OUTOFMEMORY** | Not enough memory exists to create the required objects. |

## Remarks

TAPI calls the **AddRef** method on the
[IEnumMcastScope](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-ienummcastscope) interface returned by **IMcastAddressAllocation::EnumerateScopes**. The application must call **Release** on the
**IEnumMcastScope** interface to free resources associated with it.

## See also

[IMcastAddressAllocation](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-imcastaddressallocation)