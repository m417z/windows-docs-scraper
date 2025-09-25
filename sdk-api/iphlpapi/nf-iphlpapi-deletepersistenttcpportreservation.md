# DeletePersistentTcpPortReservation function

## Description

The
**DeletePersistentTcpPortReservation** function deletes a persistent TCP port reservation for a consecutive block of TCP ports on the local computer.

## Parameters

### `StartPort` [in]

The starting TCP port number in network byte order.

### `NumberOfPorts` [in]

The number of TCP port numbers to delete.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. This error is returned under several conditions that include the following: the user lacks the required administrative privileges on the local computer or the application is not running in an enhanced shell as the built-in Administrator (RunAs administrator). |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if zero is passed in the *StartPort* or *NumberOfPorts* parameters. |
| **ERROR_NOT_FOUND** | The element was not found. This error is returned if persistent port block specified by the *StartPort* and *NumberOfPorts* parameters could not be found. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **DeletePersistentTcpPortReservation** function is defined on Windows Vista and later.

The **DeletePersistentTcpPortReservation** function is used to delete a persistent reservation for a block of TCP ports.

The **DeletePersistentTcpPortReservation** function can only be called by a user logged on as a member of the Administrators group. If **DeletePersistentTcpPortReservation** is called by a user that is not a member of the Administrators group, the function call will fail and **ERROR_ACCESS_DENIED** is returned. This function can also fail because of user account control (UAC) on Windows Vista and later. If an application that contains this function is executed by a user logged on as a member of the Administrators group other than the built-in Administrator, this call will fail unless the application has been marked in the manifest file with a **requestedExecutionLevel** set to requireAdministrator. If the application lacks this manifest file, a user logged on as a member of the Administrators group other than the built-in Administrator must then be executing the application in an enhanced shell as the built-in Administrator (RunAs administrator) for this function to succeed.

#### Examples

The following example deletes a persistent TCP port reservation.

This example must be run by a user that is a member of the Administrators group. The simplest way to run this example is in an enhanced shell as the built-in Administrator (RunAs administrator).

```cpp
#ifndef UNICODE
#define UNICODE
#endif

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <Windows.h.>
#include <winsock2.h>
#include <ws2ipdef.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <stdlib.h>

// Need to link with iphlpapi.lib
#pragma comment(lib, "iphlpapi.lib")

// Need to link with ws2_32.lib for htons
#pragma comment(lib, "ws2_32.lib")

int wmain(int argc, WCHAR **argv)  {

    // Declare and initialize variables

    int startPort = 0;         // host byte order
    int numPorts = 0;
    USHORT startPortns = 0;    // Network byte order

    unsigned long status = 0;

    // Validate the parameters
    if (argc != 3) {
        wprintf(L"usage: %s <Starting Port> <Number of Ports>\n", argv[0]);
        wprintf(L"Delete a persistent TCP port reservation\n");
        wprintf(L"Example usage:\n");
        wprintf(L"   %s 5000 20\n", argv[0]);
        wprintf(L"   where StartPort=5000 NumPorts=20");
        return 1;
    }

    startPort = _wtoi(argv[1]);
    if ( startPort < 0 || startPort> 65535) {
        wprintf(L"Starting point must be either 0 or between 1 and 65,535\n");
        return 1;
    }
    startPortns = htons((u_short) startPort);

    numPorts = _wtoi(argv[2]);
    if (numPorts < 0) {
        wprintf(L"Number of ports must be a positive number\n");
        return 1;
    }

    status = DeletePersistentTcpPortReservation((USHORT) startPortns, (USHORT) numPorts);
    if( status != NO_ERROR )
    {
        wprintf(L"DeletePersistentTcpPortReservation returned error: %ld\n",
            status);
        return 1;
    }

    wprintf(L"DeletePersistentTcpPortReservation call succeeded\n");

    return 0;
}

```

## See also

[CreatePersistentTcpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-createpersistenttcpportreservation)

[CreatePersistentUdpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-createpersistentudpportreservation)

[DeletePersistentUdpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-deletepersistentudpportreservation)

[LookupPersistentTcpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-lookuppersistenttcpportreservation)

[LookupPersistentUdpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-lookuppersistentudpportreservation)