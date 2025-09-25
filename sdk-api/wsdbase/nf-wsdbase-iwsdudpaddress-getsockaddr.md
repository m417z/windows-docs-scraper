# IWSDUdpAddress::GetSockaddr

## Description

Gets the socket address information.

## Parameters

### `pSockAddr` [out]

Pointer to a [SOCKADDR_STORAGE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms740504(v=vs.85)) structure that contains the address information.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *pSockAddr* is **NULL**. |
| **E_FAIL** | The method failed. |

## See also

[IWSDUdpAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdudpaddress)