# RasValidateEntryNameW function

## Description

The
**RasValidateEntryName** function validates the format of a connection entry name. The name must contain at least one non-white-space alphanumeric character.

## Parameters

### `unnamedParam1` [in]

A pointer to a null-terminated string that specifies the full path and file name of a phone-book (PBK) file. If this parameter is **NULL**, the function uses the current default phone-book file.

**Windows Me/98/95:** This parameter should always be **NULL**. Dial-up networking stores phone-book entries in the registry rather than in a phone-book file.

### `unnamedParam2` [in]

Pointer to a null-terminated string that specifies an entry name.

The following characters are not allowed in an entry name.

| Character | Meaning |
| --- | --- |
| **\|** | vertical bar |
| **>** | greater than symbol |
| **<** | less than symbol |
| **?** | question mark |
| ***** | asterisk |
| **\** | backward slash |
| **/** | forward slash |
| **:** | colon |

**Windows 2000 or later:** The entry name cannot begin with a period (".").

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

| Value | Meaning |
| --- | --- |
| **ERROR_ALREADY_EXISTS** | The entry name already exists in the specified phonebook. |
| **ERROR_CANNOT_FIND_PHONEBOOK** | The specified phonebook doesn't exist. |
| **ERROR_INVALID_NAME** | The format of the specified entry name is invalid. |

## Remarks

The following sample code validates the phone-book entry specified by the variable *lpszEntry*.

```cpp
#include <windows.h>
#include <stdio.h>
#include "ras.h"
#include <tchar.h>

DWORD __cdecl wmain(){

    LPTSTR lpszEntry = L"EntryName\0";

    DWORD nRet = RasValidateEntryName(NULL, lpszEntry);

    switch (nRet)
    {
        case ERROR_SUCCESS:
            printf("Entry name: %s is valid but doesn't exist in the default phone book\n", lpszEntry);
            break;
        case ERROR_INVALID_NAME:
            printf("Entry name: %s is invalid\n", lpszEntry);
            break;
        case ERROR_ALREADY_EXISTS:
            printf("Entry name: %s already exists in the default phone book\n", lpszEntry);
            break;
        default:
            printf("RasValidateEntryName failed: Error = %d\n", nRet);
            break;
    }
}

```

> [!NOTE]
> The ras.h header defines RasValidateEntryName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RasCreatePhonebookEntry](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rascreatephonebookentrya)

[RasGetEntryProperties](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetentrypropertiesa)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)