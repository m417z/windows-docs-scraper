# WSAStartup function

## Description

The
**WSAStartup** function initiates use of the Winsock DLL by a process.

## Parameters

### `wVersionRequested` [in]

The highest version of Windows Sockets specification that the caller can use. The high-order byte specifies the minor version number; the low-order byte specifies the major version number.

### `lpWSAData` [out]

A pointer to the
[WSADATA](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-wsadata) data structure that is to receive details of the Windows Sockets implementation.

## Return value

If successful, the
**WSAStartup** function returns zero. Otherwise, it returns one of the error codes listed below.

The **WSAStartup** function directly returns the extended error code in the return value for this function. A call to the [WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) function is not needed and should not be used.

| Error code | Meaning |
| --- | --- |
| **[WSASYSNOTREADY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The underlying network subsystem is not ready for network communication. |
| **[WSAVERNOTSUPPORTED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The version of Windows Sockets support requested is not provided by this particular Windows Sockets implementation. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 operation is in progress. |
| **[WSAEPROCLIM](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A limit on the number of tasks supported by the Windows Sockets implementation has been reached. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpWSAData* parameter is not a valid pointer. |

## Remarks

The
**WSAStartup** function must be the first Windows Sockets function called by an application or DLL. It allows an application or DLL to specify the version of Windows Sockets required and retrieve details of the specific Windows Sockets implementation. The application or DLL can only issue further Windows Sockets functions after successfully calling
**WSAStartup**.

In order to support various Windows Sockets implementations and applications that can have functional differences from the latest version of Windows Sockets specification, a negotiation takes place in
**WSAStartup**. The caller of
**WSAStartup** passes in the *wVersionRequested* parameter the highest version of the Windows Sockets specification that the application supports. The Winsock DLL indicates the highest version of the Windows Sockets specification that it can support in its response. The Winsock DLL also replies with version of the Windows Sockets specification that it expects the caller to use.

When an application or DLL calls the
**WSAStartup** function, the Winsock DLL examines the version of the Windows Sockets specification requested by the application passed in the *wVersionRequested* parameter. If the version requested by the application is equal to or higher than the lowest version supported by the Winsock DLL, the call succeeds and the Winsock DLL returns detailed information in the [WSADATA](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-wsadata) structure pointed to by the *lpWSAData* parameter. The **wHighVersion** member of the **WSADATA** structure indicates the highest version of the Windows Sockets specification that the Winsock DLL supports. The **wVersion** member of the **WSADATA** structure indicates the version of the Windows Sockets specification that the Winsock DLL expects the caller to use.

If the **wVersion** member of the
[WSADATA](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-wsadata) structure is unacceptable to the caller, the application or DLL should call
[WSACleanup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsacleanup) to release the Winsock DLL resources and fail to initialize the Winsock application. In order to support this application or DLL, it will be necessary to search for an updated version of the Winsock DLL to install on the platform.

The current version of the Windows Sockets specification is version 2.2. The current Winsock DLL, *Ws2_32.dll*, supports applications that request any of the following versions of Windows Sockets specification:

* 1.0
* 1.1
* 2.0
* 2.1
* 2.2

To get full access to the new syntax of a higher version of the Windows Sockets specification, the application must negotiate for this higher version. In this case, the *wVersionRequested* parameter should be set to request version 2.2. The application must also fully conform to that higher version of the Windows Socket specification, such as compiling against the appropriate header file, linking with a new library, or other special cases. The *Winsock2.h header* file for Winsock 2 support is included with the Microsoft Windows Software Development Kit (SDK).

Windows Sockets version 2.2 is supported on Windows Server 2008,
Windows Vista, Windows Server 2003,
Windows XP,
Windows 2000, Windows NT 4.0 with Service Pack 4 (SP4) and later,
Windows Me,
Windows 98, and Windows 95 OSR2.
Windows Sockets version 2.2 is also supported on
Windows 95 with the Windows Socket 2 Update. Applications on these platforms should normally request Winsock 2.2 by setting the *wVersionRequested* parameter accordingly.

On Windows 95 and versions of Windows NT 3.51 and earlier, Windows Sockets version 1.1 is the highest version of the Windows Sockets specification supported.

It is legal and possible for an application or DLL written to use a lower version of the Windows Sockets specification that is supported by the Winsock DLL to successfully negotiate this lower version using the **WSAStartup** function. For example, an application can request version 1.1 in the *wVersionRequested* parameter passed to the **WSAStartup** function on a platform with the Winsock 2.2 DLL. In this case, the application should only rely on features that fit within the version requested. New Ioctl codes, new behavior of existing functions, and new functions should not be used. The version negotiation provided by the **WSAStartup** was primarily used to allow older Winsock 1.1 applications developed for Windows 95 and Windows NT 3.51 and earlier to run with the same behavior on later versions of Windows. The *Winsock.h header* file for Winsock 1.1 support is included with the Windows SDK.

This negotiation in the **WSAStartup** function allows both the application or DLL that uses Windows Sockets and the Winsock DLL to support a range of Windows Sockets versions. An application or DLL can use the Winsock DLL if there is any overlap in the version ranges. Detailed information on the Windows Sockets implementation is provided in the
[WSADATA](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-wsadata) structure returned by the **WSAStartup** function.

The following table shows how
**WSAStartup** works with different applications and Winsock DLL versions.

| Caller version support | Winsock DLL version support | **wVersion**  requested | **wVersion**  returned | **wHighVersion**  returned | End result |
| --- | --- | --- | --- | --- | --- |
| 1.1 | 1.1 | 1.1 | 1.1 | 1.1 | use 1.1 |
| 1.0 1.1 | 1.0 | 1.1 | 1.0 | 1.0 | use 1.0 |
| 1.0 | 1.0 1.1 | 1.0 | 1.0 | 1.1 | use 1.0 |
| 1.1 | 1.0 1.1 | 1.1 | 1.1 | 1.1 | use 1.1 |
| 1.1 | 1.0 | 1.1 | 1.0 | 1.0 | Application fails |
| 1.0 | 1.1 | 1.0 | — | — | [WSAVERNOTSUPPORTED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) |
| 1.0 1.1 | 1.0 1.1 | 1.1 | 1.1 | 1.1 | use 1.1 |
| 1.1 2.0 | 1.0 1.1 | 2.0 | 1.1 | 1.1 | use 1.1 |
| 2.0 | 1.0 1.1 2.0 | 2.0 | 2.0 | 2.0 | use 2.0 |
| 2.0 2.2 | 1.0 1.1 2.0 | 2.2 | 2.0 | 2.0 | use 2.0 |
| 2.2 | 1.0 1.1 2.0 2.1 2.2 | 2.2 | 2.2 | 2.2 | use 2.2 |

Once an application or DLL has made a successful
**WSAStartup** call, it can proceed to make other Windows Sockets calls as needed. When it has finished using the services of the Winsock DLL, the application must call
[WSACleanup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsacleanup) to allow the Winsock DLL to free internal Winsock resources used by the application.

An application can call
**WSAStartup** more than once if it needs to obtain the
[WSADATA](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-wsadata) structure information more than once. On each such call, the application can specify any version number supported by the Winsock DLL.

The
**WSAStartup** function typically leads to protocol-specific helper DLLs being loaded. As a result, the
**WSAStartup** function should not be called from the DllMain function in a application DLL. This can potentially cause deadlocks. For more information, please see the [DLL Main Function](https://learn.microsoft.com/windows/win32/dlls/dllmain).

An application must call the [WSACleanup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsacleanup) function for every successful
time the **WSAStartup** function is called. This means, for example, that if an application calls
**WSAStartup** three times, it must call
**WSACleanup** three times. The first two calls to
**WSACleanup** do nothing except decrement an internal counter; the final
**WSACleanup** call for the task does all necessary resource deallocation for the task.

**Note** An application can call the [WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) function to determine the extended error code for other Windows sockets functions as is normally done in Windows Sockets even if
the **WSAStartup** function fails or the **WSAStartup** function was not called to properly initialize Windows Sockets before calling a Windows Sockets function. The **WSAGetLastError** function is one of the only functions in the Winsock 2.2 DLL that can be called in the case of a **WSAStartup** failure.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

#### Examples

The following code fragment demonstrates how an application that supports only version 2.2 of Windows Sockets makes a
**WSAStartup** call:

```cpp
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

// Need to link with Ws2_32.lib
#pragma comment(lib, "ws2_32.lib")

int __cdecl main()
{

    WORD wVersionRequested;
    WSADATA wsaData;
    int err;

/* Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h */
    wVersionRequested = MAKEWORD(2, 2);

    err = WSAStartup(wVersionRequested, &wsaData);
    if (err != 0) {
        /* Tell the user that we could not find a usable */
        /* Winsock DLL.                                  */
        printf("WSAStartup failed with error: %d\n", err);
        return 1;
    }

/* Confirm that the WinSock DLL supports 2.2.*/
/* Note that if the DLL supports versions greater    */
/* than 2.2 in addition to 2.2, it will still return */
/* 2.2 in wVersion since that is the version we      */
/* requested.                                        */

    if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {
        /* Tell the user that we could not find a usable */
        /* WinSock DLL.                                  */
        printf("Could not find a usable version of Winsock.dll\n");
        WSACleanup();
        return 1;
    }
    else
        printf("The Winsock 2.2 dll was found okay\n");

/* The Winsock DLL is acceptable. Proceed to use it. */

/* Add network programming using Winsock here */

/* then call WSACleanup when done using the Winsock dll */

    WSACleanup();

}

```

## See also

[MAKEWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632663(v=vs.85))

[WSACleanup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsacleanup)

[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send)

[sendto](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-sendto)