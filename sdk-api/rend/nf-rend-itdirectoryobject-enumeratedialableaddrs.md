# ITDirectoryObject::EnumerateDialableAddrs

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**EnumerateDialableAddrs** method creates an enumerator of all dialable addresses of a given type from the directory.

## Parameters

### `dwAddressType` [in]

Indicator of the address type.

### `ppEnumDialableAddrs` [out]

Pointer to the
[IEnumDialableAddrs](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-ienumdialableaddrs) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **ERROR** | Method failed. |

## Remarks

TAPI calls the **AddRef** method on the
[IEnumDialableAddrs](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-ienumdialableaddrs) interface returned by **ITDirectoryObject::EnumerateDialableAddrs**. The application must call **Release** on the
**IEnumDialableAddrs** interface to free resources associated with it.

## See also

[IEnumDialableAddrs](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-ienumdialableaddrs)

[ITDirectoryObject](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectoryobject)