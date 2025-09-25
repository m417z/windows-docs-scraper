# IMcastAddressAllocation::get_Scopes

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**get_Scopes** method creates a collection of IMcast scopes available. This method is similar to
[EnumerateScopes](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastaddressallocation-enumeratescopes), but is used by scripting languages such as Visual Basic.

## Parameters

### `pVariant` [out]

Pointer to a **VARIANT** receiving an
[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection) of
[IMcastScope](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-imcastscope) interface pointers.

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
[IMcastScope](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-imcastscope) interface returned by **IMcastAddressAllocation::get_Scopes**. The application must call **Release** on the
**IMcastScope** interface to free resources associated with it.

## See also

[IMcastAddressAllocation](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-imcastaddressallocation)

[IMcastScope](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-imcastscope)

[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection)