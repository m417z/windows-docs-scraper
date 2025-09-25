# ASSOCIATE_NAMERES_CONTEXT_INPUT structure

## Description

The **ASSOCIATE_NAMERES_CONTEXT_INPUT** structure contains the transport setting ID and handle to a fully qualified domain name.

## Members

### `TransportSettingId`

The transport setting ID.

### `Handle`

Handle to a fully qualified domain name.

## Remarks

Generally speaking, you can use **ASSOCIATE_NAMERES_CONTEXT_INPUT** to enforce policy based on Fully Qualified Domain Name (FQDN), rather than just IP address. you can do so by retrieving a handle to a FQDN with a call to [GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa), using the addinfoex4 structure. From there, you can use the handle in **ASSOCIATE_NAMERES_CONTEXT_INPUT** in a call to [WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl), using the **SIO_APPLY_TRANSPORT_SETTING** ioctl.

#### Examples

The following code describes making a call to [GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa) with a addinfoex4 structure to retrieve the handle to a FQDN. the sample then call [WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl) with the **ASSOCIATE_NAMERES_CONTEXT_INPUT** structure.

```cpp
//
// Connect to a server using its IPv4 addresses
//

VOID
ConnectServer(
    PCWSTR server)
{
    int iResult;
    PADDRINFOEX4 pResult = NULL;
    ADDRINFOEX3 hints = { 0 };
    PADDRINFOEX4 pCur = NULL;
    WSADATA wsaData;
    SOCKET connectSocket = INVALID_SOCKET;
    ULONG bytesReturned = 0;
    ASSOCIATE_NAMERES_CONTEXT_INPUT input = { 0 };
    SOCKADDR_IN clientService;
    wchar_t ipstringbuffer[46];
    String string;
    DWORD dwRetval;
    //
    //  Initialize Winsock
    //
    iResult = WSAStartup(
        MAKEWORD(2, 2),
        &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed: %d\n", iResult);
        goto Exit;
    }

    //
    // Create a SOCKET for connection
    //
    connectSocket = socket(
        AF_UNSPEC,
        SOCK_STREAM,
        IPPROTO_TCP);
    if (connectSocket == INVALID_SOCKET)
    {
        printf("socket failed: %d\n", WSAGetLastError());
        goto Exit;
    }

    //
    // Do name resolution
    //

    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_EXTENDED | AI_FQDN | AI_CANONNAME | AI_RESOLUTION_HANDLE;
    hints.ai_version = ADDRINFOEX_VERSION_4;

    dwRetval = GetAddrInfoExW(
        server,
        NULL,
        NS_DNS,
        NULL,
        (const ADDRINFOEXW*)&hints,
        (PADDRINFOEXW*)&pResult,
        NULL,
        NULL,
        NULL, NULL);
    if (dwRetval != 0) {
        printf("GetAddrInfoEx failed with error: %d\n", dwRetval);
        goto Exit;
    }
    input.TransportSettingId.Guid = ASSOCIATE_NAMERES_CONTEXT;
    input.Handle = pResult->ai_resolutionhandle;

    //
    // Associate socket with the handle
    //

    if (WSAIoctl(
            connectSocket,
            SIO_APPLY_TRANSPORT_SETTING,
            (VOID *)&input,
            sizeof(input),
            NULL,
            0,
            &bytesReturned,
            NULL,
            NULL) == SOCKET_ERROR)
    if (iResult != 0){
        printf("WSAIoctl failed: %d\n", WSAGetLastError());
        goto Exit;
    }

    //
    // Connect to server
    //

    pCur = pResult;
    while (pCur != NULL)
    {
        if (pCur->ai_addr->sa_family == AF_INET)
        {
            clientService = *(const sockaddr_in*)pCur->ai_addr;
            clientService.sin_port = htons(80);
            if (connect(
                connectSocket,
                (const SOCKADDR *)&clientService,
                sizeof(clientService)) == SOCKET_ERROR)
            {
                printf("connect failed: %d\n", WSAGetLastError());
                goto Exit;
            }
        }
        pCur = pCur->ai_next;
    }

Exit:

    if (connectSocket != INVALID_SOCKET)
    {
        closesocket(connectSocket);
    }
    if (pResult)
    {
        FreeAddrInfoExW((ADDRINFOEXW*)pResult);
    }
    WSACleanup();
    return;
}

```

## See also

[GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa)

[WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl)

[addrinfoex4](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoex4)