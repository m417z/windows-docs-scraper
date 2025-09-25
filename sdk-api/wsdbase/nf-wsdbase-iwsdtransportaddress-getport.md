# IWSDTransportAddress::GetPort

## Description

Gets the IP port number associated with this transport address.

## Parameters

### `pwPort` [out]

Port number associated with the address object.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *pwPort* is **NULL**. |

## See also

[IWSDTransportAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdtransportaddress)