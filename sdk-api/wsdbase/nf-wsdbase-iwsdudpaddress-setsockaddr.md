# IWSDUdpAddress::SetSockaddr

## Description

Sets the socket address information.

## Parameters

### `pSockAddr` [in]

Pointer to a [SOCKADDR_STORAGE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms740504(v=vs.85)) structure.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | *pSockAddr* is **NULL**. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **HRESULT_FROM_WIN32(WSAEINVAL)** | The specified address is not a valid socket address, or no transport provider supports the indicated address family. |
| **HRESULT_FROM_WIN32(WSANOTINITIALISED)** | The Winsock 2 DLL has not been initialized. The application must first call [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) to initialize Winsock 2. |
| **HRESULT_FROM_WIN32(WSAENOBUFS)** | No buffer space available. |

## See also

[IWSDUdpAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdudpaddress)