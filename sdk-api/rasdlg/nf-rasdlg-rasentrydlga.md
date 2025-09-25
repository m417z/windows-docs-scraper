# RasEntryDlgA function

## Description

The
**RasEntryDlg** function displays modal property sheets that allow a user to manipulate phone-book entries. If editing or copying an existing phone-book entry, the function displays a phone-book entry property sheet. The
**RasEntryDlg** function returns when the user closes the property sheet.

## Parameters

### `lpszPhonebook` [in]

Pointer to a **null**-terminated string that specifies the full path and file name of a phone-book (PBK) file. If this parameter is **NULL**, the function uses the current default phone-book file. The default phone-book file is the one selected by the user in the **User Preferences** property sheet of the **Dial-Up Networking** dialog box.

### `lpszEntry` [in]

Pointer to a **null**-terminated string that specifies the name of the phone-book entry to edit, copy, or create.

If you are editing or copying an entry, this parameter is the name of an existing phone-book entry. If you are copying an entry, set the **RASEDFLAG_CloneEntry** flag in the **dwFlags** member of the
[RASENTRYDLG](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377023(v=vs.85)) structure.

**Note** The **RASEDFLAG_CloneEntry** flag has been deprecated, as of
Windows Vista and Windows Server 2008. It may be altered or unavailable in subsequent versions. Instead, copy an entry by calling [RasGetEntryProperties](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetentrypropertiesa) to get the entry and then calling [RasSetEntryProperties](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rassetentrypropertiesa) to save the entry with a new name.

If you are creating an entry, this parameter is a default new entry name that the user can change. If this parameter is **NULL**, the function provides a default name. If you are creating an entry, set the **RASEDFLAG_NewEntry** flag in the **dwFlags** member of the
[RASENTRYDLG](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377023(v=vs.85)) structure.

### `lpInfo` [in]

Pointer to a
[RASENTRYDLG](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377260(v=vs.85)) structure that specifies additional input and output parameters. The **dwSize** member of this structure must specify sizeof(**RASENTRYDLG**). Use the **dwFlags** member to indicate whether you are creating, editing, or copying an entry. If an error occurs, the **dwError** member returns an error code; otherwise, it returns zero.

## Return value

If the user creates, copies, or edits a phone-book entry, the return value is **TRUE**. Otherwise, the function returns **FALSE**.

 If an error occurs, **RasEntryDlg** sets the **dwError** member of the
[RASENTRYDLG](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377260(v=vs.85)) structure to a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

## Remarks

The
[RasCreatePhonebookEntry](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rascreatephonebookentrya) and
[RasEditPhonebookEntry](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-raseditphonebookentrya) functions call the
**RasEntryDlg** function.

The following sample code brings up a property sheet to create a new entry. The *lpszEntry* variable specifies the default name for the new entry.

```cpp
#include <windows.h>
#include <stdio.h>
#include "ras.h"
#include "rasdlg.h"
#include <tchar.h>

DWORD __cdecl wmain(){

    DWORD dwRet = ERROR_SUCCESS;
    BOOL nRet = TRUE;
    LPTSTR lpszEntry = L"EntryName";

    // Allocate heap memory and initialize RASENTRYDLG structure
    LPRASENTRYDLG lpEntry = (LPRASENTRYDLG)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(RASENTRYDLG));
    if (lpEntry == NULL){
        wprintf(L"HeapAlloc failed.\n");
        return 0;
    }

    // The RASENTRYDLG->dwSize member has to be initialized or the RRAS APIs will fail below.
    lpEntry->dwSize = sizeof(RASENTRYDLG);
    lpEntry->dwFlags |= RASEDFLAG_NewEntry;

    // Create the new entry using a user dialog
    nRet = RasEntryDlg(NULL, lpszEntry, lpEntry);

    // Any error codes are returned in lpEntry
    dwRet = lpEntry->dwError;

    if (nRet == TRUE) {
        wprintf(L"New entry created: %s\n", lpEntry->szEntry);

        // Clean up: delete the new entry
        dwRet = RasDeleteEntry(NULL, lpszEntry);
        if (dwRet != ERROR_SUCCESS) {
            wprintf(L"RasDeleteEntry failed: Error = %d\n", dwRet);
        }

    }
    else {
        if (dwRet != ERROR_SUCCESS) {
            wprintf(L"RasEntryDlg failed: Error = %d\n", dwRet);
        }
        else {
            wprintf(L"User pressed Cancel\n");
        }
    }

    HeapFree(GetProcessHeap(), 0, lpEntry);
    return 0;
}

```

> [!NOTE]
> The rasdlg.h header defines RASENTRYDLG as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RASENTRYDLG](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377260(v=vs.85))

[RasCreatePhonebookEntry](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rascreatephonebookentrya)

[RasCustomEntryDlg](https://learn.microsoft.com/windows/desktop/api/rasdlg/nc-rasdlg-rascustomentrydlgfn)

[RasEditPhonebookEntry](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-raseditphonebookentrya)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)