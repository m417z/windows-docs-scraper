# IWSDUdpAddress::GetTTL

## Description

Gets the time-to-live (TTL) for all outbound packets using this address.

## Parameters

### `pdwTTL` [out]

Pointer to the TTL of outgoing UDP packets. Generally, the TTL represents the maximum number of hops before a packet is discarded. Some implementations interpret the TTL differently.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *pdwTTL* is **NULL**. |

## See also

[IWSDUdpAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdudpaddress)