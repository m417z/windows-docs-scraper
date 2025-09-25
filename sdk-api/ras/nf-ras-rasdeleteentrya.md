# RasDeleteEntryA function

## Description

The
**RasDeleteEntry** function deletes an entry from a phone book.

## Parameters

### `unnamedParam1` [in]

 Pointer to a null-terminated string that specifies the full path and file name of a phone-book (PBK) file. If this parameter is **NULL**, the function uses the current default phone-book file. The default phone-book file is the one selected by the user in the **User Preferences** property sheet of the **Dial-Up Networking** dialog box.

**Windows Me/98/95:** This parameter should always be **NULL**. Dial-up networking stores phone-book entries in the registry rather than in a phone-book file.

### `unnamedParam2` [in]

Pointer to a null-terminated string that specifies the name of an existing entry to be deleted.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have correct privileges. Only an administrator can complete this task. |
| **ERROR_INVALID_NAME** | The entry name specified in *lpszEntry* does not exist. |

## Remarks

The following sample code deletes the phone-book entry specified by the variable *lpszEntry*.

```cpp
#include <stdio.h>
#include <windows.h>
#include "ras.h"
#include "strsafe.h"

#define PHONE_NUMBER_LENGTH 7
#define DEVICE_NAME_LENGTH 5
#define DEVICE_TYPE_LENGTH 5

DWORD __cdecl wmain(){

    DWORD dwRet = ERROR_SUCCESS;
    LPTSTR lpszEntry = L"RASEntryName";
    LPTSTR lpszphonenumber = L"5555555";
    LPTSTR lpszdevicename = L"Modem";
    LPTSTR lpszdevicetype = RASDT_Modem;

    // Allocate heap memory for the RASENTRY structure
    LPRASENTRY lpentry = (LPRASENTRY)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(RASENTRY));
    if (lpentry == NULL){
        printf("HeapAlloc failed");
        return 0;
       }

    // The RASENTRY->dwSize member has to be initialized or the RRAS APIs will fail below.
    lpentry->dwSize = sizeof(RASENTRY);
    lpentry->dwFramingProtocol = RASFP_Ppp;
    lpentry->dwfOptions = 0;
    lpentry->dwType = RASET_Phone;
    dwRet |= StringCchCopyN(lpentry->szLocalPhoneNumber, RAS_MaxPhoneNumber, lpszphonenumber, PHONE_NUMBER_LENGTH);
    dwRet |= StringCchCopyN(lpentry->szDeviceName, RAS_MaxDeviceName, lpszdevicename, DEVICE_NAME_LENGTH);
    dwRet |= StringCchCopyN(lpentry->szDeviceType, RAS_MaxDeviceType, lpszdevicetype, DEVICE_TYPE_LENGTH);
    if (dwRet != ERROR_SUCCESS){
        wprintf(L"RASENTRY structure initialization failed");
        HeapFree(GetProcessHeap(), 0, lpentry);
        return 0;
    }

    // Validate the new entry's name
    dwRet = RasValidateEntryName(NULL, lpszEntry);
    if (dwRet != ERROR_SUCCESS){
        wprintf(L"RasValidateEntryName failed: Error = %d\n", dwRet);
        HeapFree(GetProcessHeap(), 0, lpentry);
        return 0;
    }

    // Create and set the new entry's properties
    dwRet = RasSetEntryProperties(NULL, lpszEntry, lpentry, lpentry->dwSize, NULL, 0);
    if (dwRet != ERROR_SUCCESS){
        wprintf(L"RasSetEntryProperties failed: Error = %d\n", dwRet);
        HeapFree(GetProcessHeap(), 0, lpentry);
        return 0;
    }

    // Clean up: delete the new entry
    dwRet = RasDeleteEntry(NULL, lpszEntry);
    if (dwRet != ERROR_SUCCESS){
        wprintf(L"RasDeleteEntry failed: Error = %d\n", dwRet);
    }

    HeapFree(GetProcessHeap(), 0, lpentry);
    return 0;
}

```

> [!NOTE]
> The ras.h header defines RasDeleteEntry as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RasCreatePhonebookEntry](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rascreatephonebookentrya)

[RasEnumEntries](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasenumentriesa)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)