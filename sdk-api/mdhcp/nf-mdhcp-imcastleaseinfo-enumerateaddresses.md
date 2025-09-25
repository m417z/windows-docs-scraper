# IMcastLeaseInfo::EnumerateAddresses

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**EnumerateAddresses** method obtains the collection of multicast addresses that are the subject of this lease or lease request. This method is primarily for C++ programmers. Visual Basic and other scripting languages use
[get_Addresses](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastleaseinfo-get_addresses) instead.

## Parameters

### `ppEnumAddresses` [out]

Returns a pointer to a new
[IEnumBstr](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumbstr) object.
**IEnumBstr** is a standard enumerator interface that enumerates BSTR strings. Each string is an IP version 4 address in dotted quad notation (for example, 10.111.222.111).

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The caller passed in an invalid pointer argument. |
| **E_OUTOFMEMORY** | Not enough memory to allocate the enumerator. |

## Remarks

TAPI calls the **AddRef** method on the
[IEnumBstr](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumbstr) interface returned by **IMcastLeaseInfo::EnumerateAddresses**. The application must call **Release** on the
**IEnumBstr** interface to free resources associated with it.

## See also

[IEnumBstr](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumbstr)

[IMcastLeaseInfo](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-imcastleaseinfo)

[get_Addresses](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastleaseinfo-get_addresses)