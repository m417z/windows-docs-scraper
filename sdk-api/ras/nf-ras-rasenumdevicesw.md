# RasEnumDevicesW function

## Description

The
**RasEnumDevices** function returns the name and type of all available RAS-capable devices.

## Parameters

### `unnamedParam1` [in]

Pointer to a buffer that receives an array of
[RASDEVINFO](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377001(v=vs.85)) structures, one for each RAS-capable device. Before calling the function, set the **dwSize** member of the first
**RASDEVINFO** structure in the buffer to sizeof(**RASDEVINFO**) to identify the version of the structure.

### `unnamedParam2` [in, out]

Pointer to a variable that, on input, contains the size, in bytes, of the *lpRasDevInfo* buffer.

On output, the function sets this variable to the number of bytes required to enumerate the devices.

**Note**

To determine the required buffer size, call
**RasEnumDevices** with *lpRasDevInfo* set to **NULL**. The variable pointed to by *lpcb* should be set to zero. The function will return the required buffer size in *lpcb* and an error code of **ERROR_BUFFER_TOO_SMALL**.

### `unnamedParam3` [out]

Pointer to a variable that receives the number of
[RASDEVINFO](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377001(v=vs.85)) structures written to the *lpRasDevInfo* buffer.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

| Value | Meaning |
| --- | --- |
| **ERROR_BUFFER_TOO_SMALL** | The *lpRasDevInfo* buffer is not large enough. The *lpcb* parameter is less than the **dwSize** member in the *lpRasDevInfo* parameter which should be set prior to calling the function. The function returns the required buffer size in the variable pointed to by *lpcb*. |
| **ERROR_NOT_ENOUGH_MEMORY** | Indicates insufficient memory. The *lpRasDevInfo* parameter is non-**NULL**, the *lpcb* parameter is non-**NULL** and an internal memory allocation failed. This is possibly due to a low-memory condition. |
| **ERROR_INVALID_PARAMETER** | Indicates an invalid parameter value. The *lpcb* parameter is **NULL** or the *lpcDevices* parameter is **NULL**. |
| **ERROR_INVALID_USER_BUFFER** | The address or buffer specified by *lpRasDevInfo* is invalid. The **dwSize** member of the *lpRasDevInfo* parameter does not equal sizeof([RASDEVINFO](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377001(v=vs.85))). |

## Remarks

The following sample code enumerates the devices on the current machine. The code initially calls
**RasEnumDevices** with a *lpRasDevInfo* parameter of **NULL**, to obtain the size of the buffer that should be passed in. The code also sets the **dwSize** member of the first
[RASDEVINFO](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377001(v=vs.85)) structure to sizeof(**RASDEVINFO**) to specify the version of the structure.

```cpp
#include <windows.h>
#include <stdio.h>
#include "ras.h"
#include "raserror.h"
#pragma comment(lib, "rasapi32.lib")

DWORD __cdecl wmain(){

    DWORD dwCb = 0;
    DWORD dwRet = ERROR_SUCCESS;
    DWORD dwDevices = 0;
    LPRASDEVINFO lpRasDevInfo = NULL;

    // Call RasEnumDevices with lpRasDevInfo = NULL. dwCb is returned with the required buffer size and
    // a return code of ERROR_BUFFER_TOO_SMALL
    dwRet = RasEnumDevices(lpRasDevInfo, &dwCb, &dwDevices);

    if (dwRet == ERROR_BUFFER_TOO_SMALL){
        // Allocate the memory needed for the array of RAS structure(s).
        lpRasDevInfo = (LPRASDEVINFO) HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, dwCb);
        if (lpRasDevInfo == NULL){
            wprintf(L"HeapAlloc failed!\n");
            return 0;
        }
        // The first RASDEVINFO structure in the array must contain the structure size
        lpRasDevInfo[0].dwSize = sizeof(RASDEVINFO);

        // Call RasEnumDevices to enumerate RAS devices
        dwRet = RasEnumDevices(lpRasDevInfo, &dwCb, &dwDevices);

        // If successful, print the names of the RAS devices
        if (ERROR_SUCCESS == dwRet){
            wprintf(L"The following RAS devices were found:\n");
            for (DWORD i = 0; i < dwDevices; i++){
                         wprintf(L"%s\n", lpRasDevInfo[i].szDeviceName);
                  }
        }
        //Deallocate memory for the connection buffer
        HeapFree(GetProcessHeap(), 0, lpRasDevInfo);
        lpRasDevInfo = NULL;
        return 0;
    }

    // There was either a problem with RAS or there are no RAS devices to enumerate
    if(dwDevices >= 1){
        wprintf(L"The operation failed to acquire the buffer size.\n");
    }else{
        wprintf(L"There were no RAS devices found.\n");
    }

    return 0;
}

```

> [!NOTE]
> The ras.h header defines RasEnumDevices as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RASDEVINFO](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377001(v=vs.85))

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)