# IEnumDialableAddrs::Clone

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**Clone** method creates another enumerator that contains the same enumeration state as the current one.

## Parameters

### `ppEnum` [out]

Pointer to the new
[IEnumDialableAddrs](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-ienumdialableaddrs) object.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppEnum* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_UNEXPECTED** | Failed for unknown reasons. |

## Remarks

TAPI calls the **AddRef** method on the
[IEnumDialableAddrs](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-ienumdialableaddrs) interface returned by **IEnumDialableAddrs::Clone**. The application must call **Release** on the
**IEnumDialableAddrs** interface to free resources associated with it.

## See also

[IEnumDialableAddrs](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-ienumdialableaddrs)