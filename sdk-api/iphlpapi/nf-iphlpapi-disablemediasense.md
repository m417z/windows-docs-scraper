# DisableMediaSense function

## Description

The **DisableMediaSense** function disables the media sensing capability of the TCP/IP stack on a local computer.

## Parameters

### `pHandle`

A pointer to a variable that is used to store a handle. If the *pOverlapped* parameter is not **NULL**, this variable will be used internally to store a handle required to call the IP driver and disable the media sensing capability.

An application should not use the value pointed to by this variable. This handle is for internal use and should not be closed.

### `pOverLapped`

A pointer to an
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure. Except for the **hEvent** member, all members of this structure must be set to zero. The **hEvent** member requires a handle to a valid event object. Use the
[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa) function to create this event object.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if an *pOverlapped* parameter is a bad pointer. |
| **ERROR_IO_PENDING** | The operation is in progress. This value is returned by a successful asynchronous call to [DisableMediaSense](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-disablemediasense). |
| **ERROR_OPEN_FAILED** | The handle pointed to by the *pHandle* parameter was invalid. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

If the *pHandle* or *pOverlapped* parameters are **NULL**, the **DisableMediaSense** function is executed synchronously.

If both the *pHandle* and *pOverlapped* parameters are not **NULL**, the **DisableMediaSense** function is executed asynchronously using the [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure pointed to by the *pOverlapped* parameter.

The **DisableMediaSense** function does not complete until the [RestoreMediaSense](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-restoremediasense) function is called later to restore the media sensing capability. Until then, an I/O request packet (IRP) remains queued up. Alternatively, when the process that called **DisableMediaSense** exits, the IRP is canceled and a cancel routine is called that would again restore the media sensing capability.

To call **DisableMediaSense** synchronously, an application needs to create a separate thread for this call. Otherwise it would keep waiting for IRP completion and the function will block.

To call **DisableMediaSense** asynchronously, an application needs to allocate an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure. Except for the **hEvent** member, all members of this structure must be set to zero. The **hEvent** member requires a handle to a valid event object. Use the
[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa) function to create this event. When called asynchronously, **DisableMediaSense** always returns ERROR_IO_PENDING. The IRP will be completed only when [RestoreMediaSense](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-restoremediasense) is called later. Use the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function to close the handle to the event object when it is no longer needed. The system closes the handle automatically when the process terminates. The event object is destroyed when its last handle has been closed.

On Windows Server 2003and Windows XP, the TCP/IP stack implements a policy of deleting all IP addresses on an interface in response to a media sense disconnect event from an underlying network interface. If a network switch or hub that the local computer is connected to is powered off, or a network cable is disconnected, the network interface will deliver disconnection events. IP configuration information associated with the network interface is lost. As a result, the TCP/IP stack implements a policy of hiding disconnected interfaces so these interfaces and their associated IP addresses do not show up in configuration information retrieved through IP helper. This policy prevents some applications from easily detecting that a network interface is merely disconnected, rather than removed from the system.

This behavior does not normally impact a local client computer if it is using DHCP requests to a DHCP server for IP configuration information. But this can have a serious impact on server computers, particularly computers used as part of clusters. The **DisableMediaSense** function can be used to temporarily disable the media sensing capability for these cases. At some later time, the [RestoreMediaSense](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-restoremediasense) function would be called to restore the media sensing capability.

The following registry setting is related to the **DisableMediaSense** and [RestoreMediaSense](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-restoremediasense) functions:

**System**\**CurrentControlSet**\**Services**\**Tcpip**\**Parameters**\**DisableDHCPMediaSense**

There is an internal flag in Windows that is set if this registry key exists when the machine first boots up. The same internal flag also gets set and reset by calling **DisableMediaSense** and [RestoreMediaSense](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-restoremediasense). However with registry setting, you need to reboot the machine for the changes to take place.

The TCP/IP stack on Windows Vista and later was changed to not hide disconnected interfaces when a disconnect event occurs. So on Windows Vista and later, the **DisableMediaSense** and [RestoreMediaSense](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-restoremediasense) functions don't do anything and always returns NO_ERROR.

#### Examples

The following example shows how to call the **DisableMediaSense** and [RestoreMediaSense](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-restoremediasense) functions asynchronously. This sample is only useful on Windows Server 2003and Windows XP where the **DisableMediaSense** and **RestoreMediaSense** functions do something useful.

The sample first calls the **DisableMediaSense** function, sleeps for 60 seconds to allow the user to disconnect a network cable, retrieves the IP address table and prints some members of the IP address entries in the table, calls the [RestoreMediaSense](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-restoremediasense) function, retrieves the IP address table again, and prints some members of the IP address entries in the table. The impact of disabling the media sensing capability can be seen in the difference in the IP address table entries.

For an example that shows how to call the **DisableMediaSense** and [RestoreMediaSense](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-restoremediasense) functions synchronously, see the **RestoreMediaSense** function reference.

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

    // Variables to call DisableMediaSense
    //  and RestoreMediaSense asynchronously
    HANDLE IpDriverHandle = INVALID_HANDLE_VALUE;
    OVERLAPPED Overlapped;
    HANDLE DriverHandle;
    DWORD dwEnableCount = 0;

    memset(&Overlapped, 0, sizeof (Overlapped));
    Overlapped.hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);

    dwRetVal = DisableMediaSense(&DriverHandle, &Overlapped);
    if (dwRetVal != ERROR_IO_PENDING) {
        printf("DisableMediaSense failed with error %d\n", dwRetVal);
        exit(1);
    } else {
        printf(" === DisableMediaSense called ===\n\n");
        // Sleep for 60 seconds so we can disconnect a cable
        Sleep(60000);
    }

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

    // Call RestoreMediaSense asynchronously to enable mediasense
    dwRetVal = RestoreMediaSense(&Overlapped, &dwEnableCount);
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
                    NULL, dwRetVal,
                    MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),  // Default language
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

[EnableRouter](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-enablerouter)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)

[RestoreMediaSense](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-restoremediasense)

[UnenableRouter](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-unenablerouter)