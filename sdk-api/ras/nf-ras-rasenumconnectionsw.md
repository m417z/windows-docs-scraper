# RasEnumConnectionsW function

## Description

The
**RasEnumConnections** function lists all active RAS connections. It returns each connection's handle and phone-book entry name.

## Parameters

### `unnamedParam1` [in, out]

Pointer to a buffer that receives, on output, an array of
[RASCONN](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376725(v=vs.85)) structures, one for each RAS connection.

On input, an application must set the **dwSize** member of the first
[RASCONN](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376725(v=vs.85)) structure in the buffer to sizeof(**RASCONN**) in order to identify the version of the structure being passed.

### `unnamedParam2` [in, out]

Pointer to a variable that, on input, contains the size, in bytes, of the buffer specified by *lprasconn*.

On output, the function sets this variable to the number of bytes required to enumerate the RAS connections.

**Note**

To determine the required buffer size, call
**RasEnumConnections** with *lprasconn* set to **NULL**. The variable pointed to by *lpcb* should be set to zero. The function will return the required buffer size in *lpcb* and an error code of **ERROR_BUFFER_TOO_SMALL**.

### `unnamedParam3` [out]

Pointer to a variable that receives the number of
[RASCONN](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376725(v=vs.85)) structures written to the buffer specified by *lprasconn*.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

| Return code | Description |
| --- | --- |
| **ERROR_BUFFER_TOO_SMALL** | The *lprasconn* buffer is not large enough. The *lpcb* parameter is less than the **dwSize** member in the *lprasconn* parameter which is should be set prior to calling the function. The function returns the required buffer size in the variable pointed to by *lpcb*. |

## Remarks

If a connection was made without specifying a phone-book entry name, the information returned for that connection gives the connection phone number preceded by ".".

The following code sample code uses **RasEnumConnections** to enumerates the active RAS connections.

```cpp
#include <windows.h>
#include <stdio.h>
#include "ras.h"
#include "raserror.h"
#pragma comment(lib, "rasapi32.lib")

DWORD __cdecl wmain(){

    DWORD dwCb = 0;
    DWORD dwRet = ERROR_SUCCESS;
    DWORD dwConnections = 0;
    LPRASCONN lpRasConn = NULL;

    // Call RasEnumConnections with lpRasConn = NULL. dwCb is returned with the required buffer size and
    // a return code of ERROR_BUFFER_TOO_SMALL
    dwRet = RasEnumConnections(lpRasConn, &dwCb, &dwConnections);

    if (dwRet == ERROR_BUFFER_TOO_SMALL){
        // Allocate the memory needed for the array of RAS structure(s).
        lpRasConn = (LPRASCONN) HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, dwCb);
        if (lpRasConn == NULL){
            wprintf(L"HeapAlloc failed!\n");
            return 0;
        }
        // The first RASCONN structure in the array must contain the RASCONN structure size
        lpRasConn[0].dwSize = sizeof(RASCONN);

        // Call RasEnumConnections to enumerate active connections
        dwRet = RasEnumConnections(lpRasConn, &dwCb, &dwConnections);

        // If successful, print the names of the active connections.
        if (ERROR_SUCCESS == dwRet){
            wprintf(L"The following RAS connections are currently active:\n");
            for (DWORD i = 0; i < dwConnections; i++){
                         wprintf(L"%s\n", lpRasConn[i].szEntryName);
                  }
        }
        //Deallocate memory for the connection buffer
        HeapFree(GetProcessHeap(), 0, lpRasConn);
        lpRasConn = NULL;
        return 0;
    }

    // There was either a problem with RAS or there are no connections to enumerate
    if(dwConnections >= 1){
        wprintf(L"The operation failed to acquire the buffer size.\n");
    }else{
        wprintf(L"There are no active RAS connections.\n");
    }

    return 0;
}

```

**RasEnumConnections** cannot enumerate a connection as **Active** until RAS has successfully connected.

**Windows Me/98/95:** **RasEnumConnections** enumerates a connection as **Active** as soon as it starts dialing.

The most reliable way to enumerate and check for an active connection is to call **RasEnumConnections** or [RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) to get a connection handle, then call [RasGetConnectStatus](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetconnectstatusa) to determine the actual connection state.

> [!NOTE]
> The ras.h header defines RasEnumConnections as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RASCONN](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376725(v=vs.85))

[RasEnumEntries](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasenumentriesa)

[RasGetConnectStatus](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetconnectstatusa)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)