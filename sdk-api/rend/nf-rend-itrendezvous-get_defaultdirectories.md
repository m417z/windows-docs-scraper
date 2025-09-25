# ITRendezvous::get_DefaultDirectories

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**get_DefaultDirectories** method enumerates all configured default directories. This method is similar to
[EnumerateDefaultDirectories](https://learn.microsoft.com/windows/desktop/api/rend/nf-rend-itrendezvous-enumeratedefaultdirectories) but is provided for use by Visual Basic and other scripting languages.

## Parameters

### `pVariant` [out]

Pointer to a **VARIANT** that will receive an
[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection) of
[ITDirectory](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectory) interface pointers.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to create a collection. |
| **E_POINTER** | Pointer is invalid. |

## Remarks

TAPI calls the **AddRef** method on the
[ITDirectory](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectory) interface returned by **ITRendezvous::get_DefaultDirectories**. The application must call **Release** on the
**ITDirectory** interface to free resources associated with it.

## See also

[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection)

[ITDirectory](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectory)

[ITRendezvous](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itrendezvous)