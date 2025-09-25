# ITDirectoryObject::get_DialableAddrs

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**get_DialableAddrs** method gets all dialable addresses of a given type from the directory. This method performs the same function as
[EnumerateDialableAddrs](https://learn.microsoft.com/windows/desktop/api/rend/nf-rend-itdirectoryobject-enumeratedialableaddrs) but is used by scripting languages such as Visual Basic.

## Parameters

### `dwAddressType` [in]

Indicator of address type.

### `pVariant` [out]

Pointer to a **VARIANT** containing an
[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection) of **BSTR** strings, each containing a dialable address.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **ERROR** | Method failed. |

## Remarks

TAPI calls the **AddRef** method on the
[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress) interface returned by **ITDirectoryObject::get_DialableAddrs**. The application must call **Release** on the
**ITAddress** interface to free resources associated with it.

## See also

[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress)

[ITDirectoryObject](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectoryobject)