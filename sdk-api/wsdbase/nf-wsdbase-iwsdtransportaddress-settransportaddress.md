# IWSDTransportAddress::SetTransportAddress

## Description

Sets the string representation of the transport address. The format of the string varies, and is determined by the implementing interface (either [IWSDHttpAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdhttpaddress) or [IWSDUdpAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdudpaddress)).

## Parameters

### `pszAddress` [in]

String representation of the transport address.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | The length in characters of the address string pointed to by *ppszAddress* exceeds WSD_MAX_TEXT_LENGTH (8192), *ppszAddress* is **NULL**, or the format of *ppszAddress* was not recognized. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## See also

[IWSDTransportAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdtransportaddress)