# IWSDUdpAddress::SetTTL

## Description

Sets the time-to-live (TTL) for all outbound packets using this address.

## Parameters

### `dwTTL` [in]

The TTL of outgoing UDP packets. Generally, the TTL represents the maximum number of hops before a packet is discarded. Some implementations interpret the TTL differently.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | *dwTTL* is greater than 255. |

## See also

[IWSDUdpAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdudpaddress)