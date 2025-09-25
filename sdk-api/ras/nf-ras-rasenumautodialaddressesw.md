# RasEnumAutodialAddressesW function

## Description

The
**RasEnumAutodialAddresses** function returns a list of all addresses in the AutoDial mapping database.

## Parameters

### `lppRasAutodialAddresses` [in, out]

Pointer to an array of string pointers, with additional space for the storage of the strings themselves at the end of the buffer.

On output, each string receives the name of an address in the AutoDial mapping database.

If *lppAddresses* is **NULL** on input,
**RasEnumAutodialAddresses** sets the *lpdwcbAddresses* and *lpdwcAddresses* parameters to indicate the required size, in bytes, and the number of address entries in the database.

### `lpdwcbRasAutodialAddresses` [in, out]

Pointer to a variable that, on input, contains the size, in bytes, of the buffer specified by the *lpRasEnumAutodialAddressespAddresses* parameter.

**Note**

To determine the required buffer size, call
**RasEnumAutodialAddresses** with *lppAddresses* set to **NULL**. The variable pointed to by *lpdwcbAddresses* should be set to zero. The function will return the required buffer size in *lpdwcbAddresses* and an error code of **ERROR_BUFFER_TOO_SMALL**.

### `lpdwcRasAutodialAddresses` [out]

Pointer to a variable that receives the number of address strings returned in the *lppAddresses* buffer.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | **NULL** was passed for the *lpdwcbAddresses* or *lpdwcAddresses* parameter. |
| **ERROR_BUFFER_TOO_SMALL** | The *lppAddresses* buffer was **NULL** and *lpdwcbAddresses* was zero. The function returns the required buffer size in the variable pointed to by *lpdwcbAddresses*. |

## Remarks

The following code sample code uses **RasEnumAutodialAddresses** to enumerate the Autodial mapping database.

```cpp
#include <windows.h>
#include <stdio.h>
#include "ras.h"
#include "raserror.h"
#include <tchar.h>

DWORD __cdecl wmain(){

    DWORD dwBytes = 0;
    DWORD dwRet = ERROR_SUCCESS;
    DWORD dwAddresses = 0;
    LPTSTR * lppAddresses = NULL;
    LPCTSTR lpEntryAddress = L"www.microsoft.com";

    // Allocate memory for a new Autodial address to add to the mapping database
    LPRASAUTODIALENTRY lpentry = (LPRASAUTODIALENTRY) HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(RASAUTODIALENTRY));
    lpentry->dwSize = sizeof(RASAUTODIALENTRY);

    // Add a (non-functional) address to the Autodial mapping database
    // (this ensures RasEnumAutodialAddresses() has something to return)
    dwRet = RasSetAutodialAddress(lpEntryAddress, 0, lpentry, lpentry->dwSize, 1);

    // Call RasEnumAutodialAddresses() with lppAddresses = NULL. dwBytes is returned with the
    // required buffer size and a return code of ERROR_BUFFER_TOO_SMALL
    dwRet = RasEnumAutodialAddresses(lppAddresses, &dwBytes, &dwAddresses);

    if (dwRet == ERROR_BUFFER_TOO_SMALL){
        // Allocate the memory needed for the array of RAS Autodial addresses.
        lppAddresses = (LPTSTR *) HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, dwBytes);
        if (lppAddresses == NULL){
            wprintf(L"HeapAlloc failed!\n");
            return 0;
        }

        // Call RasEnumAutodialAddresses() to enumerate all RAS Autodial addresses
        dwRet = RasEnumAutodialAddresses(lppAddresses, &dwBytes, &dwAddresses);

        // If successful, print the RAS Autodial addresses
        if (dwRet == ERROR_SUCCESS){
            wprintf(L"The following RAS Autodial addresses were found:\n");
            for (DWORD i = 0; i < dwAddresses; i++){
                wprintf(L"%s\n", lppAddresses[i]);
            }
        }
        // Remove the address
        dwRet = RasSetAutodialAddress(lpEntryAddress, 0, NULL, 0, 0);

        //Deallocate memory for the address buffers
        HeapFree(GetProcessHeap(), 0, lppAddresses);
        HeapFree(GetProcessHeap(), 0, lpentry);
        lppAddresses = NULL;
        return 0;
    }

    // There was either a problem with RAS or there are no RAS Autodial addresses to enumerate
    if(dwAddresses >= 1){
        wprintf(L"The operation failed to acquire the buffer size.\n");
    }else{
        wprintf(L"There were no RAS Autodial addresses found.\n");
    }

    // Remove the address
    dwRet = RasSetAutodialAddress(lpEntryAddress, 0, NULL, 0, 0);
    HeapFree(GetProcessHeap(), 0, lpentry);
    return 0;
}

```

> [!NOTE]
> The ras.h header defines RasEnumAutodialAddresses as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RASAUTODIALENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376721(v=vs.85))

[RasGetAutodialAddress](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetautodialaddressa)

[RasSetAutodialAddress](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rassetautodialaddressa)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)