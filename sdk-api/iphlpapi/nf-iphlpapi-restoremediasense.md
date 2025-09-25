# RestoreMediaSense function

## Description

The **RestoreMediaSense** function restores the media sensing capability of the TCP/IP stack on a local computer on which the [DisableMediaSense](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-disablemediasense) function was previously called.

## Parameters

### `pOverlapped`

A pointer to an
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure. Except for the **hEvent** member, all members of this structure must be set to zero. The **hEvent** member should contain a handle to a valid event object. Use the
[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa) function to create this event object.

### `lpdwEnableCount` [optional]

An optional pointer to a DWORD variable that receives the number of references remaining if the **RestoreMediaSense** function succeeds. The variable is also used by the [EnableRouter](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-enablerouter) and [UnenableRouter](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-unenablerouter) functions.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if an *pOverlapped* parameter is a bad pointer. This error is also returned if the [DisableMediaSense](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-disablemediasense) function was not called prior to calling the [RestoreMediaSense](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-restoremediasense) function. |
| **ERROR_IO_PENDING** | The operation is in progress. This value may be returned by a successful asynchronous call to [RestoreMediaSense](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-restoremediasense). |
| **ERROR_OPEN_FAILED** | An internal handle to the driver was invalid. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

If the *pOverlapped* parameter is **NULL**, the **RestoreMediaSense** function is executed synchronously.

If the *pOverlapped* parameter is not **NULL**, the **RestoreMediaSense** function is executed asynchronously using the [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure pointed to by the *pOverlapped* parameter.

The [DisableMediaSense](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-disablemediasense) function does not complete until the **RestoreMediaSense** function is called later to restore the media sensing capability. Until then, an I/O request packet (IRP) remains queued up. Alternatively, when the process that called **DisableMediaSense** exits, the IRP is canceled and a cancel routine is called that would again restore the media sensing capability.

To call **RestoreMediaSense** synchronously, an application needs to pass a **NULL** pointer in the *pOverlapped* parameter. When **RestoreMediaSense** is called synchronously, the function returns when the I/O request packet (IRP) to restore the media sense has completed.

To call **RestoreMediaSense** asynchronously, an application needs to allocate an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure. Except for the **hEvent** member, all members of this structure must be set to zero. The **hEvent** member requires a handle to a valid event object. Use the
[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa) function to create this event. When called asynchronously, **RestoreMediaSense** can return ERROR_IO_PENDING. The IRP completes when the media sensing capability has been restored. Use the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function to close the handle to the event object when it is no longer needed. The system closes the handle automatically when the process terminates. The event object is destroyed when its last handle has been closed.

If [DisableMediaSense](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-disablemediasense) was not called prior to calling **RestoreMediaSense**, then **RestoreMediaSense** returns ERROR_INVALID_PARAMETER.

On Windows Server 2003and Windows XP, the TCP/IP stack implements a policy of deleting all IP addresses on an interface in response to a media sense disconnect event from an underlying network interface. If a network switch or hub that the local computer is connected to is powered off, or a network cable is disconnected, the network interface will deliver disconnection events. IP configuration information associated with the network interface is lost. As a result, the TCP/IP stack implements a policy of hiding disconnected interfaces so these interfaces and their associated IP addresses do not show up in configuration information retrieved through IP helper. This policy prevents some applications from easily detecting that a network interface is merely disconnected, rather than removed from the system.

This behavior does not normally impact a local client computer if it is using DHCP requests to a DHCP server for IP configuration information. But this can have a serious impact on server computers, particularly computers used as part of clusters. The [DisableMediaSense](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-disablemediasense) function can be used to temporarily disable the media sense capability for these cases. At some later time, the **RestoreMediaSense** function would be called to restore the media sensing capability.

The following registry setting is related to the [DisableMediaSense](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-disablemediasense) and **RestoreMediaSense** functions:

**System**\**CurrentControlSet**\**Services**\**Tcpip**\**Parameters**\**DisableDHCPMediaSense**

There is an internal flag in Windows that is set if this registry key exists when the machine first boots up. The same internal flag also gets set and reset by calling [DisableMediaSense](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-disablemediasense) and **RestoreMediaSense**. However with registry setting, you need to reboot the machine for the changes to take place.

The TCP/IP stack on Windows Vista and later was changed to not hide disconnected interfaces when a disconnect event occurs. So on Windows Vista and later, the [DisableMediaSense](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-disablemediasense) and **RestoreMediaSense** functions don't do anything and always returns NO_ERROR.

#### Examples

The following example shows how to call the [DisableMediaSense](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-disablemediasense) and **RestoreMediaSense** functions synchronously. This sample is only useful on Windows Server 2003and Windows XP where the **DisableMediaSense** and **RestoreMediaSense** functions do something useful.

The sample first creates a separate thread that calls the [DisableMediaSense](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-disablemediasense) function synchronously, the main thread sleeps for 60 seconds to allow the user to disconnect a network cable, retrieves the IP address table and prints some members of the IP address entries in the table, calls the **RestoreMediaSense** function synchronously, retrieves the IP address table again, and prints some members of the IP address entries in the table. The impact of disabling the media sensing capability can be seen in the difference in the IP address table entries.

For an example that shows how to call the [DisableMediaSense](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-disablemediasense) and **RestoreMediaSense** functions asynchronously, see the **DisableMediaSense** function reference.

```cpp
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <stdio.h>

#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")

#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))

/* Note: could also use malloc() and free() */

// The thread proc to call DisableMediaSense
DWORD WINAPI ThreadProc(LPVOID lpParam)
{
    if (*((DWORD *) lpParam)) {
        DWORD dwRetVal;
        dwRetVal = DisableMediaSense(NULL, NULL);
        if (dwRetVal && dwRetVal != ERROR_IO_PENDING) {
            printf("DisableMediaSense failed with error %d\n", dwRetVal);
            return 0;
        } else {
            Sleep(1000);
            printf(" === DisableMediaSense Returned now. ===\n\n");
        }
    }
    return 0;
}

int __cdecl main()
{

    int i;

    /* Variables used by GetIpAddrTable */
    PMIB_IPADDRTABLE pIPAddrTable;
    DWORD dwSize = 0;
    DWORD dwRetVal = 0;
    IN_ADDR IPAddr;

    /* Variables used to return error message */
    LPVOID lpMsgBuf;

    /* Variable to use with RestoreMediaSense */
    DWORD dwEnableCount = 0;

    // Variables used to create a separate thread to call
    // the DisableMediaSense function
    DWORD ThreadID;
    DWORD IsDisable = TRUE;
    HANDLE Disable_THandle;

    // Create the thread to call Disable MediaSense synchronously
    Disable_THandle =
        CreateThread(NULL, 0, ThreadProc, (LPVOID) & IsDisable, 0, &ThreadID);
    if (!Disable_THandle) {
        printf("CreateTread Failed:%d", GetLastError());
        exit(1);
    }

    printf(" === DisableMediaSense called on separate thread ===\n\n");
// Sleep for 60 seconds so we can disconnect a cable
    Sleep(60000);

    // Before calling AddIPAddress we use GetIpAddrTable to get
    // an adapter to which we can add the IP.
    pIPAddrTable = (MIB_IPADDRTABLE *) MALLOC(sizeof (MIB_IPADDRTABLE));

    if (pIPAddrTable) {
        // Make an initial call to GetIpAddrTable to get the
        // necessary size into the dwSize variable
        if (GetIpAddrTable(pIPAddrTable, &dwSize, 0) ==
            ERROR_INSUFFICIENT_BUFFER) {
            FREE(pIPAddrTable);
            pIPAddrTable = (MIB_IPADDRTABLE *) MALLOC(dwSize);

        }
        if (pIPAddrTable == NULL) {
            printf("Memory allocation failed for GetIpAddrTable\n");
            exit(1);
        }
    }
    // Make a second call to GetIpAddrTable to get the
    // actual data we want
    if ((dwRetVal = GetIpAddrTable(pIPAddrTable, &dwSize, 0)) != NO_ERROR) {
        printf("GetIpAddrTable failed with error %d\n", dwRetVal);
        if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
                    FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                    NULL,
                    dwRetVal,
                    MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
                    (LPTSTR) & lpMsgBuf, 0, NULL)) {
            printf("\tError: %s", lpMsgBuf);
            LocalFree(lpMsgBuf);
        }
        exit(1);
    }

    printf("\tNum Entries: %ld\n", pIPAddrTable->dwNumEntries);
    for (i = 0; i < (int) pIPAddrTable->dwNumEntries; i++) {
        printf("\n\tInterface Index[%d]:\t%ld\n", i,
               pIPAddrTable->table[i].dwIndex);
        IPAddr.S_un.S_addr = (u_long) pIPAddrTable->table[i].dwAddr;
        printf("\tIP Address[%d]:     \t%s\n", i, inet_ntoa(IPAddr));
        IPAddr.S_un.S_addr = (u_long) pIPAddrTable->table[i].dwMask;
        printf("\tSubnet Mask[%d]:    \t%s\n", i, inet_ntoa(IPAddr));
        IPAddr.S_un.S_addr = (u_long) pIPAddrTable->table[i].dwBCastAddr;
        printf("\tBroadCast[%d]:      \t%s (%ld%)\n", i, inet_ntoa(IPAddr),
               pIPAddrTable->table[i].dwBCastAddr);
        printf("\tReassembly size[%d]:\t%ld\n", i,
               pIPAddrTable->table[i].dwReasmSize);
        printf("\tType and State[%d]:", i);
        if (pIPAddrTable->table[i].wType & MIB_IPADDR_PRIMARY)
            printf("\tPrimary IP Address");
        if (pIPAddrTable->table[i].wType & MIB_IPADDR_DYNAMIC)
            printf("\tDynamic IP Address");
        if (pIPAddrTable->table[i].wType & MIB_IPADDR_DISCONNECTED)
            printf("\tAddress is on disconnected interface");
        if (pIPAddrTable->table[i].wType & MIB_IPADDR_DELETED)
            printf("\tAddress is being deleted");
        if (pIPAddrTable->table[i].wType & MIB_IPADDR_TRANSIENT)
            printf("\tTransient address");
        printf("\n");
    }

    // Call RestoreMediaSense synchronously to enable mediasense
    dwRetVal = RestoreMediaSense(NULL, &dwEnableCount);
    if (dwRetVal && dwRetVal != ERROR_IO_PENDING) {
        printf("RestoreMediaSense failed with error %d\n", dwRetVal);
        exit(1);
    } else {
        printf(" === RestoreMediaSense called ===\n");
        printf("  EnableCount returned was %ld\n\n", dwEnableCount);
    }

    if (pIPAddrTable) {
        // Make an initial call to GetIpAddrTable to get the
        // necessary size into the dwSize variable
        if (GetIpAddrTable(pIPAddrTable, &dwSize, 0) ==
            ERROR_INSUFFICIENT_BUFFER) {
            FREE(pIPAddrTable);
            pIPAddrTable = (MIB_IPADDRTABLE *) MALLOC(dwSize);

        }
        if (pIPAddrTable == NULL) {
            printf("Memory allocation failed for GetIpAddrTable\n");
            exit(1);
        }
    }
    // Make a second call to GetIpAddrTable to get the
    // actual data we want
    if ((dwRetVal = GetIpAddrTable(pIPAddrTable, &dwSize, 0)) != NO_ERROR) {
        printf("GetIpAddrTable failed with error %d\n", dwRetVal);
        if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
                    FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                    NULL,
                    dwRetVal,
                    MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
                    (LPTSTR) & lpMsgBuf, 0, NULL)) {
            printf("\tError: %s", lpMsgBuf);
            LocalFree(lpMsgBuf);
        }
        exit(1);
    }

    printf("\tNum Entries: %ld\n", pIPAddrTable->dwNumEntries);
    for (i = 0; i < (int) pIPAddrTable->dwNumEntries; i++) {
        printf("\n\tInterface Index[%d]:\t%ld\n", i,
               pIPAddrTable->table[i].dwIndex);
        IPAddr.S_un.S_addr = (u_long) pIPAddrTable->table[i].dwAddr;
        printf("\tIP Address[%d]:     \t%s\n", i, inet_ntoa(IPAddr));
        IPAddr.S_un.S_addr = (u_long) pIPAddrTable->table[i].dwMask;
        printf("\tSubnet Mask[%d]:    \t%s\n", i, inet_ntoa(IPAddr));
        IPAddr.S_un.S_addr = (u_long) pIPAddrTable->table[i].dwBCastAddr;
        printf("\tBroadCast[%d]:      \t%s (%ld%)\n", i, inet_ntoa(IPAddr),
               pIPAddrTable->table[i].dwBCastAddr);
        printf("\tReassembly size[%d]:\t%ld\n", i,
               pIPAddrTable->table[i].dwReasmSize);
        printf("\tType and State[%d]:", i);
        if (pIPAddrTable->table[i].wType & MIB_IPADDR_PRIMARY)
            printf("\tPrimary IP Address");
        if (pIPAddrTable->table[i].wType & MIB_IPADDR_DYNAMIC)
            printf("\tDynamic IP Address");
        if (pIPAddrTable->table[i].wType & MIB_IPADDR_DISCONNECTED)
            printf("\tAddress is on disconnected interface");
        if (pIPAddrTable->table[i].wType & MIB_IPADDR_DELETED)
            printf("\tAddress is being deleted");
        if (pIPAddrTable->table[i].wType & MIB_IPADDR_TRANSIENT)
            printf("\tTransient address");
        printf("\n");
    }

    if (pIPAddrTable) {
        FREE(pIPAddrTable);
        pIPAddrTable = NULL;
    }

    exit(0);
}

```

## See also

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa)

[DisableMediaSense](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-disablemediasense)

[EnableRouter](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-enablerouter)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)

[UnenableRouter](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-unenablerouter)