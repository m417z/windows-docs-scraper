# IMcastLeaseInfo::get_Addresses

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

 The
**get_Addresses** method obtains the collection of multicast addresses that are the subject of this lease or lease request. This method is primarily for Visual Basic and other scripting languages; C++ programmers use
[EnumerateAddresses](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastleaseinfo-enumerateaddresses) instead.

## Parameters

### `pVariant` [out]

Pointer to a **VARIANT** receiving an
[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection) of **BSTR** strings. Each string is an IP version 4 address in dotted quad notation (for example, 10.111.222.111).

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The caller passed in an invalid pointer argument. |
| **E_OUTOFMEMORY** | Not enough memory to allocate the collection. |

## Remarks

Each address is an IP version 4 address represented as a **BSTR** in dotted quad notation (for example, 10.111.222.111).

TAPI calls the **AddRef** method on the
[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress) interface returned by **IMcastLeaseInfo::get_Addresses**. The application must call **Release** on the
**ITAddress** interface to free resources associated with it.

This function may send data over the wire in unencrypted form; therefore, someone eavesdropping on the network may be able to read the data. The security risk of sending the data in clear text should be considered before using this method.

## See also

[EnumerateAddresses](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastleaseinfo-enumerateaddresses)

[IMcastLeaseInfo](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-imcastleaseinfo)

[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress)