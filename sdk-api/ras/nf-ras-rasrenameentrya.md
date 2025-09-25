# RasRenameEntryA function

## Description

The
**RasRenameEntry** function changes the name of an entry in a phone book.

## Parameters

### `unnamedParam1` [in]

Pointer to a null-terminated string that specifies the full path and file name of a phone-book (PBK) file. If this parameter is **NULL**, the function uses the current default phone-book file. The default phone-book file is the one selected by the user in the **User Preferences** property sheet of the **Dial-Up Networking** dialog box.

**Windows Me/98/95:** This parameter should always be **NULL**. Dial-up networking stores phone-book entries in the registry rather than in a phone-book file.

### `unnamedParam2` [in]

Pointer to a null-terminated string that specifies an existing entry name.

### `unnamedParam3` [in]

Pointer to a null-terminated string that specifies the new entry name. Before calling
**RasRenameEntry**, call the
[RasValidateEntryName](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasvalidateentrynamea) function to validate the new entry name.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

| Value | Meaning |
| --- | --- |
| **ERROR_NOT_ENOUGH_MEMORY** | The function could not allocate sufficient memory to complete the operation. |
| **ERROR_INVALID_NAME** | The *lpszNewEntry* name is invalid. |
| **ERROR_ALREADY_EXISTS** | An entry with the *lpszNewEntry* name already exists. |
| **ERROR_CANNOT_FIND_PHONEBOOK_ENTRY** | The phone-book entry does not exist. |

## Remarks

The
**RasRenameEntry** function allows entry names that would not be accepted by the dial-up networking user interface. The entry names specified in
**RasRenameEntry** can consist of any string that adheres to the following conditions:

1. The string cannot have a length greater than RAS_MaxEntryName (as defined in Ras.h).
2. The string cannot consist entirely of space or tab characters.
3. The first character in the string cannot be a period character (".").

The following code sample renames the phone-book entry with the name specified by *pszOldName* to the new name specified by *pszNewName*.

```cpp
#include <windows.h>
#include <stdio.h>
#include "ras.h"
#include <tchar.h>

DWORD main (){

    DWORD dwErr = ERROR_SUCCESS;
    LPCTSTR pszOldName = L"RAS Connection 1\0";
    LPCTSTR pszNewName = L"RAS Connection 2\0";

    dwErr = RasValidateEntryName(NULL, pszNewName);
    if (ERROR_SUCCESS != dwErr)
    {
        printf("RasValidateEntryName failed: Error = %d\n", dwErr);
        return dwErr;
    }

    dwErr = RasRenameEntry(NULL, pszOldName, pszNewName);
    if (ERROR_SUCCESS != dwErr)
    {
        printf("RasRenameEntry failed: Error = %d\n", dwErr);
        return dwErr;
    }

    printf("Successfully renamed entry '%s' to '%s'\n", pszOldName, pszNewName);

    return 0;
}

```

> [!NOTE]
> The ras.h header defines RasRenameEntry as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RasValidateEntryName](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasvalidateentrynamea)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)