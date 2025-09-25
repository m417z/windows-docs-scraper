# RasDialDlgA function

## Description

The
**RasDialDlg** function establishes a RAS connection using a specified phone-book entry and the credentials of the logged-on user. The function displays a stream of dialog boxes that indicate the state of the connection operation.

## Parameters

### `lpszPhonebook` [in]

Pointer to a null-terminated string that specifies the full path and file name of a phone-book (PBK) file. If this parameter is **NULL**, the function uses the current default phone-book file. The default phone-book file is the one selected by the user in the **User Preferences** property sheet of the **Dial-Up Networking** dialog box.

### `lpszEntry` [in]

Pointer to a null-terminated string that specifies the name of the phone-book entry to dial.

### `lpszPhoneNumber` [in]

Pointer to a null-terminated string that specifies a phone number that overrides the numbers stored in the phone-book entry. If this parameter is **NULL**,
**RasDialDlg** uses the numbers in the phone-book entry.

### `lpInfo` [in]

Pointer to a
[RASDIALDLG](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377023(v=vs.85)) structure that specifies additional input and output parameters. The **dwSize** member of this structure must specify sizeof(**RASDIALDLG**). If an error occurs, the **dwError** member returns an error code; otherwise, it returns zero.

## Return value

If the function establishes a RAS connection, the return value is **TRUE**. Otherwise, the function should return **FALSE**.

If an error occurs, **RasDialDlg** should set the **dwError** member of the
[RASDIALDLG](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377023(v=vs.85)) structure to a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

## Remarks

The
**RasDialDlg** function displays a series of dialog boxes that are similar to the dialog boxes the main **Dial-Up Networking** dialog box displays when the user selects the **Dial** button. Use the
**RasDialDlg** function to display a standard user interface for a connection operation without presenting the main phone-book dialog box. For example, the RAS AutoDial service uses this function to establish a connection using the phone-book entry associated with a remote address.

The
**RasDialDlg** function displays dialog boxes during the connection operation to provide feedback to the user about the progress of the operation. For example, the dialog boxes might indicate when the operation is dialing, when it is authenticating the user's credentials on the remote server, and so on. The dialog boxes also provide a **Cancel** button for the user to terminate the operation.

**RasDialDlg** returns when the connection is established, or when the user cancels the operation.

The following sample code dials the entry in the default phone-book specified by the variable *lpszEntry*.

**Note** This simple sample is intended to run on Windows Vista and later versions of Windows. Please be aware the call to sizeof(RASENTRY) will return a different value depending on what version of the operating system the code is being run. Please take steps to ensure this is handled appropriately.

```cpp
#include <windows.h>
#include <stdio.h>
#include "ras.h"
#include "rasdlg.h"
#include <tchar.h>
#include "strsafe.h"

#define PHONE_NUMBER_LENGTH 7
#define DEVICE_NAME_LENGTH 5
#define DEVICE_TYPE_LENGTH 5

DWORD __cdecl wmain(){

    DWORD dwError = ERROR_SUCCESS;
    BOOL nRet = TRUE;
    LPTSTR lpszEntry = L"EntryName";
    LPTSTR lpszphonenumber = L"5555555";
    LPTSTR lpszdevicename = L"Modem";
    LPTSTR lpszdevicetype = RASDT_Modem;

    // Allocate heap memory and initialize RASENTRY structure
    LPRASENTRY lpentry = (LPRASENTRY)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(RASENTRY));
    // Allocate heap memory and initialize RASDIALDLG structure
    LPRASDIALDLG lpInfo = (LPRASDIALDLG) HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(RASDIALDLG));

    if (lpentry == NULL || lpInfo == NULL){
        wprintf(L"HeapAlloc failed");
        HeapFree(GetProcessHeap(), 0, lpentry);
        HeapFree(GetProcessHeap(), 0, lpInfo);
        return 0;
    }

    // The RASDIALDLG and RASENTRY dwSize members have to be initialized or the RasDialDlg()
    // RasSetEntryProperties() APIs will fail below.
    lpInfo->dwSize = sizeof(RASDIALDLG);
    lpentry->dwSize = sizeof(RASENTRY);
    lpentry->dwFramingProtocol = RASFP_Ppp;
    lpentry->dwfOptions = 0;
    lpentry->dwType = RASFP_Ppp;
    dwError |= StringCchCopyN(lpentry->szLocalPhoneNumber, RAS_MaxPhoneNumber, lpszphonenumber, PHONE_NUMBER_LENGTH);
    dwError |= StringCchCopyN(lpentry->szDeviceName, RAS_MaxDeviceName, lpszdevicename, DEVICE_NAME_LENGTH);
    dwError |= StringCchCopyN(lpentry->szDeviceType, RAS_MaxDeviceType, lpszdevicetype, DEVICE_TYPE_LENGTH);

    if (dwError != S_OK){
        wprintf(L"Structure initialization failed: Error = %d\n", dwError);
        HeapFree(GetProcessHeap(), 0, lpentry);
        HeapFree(GetProcessHeap(), 0, lpInfo);
        return 0;
    }

    // Validate the new entry's name
    dwError = RasValidateEntryName(NULL, lpszEntry);
    if (dwError != ERROR_SUCCESS){
        wprintf(L"RasValidateEntryName failed: Error = %d\n", dwError);
        HeapFree(GetProcessHeap(), 0, lpentry);
        HeapFree(GetProcessHeap(), 0, lpInfo);
        return 0;
    }

    // Create and set the new entry's properties
    dwError = RasSetEntryProperties(NULL, lpszEntry, lpentry, lpentry->dwSize, NULL, 0);
    if (dwError != ERROR_SUCCESS){
        wprintf(L"RasSetEntryProperties failed: Error = %d\n", dwError);
        HeapFree(GetProcessHeap(), 0, lpentry);
        HeapFree(GetProcessHeap(), 0, lpInfo);
        return 0;
    }

    // Connect using the new entry
    nRet = RasDialDlg(NULL, lpszEntry, NULL, lpInfo);
    if (nRet != TRUE){
        wprintf(L"RasDialDlg failed: Error = %d\n", lpInfo->dwError);
    }

    // Clean up: delete the new entry
    dwError = RasDeleteEntry(NULL, lpszEntry);
    if (dwError != ERROR_SUCCESS){
        wprintf(L"RasDeleteEntry failed: Error = %d\n", dwError);
    }

    HeapFree(GetProcessHeap(), 0, lpentry);
    HeapFree(GetProcessHeap(), 0, lpInfo);

    return 0;
}

```

> [!NOTE]
> The rasdlg.h header defines RasDialDlg as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RASDIALDLG](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377023(v=vs.85))

[RasPhonebookDlg](https://learn.microsoft.com/windows/desktop/api/rasdlg/nf-rasdlg-rasphonebookdlga)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)