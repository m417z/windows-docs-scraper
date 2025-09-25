# RasEnumEntriesW function

## Description

The
**RasEnumEntries** function lists all entry names in a remote access phone book.

## Parameters

### `unnamedParam1` [in]

Reserved; must be **NULL**.

### `unnamedParam2` [in]

Pointer to a null-terminated string that specifies the full path and file name of a phone-book (PBK) file. If this parameter is **NULL**, the function uses the current default phone-book file. The default phone-book file is the one selected by the user in the **User Preferences** property sheet of the **Dial-Up Networking** dialog box.

If this parameter is **NULL**, the entries are enumerated from all the remote access phone-book files in the AllUsers profile and the user's profile.

### `unnamedParam3` [in, out]

Pointer to a buffer that, on output, receives an array of
[RASENTRYNAME](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377267(v=vs.85)) structures, one for each phone-book entry.

On input, an application must set the **dwSize** member of the first
[RASENTRYNAME](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377267(v=vs.85)) structure in the buffer to sizeof(**RASENTRYNAME**) in order to identify the version of the structure being passed.

### `unnamedParam4` [in, out]

Pointer to a variable that, on input, contains the size, in bytes, of the buffer specified by *lprasentryname*.

Pointer to a variable that, on output, contains the size, in bytes, of the array of
[RASENTRYNAME](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377267(v=vs.85)) structures required for the phone-book entries.

**Windows Vista or later:** To determine the required buffer size, call
**RasEnumEntries** with *lprasentryname* set to **NULL**. The variable pointed to by *lpcb* should be set to zero. The function will return the required buffer size in *lpcb* and an error code of **ERROR_BUFFER_TOO_SMALL**.

### `unnamedParam5` [out]

Pointer to a variable that receives to the number of phone-book entries written to the buffer specified by *lprasentryname*.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

| Value | Meaning |
| --- | --- |
| **ERROR_BUFFER_TOO_SMALL** | The *lprasentryname* buffer is not large enough. The *lpcb* parameter is less than the **dwSize** member in the *lprasentryname* parameter which should be set prior to calling the function. The function returns the required buffer size in the variable pointed to by *lpcb*.<br><br>**Windows Vista or later:** The *lprasentryname* buffer may be set to **NULL** and the variable pointed to by *lpcb* may be set to zero. The function will return the required buffer size in the variable pointed to by *lpcb*. |
| **ERROR_INVALID_SIZE** | The value of **dwSize** in the [RASENTRYNAME](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377267(v=vs.85)) structure pointed to by *lprasentryname*, specifies a version of the structure that is not supported on the current platform. For example, on Windows 95, **RasEnumEntries** returns this error if **dwSize** indicates that [RASENTRYNAME](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377267(v=vs.85)) includes the **dwFlags** and **szPhonebookPath** members, since these members are not supported on Windows 95 (they are supported only on Windows 2000 and later). |
| **ERROR_NOT_ENOUGH_MEMORY** | The function could not allocate sufficient memory to complete the operation. |

## Remarks

The following sample code enumerates the RAS phone-book entries on Windows Vista and later versions of Windows. The code initially calls
**RasEnumEntries** to obtain the size of the buffer to pass in. The code then calls
**RasEnumEntries** again, to enumerate the entries. Note that for the second call, the code sets the **dwSize** member of the first
[RASENTRYNAME](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377267(v=vs.85)) structure in the buffer to sizeof(**RASENTRYNAME**) to specify the structure version.

```cpp
#include <windows.h>
#include <stdio.h>
#include "ras.h"
#include "raserror.h"
#pragma comment(lib, "rasapi32.lib")

DWORD __cdecl wmain(){

    DWORD dwCb = 0;
    DWORD dwRet = ERROR_SUCCESS;
    DWORD dwEntries = 0;
    LPRASENTRYNAME lpRasEntryName = NULL;

    // Call RasEnumEntries with lpRasEntryName = NULL. dwCb is returned with the required buffer size and
    // a return code of ERROR_BUFFER_TOO_SMALL
    dwRet = RasEnumEntries(NULL, NULL, lpRasEntryName, &dwCb, &dwEntries);

    if (dwRet == ERROR_BUFFER_TOO_SMALL){
        // Allocate the memory needed for the array of RAS entry names.
        lpRasEntryName = (LPRASENTRYNAME) HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, dwCb);
        if (lpRasEntryName == NULL){
            wprintf(L"HeapAlloc failed!\n");
            return 0;
        }
        // The first RASENTRYNAME structure in the array must contain the structure size
        lpRasEntryName[0].dwSize = sizeof(RASENTRYNAME);

        // Call RasEnumEntries to enumerate all RAS entry names
        dwRet = RasEnumEntries(NULL, NULL, lpRasEntryName, &dwCb, &dwEntries);

        // If successful, print the RAS entry names
        if (ERROR_SUCCESS == dwRet){
            wprintf(L"The following RAS entry names were found:\n");
            for (DWORD i = 0; i < dwEntries; i++){
                wprintf(L"%s\n", lpRasEntryName[i].szEntryName);
            }
        }
        //Deallocate memory for the connection buffer
        HeapFree(GetProcessHeap(), 0, lpRasEntryName);
        lpRasEntryName = NULL;
        return 0;
    }

    // There was either a problem with RAS or there are RAS entry names to enumerate
    if(dwEntries >= 1){
        wprintf(L"The operation failed to acquire the buffer size.\n");
    }else{
        wprintf(L"There were no RAS entry names found:.\n");
    }

    return 0;
}

```

> [!NOTE]
> The ras.h header defines RasEnumEntries as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RASENTRYNAME](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377267(v=vs.85))

[RasEnumConnections](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasenumconnectionsa)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)