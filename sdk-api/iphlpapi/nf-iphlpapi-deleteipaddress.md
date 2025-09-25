# DeleteIPAddress function

## Description

The
**DeleteIPAddress** function deletes an IP address previously added using
[AddIPAddress](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-addipaddress).

## Parameters

### `NTEContext` [in]

The Net Table Entry (NTE) context for the IP address. This context was returned by the previous call to
[AddIPAddress](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-addipaddress).

## Return value

The function returns **NO_ERROR** (zero) if the function is successful.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. This error is returned on Windows Vista and Windows Server 2008 under several conditions that include the following: the user lacks the required administrative privileges on the local computer or the application is not running in an enhanced shell as the built-in Administrator (RunAs administrator). |
| **ERROR_INVALID_PARAMETER** | An input parameter is invalid, no action was taken. |
| **ERROR_NOT_SUPPORTED** | The IPv4 transport is not configured on the local computer. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

On Windows Vista and later, the **DeleteIPAddress** function can only be called by a user logged on as a member of the Administrators group. If **DeleteIPAddress** is called by a user that is not a member of the Administrators group, the function call will fail and **ERROR_ACCESS_DENIED** is returned. This function can also fail because of user account control (UAC) on Windows Vista and later. If an application that contains this function is executed by a user logged on as a member of the Administrators group other than the built-in Administrator, this call will fail unless the application has been marked in the manifest file with a **requestedExecutionLevel** set to requireAdministrator. If the application on Windows Vista and later lacks this manifest file, a user logged on as a member of the Administrators group other than the built-in Administrator must then be executing the application in an enhanced shell as the built-in Administrator (RunAs administrator) for this function to succeed.

**Note** On Windows NT 4.0 and Windows 2000 and later, this function executes a privileged operation. For this function to execute successfully, the caller must be logged on as a member of the Administrators group or the NetworkConfigurationOperators group.

#### Examples

The following example retrieves the IP address table, then adds the IP address 192.168.0.27 to the first adapter. The IP address that was added is then deleted.

```cpp
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <windows.h>
#include <winsock2.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <stdlib.h>

#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")

int main()
{
    // Declare and initialize variables
    PMIB_IPADDRTABLE pIPAddrTable;
    DWORD dwSize = 0;
    DWORD dwRetVal;

    // IP and mask we will be adding
    UINT iaIPAddress;
    UINT imIPMask;

    // Variables where handles to the added IP will be returned
    ULONG NTEContext = 0;
    ULONG NTEInstance = 0;

    LPVOID lpMsgBuf;

    // Before calling AddIPAddress we use GetIpAddrTable to get
    // an adapter to which we can add the IP.
    pIPAddrTable = (MIB_IPADDRTABLE *) malloc(sizeof (MIB_IPADDRTABLE));

    // Make an initial call to GetIpAddrTable to get the
    // necessary size into the dwSize variable
    if (GetIpAddrTable(pIPAddrTable, &dwSize, 0) == ERROR_INSUFFICIENT_BUFFER) {
        GlobalFree(pIPAddrTable);
        pIPAddrTable = (MIB_IPADDRTABLE *) malloc(dwSize);
    }
    // Make a second call to GetIpAddrTable to get the
    // actual data we want
    if ((dwRetVal = GetIpAddrTable(pIPAddrTable, &dwSize, 0)) == NO_ERROR) {
        printf("\tAddress: %ld\n", pIPAddrTable->table[0].dwAddr);
        printf("\tMask:    %ld\n", pIPAddrTable->table[0].dwMask);
        printf("\tIndex:   %ld\n", pIPAddrTable->table[0].dwIndex);
        printf("\tBCast:   %ld\n", pIPAddrTable->table[0].dwBCastAddr);
        printf("\tReasm:   %ld\n", pIPAddrTable->table[0].dwReasmSize);
    } else {
        printf("Call to GetIpAddrTable failed.\n");
    }

    // IP and mask we will be adding

    iaIPAddress = inet_addr("192.168.0.27");
    imIPMask = inet_addr("255.255.255.0");

    if ((dwRetVal = AddIPAddress(iaIPAddress,
                                 imIPMask,
                                 pIPAddrTable->table[0].dwIndex,
                                 &NTEContext, &NTEInstance)) == NO_ERROR) {
        printf("\tIP address added.\n");
    }

    else {
        printf("Error adding IP address.\n");

        if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL, dwRetVal, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),       // Default language
                          (LPTSTR) & lpMsgBuf, 0, NULL)) {
            printf("\tError: %s", lpMsgBuf);
        }
        LocalFree(lpMsgBuf);
    }

    // Delete the IP we just added using the NTEContext
    // variable where the handle was returned
    if ((dwRetVal = DeleteIPAddress(NTEContext)) == NO_ERROR) {
        printf("\tIP Address Deleted.\n");
    } else {
        printf("\tCall to DeleteIPAddress failed.\n");
    }

    exit(0);

```

## See also

[AddIPAddress](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-addipaddress)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)