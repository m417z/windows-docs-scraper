# IWSDTransportAddress::GetTransportAddressEx

## Description

Gets a pointer to a string representation of the address object. The format of the string varies, and is determined by the implementing interface (either [IWSDHttpAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdhttpaddress) or [IWSDUdpAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdudpaddress)).

## Parameters

### `fSafe` [in]

Specifies whether the scope identifier for an IPv6 address is included in the returned *ppszAddress* string. For example, if the address object represents an IPv6 link local address and *fSafe* is **FALSE**, then the IPv6 scope identifier will be included in the returned *ppszAddress* string.

If the address object represents an IPv4 address or a host name, this parameter is ignored.

### `ppszAddress` [out]

String representation of the address object. Do not deallocate this pointer.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *ppszAddress* is **NULL**. |
| **S_FALSE** | The transport address has not yet been set. To set the transport address, call [SetTransportAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nf-wsdbase-iwsdtransportaddress-settransportaddress) with a non-**NULL** address. |

## Remarks

The string returned by this method may contain an IPv4 or unbracketed IPv6 address such as "fe80::1". It may also contain a bracketed IPv6 address that includes the port such as "[fe80::1]:1234". The caller should parse the string carefully to account for both possibilities.

## See also

[IWSDTransportAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdtransportaddress)