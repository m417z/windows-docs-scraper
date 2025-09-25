# RasGetCredentialsA function

## Description

The
**RasGetCredentials** function retrieves the user credentials associated with a specified RAS phone-book entry.

## Parameters

### `unnamedParam1` [in]

Pointer to a **null**-terminated string that specifies the full path and file name of a phone-book (PBK) file. If this parameter is **NULL**, the function uses the current default phone-book file. The default phone-book file is the one selected by the user in the **User Preferences** property sheet of the **Dial-Up Networking** dialog box.

### `unnamedParam2` [in]

Pointer to a **null**-terminated string that specifies the name of a phone-book entry.

### `unnamedParam3` [in, out]

Pointer to the
[RASCREDENTIALS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376730(v=vs.85)) structure that, on output, receives the user credentials associated with the specified phone-book entry.

On input, set the **dwSize** member of the structure to sizeof([RASCREDENTIALS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376730(v=vs.85))), and set the **dwMask** member to indicate the credential information to retrieve. When the function returns, **dwMask** indicates the members that were successfully retrieved.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

| Value | Meaning |
| --- | --- |
| **ERROR_CANNOT_OPEN_PHONEBOOK** | The specified phone book cannot be found. |
| **ERROR_CANNOT_FIND_PHONEBOOK_ENTRY** | The specified entry does not exist in the phone book. |
| **ERROR_INVALID_PARAMETER** | The *lpCredentials* parameter was **NULL**. |
| **ERROR_INVALID_SIZE** | The **dwSize** member of the [RASCREDENTIALS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376730(v=vs.85)) structure is an unrecognized value. |

## Remarks

The
**RasGetCredentials** function retrieves the credentials of the last user in order to connect using the specified phone-book entry, or the credentials subsequently specified in a call to the
[RasSetCredentials](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rassetcredentialsa) function for the phone-book entry.

 This function is the preferred way of securely retrieving the credentials associated with a RAS phone-book entry.
**RasGetCredentials** supersedes the
[RasGetEntryDialParams](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetentrydialparamsa) function, which may not be supported in future releases of Windows.

**RasGetCredentials** does not return the actual password. Instead, the **szPassword** member of the
[RASCREDENTIALS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376730(v=vs.85)) structure contains a handle to the saved password. Substitute this handle for the saved password in subsequent calls to
[RasSetCredentials](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rassetcredentialsa) and
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala). When presented with this handle,
**RasDial** retrieves and uses the saved password. The value of this handle may change in future versions of the operating system; do not develop code that depends on the contents or format of this value.

The **dwMask** member of
[RASCREDENTIALS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376730(v=vs.85)) contains the RASCM_Password flag if the system has saved a password for the specified entry. If the system has no password saved for this entry, **dwMask** does not contain RASCM_Password.

**Windows 2000/NT:** This feature is not supported.

If the **dwMask** of the
[RASCREDENTIALS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376730(v=vs.85)) structure contains the RASCM_DefaultCreds flag, the credentials returned are the default credentials for an all-user connection.

To retrieve a pre-shared key, use the RASCM_PreSharedKey flag in the RASCREDENTIALS.dwMask field.

**Windows 2000/NT:** This feature is not supported.

The following sample code creates the "RasEntryName" phone book entry, sets its credentials using [RasSetCredentials](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rassetcredentialsa), and then retrieves those credentials using **RasGetCredentials**.

```cpp
#include <windows.h>
#include "ras.h"
#include <stdio.h>
#include <tchar.h>
#include "strsafe.h"

#define PHONE_NUMBER_LENGTH 7
#define DEVICE_NAME_LENGTH 5
#define DEVICE_TYPE_LENGTH 5
#define DOMAIN_NAME_LENGTH 9
#define USER_NAME_LENGTH 11

DWORD __cdecl wmain(){

    DWORD dwRet = ERROR_SUCCESS;
    LPTSTR lpszEntry = L"RasEntryName";
    LPTSTR lpszPhoneNumber = L"5555555";
    LPTSTR lpszDeviceName = L"Modem";
    LPTSTR lpszDeviceType = RASDT_Modem;
    LPTSTR lpszDomainName = L"RASDomain";
    LPTSTR lpszUserName = L"RASUserName";
    /***********************************************************************************************/
    // Create a new phone book entry
    /***********************************************************************************************/

    // Allocate heap memory for the RASENTRY structure
    LPRASENTRY lpentry = (LPRASENTRY)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(RASENTRY));
    if (lpentry == NULL){
        wprintf(L"HeapAlloc failed!\n");
        return 0;
    }
    // The RASENTRY->dwSize member has to be initialized or the RRAS RasValidateEntryName() and
    // RasSetEntryProperties APIs will fail below.
    lpentry->dwSize = sizeof(RASENTRY);
    lpentry->dwFramingProtocol = RASFP_Ppp;
    lpentry->dwfOptions = 0;
    lpentry->dwType = RASFP_Ppp;
    dwRet |= StringCchCopyN(lpentry->szLocalPhoneNumber, RAS_MaxPhoneNumber, lpszPhoneNumber, PHONE_NUMBER_LENGTH);
    dwRet |= StringCchCopyN(lpentry->szDeviceName, RAS_MaxDeviceName, lpszDeviceName, DEVICE_NAME_LENGTH);
    dwRet |= StringCchCopyN(lpentry->szDeviceType, RAS_MaxDeviceType, lpszDeviceType, DEVICE_TYPE_LENGTH);
    if (dwRet != ERROR_SUCCESS){
        wprintf(L"RASENTRY structure initialization failed!\n");
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

    /******************************************************************************************/
    // Set and get the new entry's credentials
    /******************************************************************************************/

    // Allocate heap memory for the RASCREDENTIALS structure
    LPRASCREDENTIALS lpCred = (LPRASCREDENTIALS) HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(RASCREDENTIALS));
    if (lpCred == NULL){
        wprintf(L"HeapAlloc failed!\n");
        return 0;
    }
    // The RASCREDENTIALS->dwsize member must be initialized or the RRAS RasSetCredentials() and
    // RasGetCredentials() APIs will fail below
    lpCred->dwSize = sizeof(RASCREDENTIALS);

    // The entry's credentials must first be set with RasSetCredentials() before they can be
    // retrieved with RasGetCredentials(). The values below are used to set the new entry's credentials.
    dwRet |= StringCchCopyN(lpCred->szDomain, DNLEN, lpszDomainName, DOMAIN_NAME_LENGTH);
    dwRet |= StringCchCopyN(lpCred->szUserName, UNLEN, lpszUserName, USER_NAME_LENGTH);
    if (dwRet != ERROR_SUCCESS){
        wprintf(L"RASCREDENTIALS structure initialization failed!\n");
        HeapFree(GetProcessHeap(), 0, lpCred);
        return 0;
    }
    // The username, password, and Domain credentials are valid
    lpCred->dwMask = RASCM_UserName | RASCM_Password | RASCM_Domain;

    // Set the newly created entry's credentials
    dwRet = RasSetCredentials(NULL, lpszEntry, lpCred, FALSE);

    // The same RASCREDENTIALS structure is used to 'set' and 'get' the credentials. Therefore, zero out
    // its values. (this proves RasGetCredentials works below!)
    dwRet |= StringCchCopyN(lpCred->szDomain, DNLEN, L"", 0);
    dwRet |= StringCchCopyN(lpCred->szUserName, UNLEN, L"", 0);
    dwRet |= StringCchCopyN(lpCred->szPassword, UNLEN, L"", 0);
    if (dwRet != ERROR_SUCCESS){
        wprintf(L"RASCREDENTIALS structure reset failed!\n");
        HeapFree(GetProcessHeap(), 0, lpCred);
        HeapFree(GetProcessHeap(), 0, lpentry);
        return 0;
    }

    // Grab the newly created entry's credentials
    dwRet = RasGetCredentials(NULL, lpszEntry, lpCred);
    if(dwRet == ERROR_SUCCESS){
        wprintf(L"The following credentials were retrieved for the entry: %s\n\tUser name: %s\n\tPassword: %s\n\tDomain: %s\n", lpszEntry, lpCred->szUserName, lpCred->szPassword, lpCred->szDomain);
    }else{
        wprintf(L"RasValidateEntryName failed: Error = %d\n", dwRet);
    }

    // Clean up: delete the new entry
    dwRet = RasDeleteEntry(NULL, lpszEntry);
    if (dwRet != ERROR_SUCCESS){
        wprintf(L"RasDeleteEntry failed: Error = %d\n", dwRet);
    }

    HeapFree(GetProcessHeap(), 0, lpentry);
    HeapFree(GetProcessHeap(), 0, lpCred);
    return 0;
}

```

> [!NOTE]
> The ras.h header defines RasGetCredentials as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RASCREDENTIALS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376730(v=vs.85))

[RasGetEntryDialParams](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetentrydialparamsa)

[RasSetCredentials](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rassetcredentialsa)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)