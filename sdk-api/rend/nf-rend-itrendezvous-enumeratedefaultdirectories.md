# ITRendezvous::EnumerateDefaultDirectories

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**EnumerateDefaultDirectories** method enumerates all configured default directories. This method is similar to
[get_DefaultDirectories](https://learn.microsoft.com/windows/desktop/api/rend/nf-rend-itrendezvous-get_defaultdirectories) but is designed for C/C++.

## Parameters

### `ppEnumDirectory` [out]

Pointer to receive
[IEnumDirectory](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-ienumdirectory) enumerator listing default directories.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | Pointer is invalid. |

## Remarks

TAPI calls the **AddRef** method on the
[IEnumDirectory](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-ienumdirectory) interface returned by **ITRendezvous::EnumerateDefaultDirectories**. The application must call **Release** on the
**IEnumDirectory** interface to free resources associated with it.

## See also

[IEnumDirectory](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-ienumdirectory)

[ITRendezvous](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itrendezvous)