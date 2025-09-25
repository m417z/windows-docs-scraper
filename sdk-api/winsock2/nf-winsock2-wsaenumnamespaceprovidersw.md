# WSAEnumNameSpaceProvidersW function

## Description

The
**WSAEnumNameSpaceProviders** function retrieves information on available namespace providers.

## Parameters

### `lpdwBufferLength` [in, out]

On input, the number of bytes contained in the buffer pointed to by *lpnspBuffer*. On output (if the function fails, and the error is
[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)), the minimum number of bytes to pass for the *lpnspBuffer* to retrieve all the requested information. The buffer passed to **WSAEnumNameSpaceProviders** must be sufficient to hold all of the namespace information.

### `lpnspBuffer` [out]

A buffer that is filled with
[WSANAMESPACE_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsanamespace_infow) structures. The returned structures are located consecutively at the head of the buffer. Variable sized information referenced by pointers in the structures point to locations within the buffer located between the end of the fixed sized structures and the end of the buffer. The number of structures filled in is the return value of
**WSAEnumNameSpaceProviders**.

## Return value

The
**WSAEnumNameSpaceProviders** function returns the number of
[WSANAMESPACE_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsanamespace_infow) structures copied into *lpnspBuffer*. Otherwise, the value SOCKET_ERROR is returned, and a specific error number can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpnspBuffer* parameter was a **NULL** pointer or the buffer length, *lpdwBufferLength*, was too small to receive all the relevant [WSANAMESPACE_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsanamespace_infow) structures and associated information. When this error is returned, the buffer length required is returned in the *lpdwBufferLength* parameter. |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The WS2_32.DLL has not been initialized. The application must first call [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) before calling any Windows Sockets functions. |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There was insufficient memory to perform the operation. |

## Remarks

The **WSAEnumNameSpaceProviders** function returns information on available namespace providers in the buffer pointed to by the *lpnspBuffer* parameter. The returned buffer contains an array of [WSANAMESPACE_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsanamespace_infow) structures located consecutively at the head of the buffer. Variable sized information referenced by pointers in the **WSANAMESPACE_INFO** structures point to locations within the buffer located between the end of the fixed **WSANAMESPACE_INFO** structures and the end of the buffer. The number of **WSANAMESPACE_INFO** structures filled in is returned by the
**WSAEnumNameSpaceProviders** function.

Each [WSANAMESPACE_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsanamespace_infow) structure entry contains the provider-specific information on the namespace entry
passed to the [WSCInstallNameSpace](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespace) and [WSCInstallNameSpace32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespace32) functions when the namespace provider was installed.

The [WSAEnumNameSpaceProvidersEx](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersexa) function is an enhanced version of the **WSAEnumNameSpaceProviders** function. The [WSCEnumNameSpaceProvidersEx32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumnamespaceprovidersex32) function is an enhanced version of the **WSAEnumNameSpaceProviders** function that returns information on available 32-bit namespace providers for use on 64-bit platforms.

### Example Code

The following example demonstrates the use of the **WSAEnumNameSpaceProviders** function to retrieve information on available namespace providers.

```cpp
#ifndef UNICODE
#define UNICODE 1
#endif

#include <winsock2.h>
#include <ws2tcpip.h>
#include <objbase.h>
#include <stdio.h>

// Link with ws2_32.lib and ole32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "ole32.lib")

#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))
// Note: could also use malloc() and free()

int wmain()
{

    //-----------------------------------------
    // Declare and initialize variables
    WSADATA wsaData;
    int iResult;
    int iError = 0;

    INT iNuminfo = 0;

    int i;

    // Allocate a 4K buffer to retrieve all the namespace providers
    DWORD dwInitialBufferLen = 4096;
    DWORD dwBufferLen;
    LPWSANAMESPACE_INFO lpProviderInfo;

    // variables needed for converting provider GUID to a string
    int iRet = 0;
    WCHAR GuidString[40] = {0};

    // Set dwBufferLen to the initial buffer length
    dwBufferLen = dwInitialBufferLen;

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        wprintf(L"WSAStartup failed: %d\n", iResult);
        return 1;
    }

    lpProviderInfo = (LPWSANAMESPACE_INFO) MALLOC(dwBufferLen);
    if (lpProviderInfo == NULL) {
        wprintf(L"Memory allocation for providers buffer failed\n");
        WSACleanup();
        return 1;
    }

    iNuminfo = WSAEnumNameSpaceProviders(&dwBufferLen, lpProviderInfo);
    if (iNuminfo == SOCKET_ERROR) {
        iError = WSAGetLastError();
        if (iError == WSAEFAULT && dwBufferLen != dwInitialBufferLen) {
            wprintf(L"WSAEnumNameSpaceProviders failed with too small a buffer\n");
            wprintf(L"  Increasing the buffer to %u\n\n", dwBufferLen);
            if (lpProviderInfo) {
               FREE(lpProviderInfo);
               lpProviderInfo = NULL;
            }

            lpProviderInfo = (LPWSANAMESPACE_INFO) MALLOC(dwBufferLen);
            if (lpProviderInfo == NULL) {
                wprintf(L"Memory allocation for providers buffer failed\n");
                WSACleanup();
               return 1;
            }

            iNuminfo = WSAEnumNameSpaceProviders(&dwBufferLen, lpProviderInfo);
            if (iNuminfo == SOCKET_ERROR) {
               wprintf(L"WSAEnumNameSpaceProviders failed with error: %d\n",
                  WSAGetLastError() );
               if (lpProviderInfo) {
                  FREE(lpProviderInfo);
                  lpProviderInfo = NULL;
               }
               WSACleanup();
               return 1;
            }
            else
                wprintf(L"\n");
        }
        else {
            wprintf(L"WSAEnumNameSpaceProviders failed with error: %d\n",
               WSAGetLastError() );
            if (lpProviderInfo) {
               FREE(lpProviderInfo);
               lpProviderInfo = NULL;
            }
           WSACleanup();
           return 1;
        }
     }

       wprintf(L"WSAEnumNameSpaceProviders succeeded with provider data count = %d\n\n",
           iNuminfo);
       for (i= 0; i < iNuminfo; i++) {
            iRet = StringFromGUID2(lpProviderInfo[i].NSProviderId, (LPOLESTR) &GuidString, 39);
            if (iRet == 0)
                wprintf(L"StringFromGUID2 failed\n");
            else
                wprintf(L"NameSpace ProviderId[%u] = %ws\n",i, GuidString);

           wprintf(L"NameSpace[%u] = ", i);
           switch (lpProviderInfo[i].dwNameSpace) {
           case NS_DNS:
               wprintf(L"Domain Name System (NS_DNS)\n");
               break;
           case NS_WINS:
               wprintf(L"Windows Internet Naming Service (NS_WINS)\n");
               break;
           case NS_NETBT:
               wprintf(L"NetBIOS (NS_NETBT)\n");
               break;
           case NS_NTDS:
               wprintf(L"Windows NT Directory Services (NS_NTDS)\n");
               break;
           case NS_NLA:
               wprintf(L"Network Location Awareness (NS_NLA)\n");
               break;
           // following values only defined on Vista and later
#if(_WIN32_WINNT >= 0x0600)
           case NS_BTH:
               wprintf(L"Bluetooth (NS_BTH)\n");
               break;
           case NS_EMAIL:
               wprintf(L"Email (NS_EMAIL)\n");
               break;
           case NS_PNRPNAME:
               wprintf(L"Peer-to-peer (NS_PNRPNAME)\n");
               break;
           case NS_PNRPCLOUD:
               wprintf(L"Peer-to-peer collection (NS_PNRPCLOUD)\n");
               break;
#endif
           default:
               wprintf(L"Other value (%u)\n", lpProviderInfo[i].dwNameSpace);
               break;
           }

           if (lpProviderInfo[i].fActive)
               wprintf(L"Namespace[%u] is active\n", i);
           else
               wprintf(L"Namespace[%u] is inactive\n", i);

           wprintf(L"NameSpace Version[%u] = %u\n", i, lpProviderInfo[i].dwVersion);

           wprintf(L"Namespace Identifier[%u] = %ws\n\n", i, lpProviderInfo[i].lpszIdentifier);
       }

    if (lpProviderInfo) {
        FREE(lpProviderInfo);
        lpProviderInfo = NULL;
    }
    WSACleanup();

    return 0;
}

```

**Windows Phone 8:** The **WSAEnumNameSpaceProvidersW** function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: The **WSAEnumNameSpaceProvidersW** function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

> [!NOTE]
> The winsock2.h header defines WSAEnumNameSpaceProviders as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[WSAEnumNameSpaceProvidersEx](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersexa)

[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror)

[WSANAMESPACE_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsanamespace_infow)

[WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup)

[WSCEnumNameSpaceProvidersEx32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumnamespaceprovidersex32)

[WSCInstallNameSpace](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespace)

[WSCInstallNameSpaceEx](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespaceex)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)