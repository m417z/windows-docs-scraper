# MsiCollectUserInfoW function

## Description

The
**MsiCollectUserInfo** function obtains and stores the user information and product ID from an installation wizard.

## Parameters

### `szProduct` [in]

Specifies the product code of the product for which the user information is collected.

## Return value

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. |
| **ERROR_SUCCESS** | The function succeeded. |
| **An error relating to an action** | See [Error Codes](https://learn.microsoft.com/windows/desktop/Msi/error-codes). |
| **[Initialization Error](https://learn.microsoft.com/windows/desktop/Msi/initialization-errors)** | An error relating to initialization occurred. |

## Remarks

The
**MsiCollectUserInfo** function is typically called by an application during the first run of the application. The application first calls
[MsiGetUserInfo](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msigetuserinfoa). If that call fails, the application calls
**MsiCollectUserInfo**.
**MsiCollectUserInfo** opens the product's installation package and invokes a wizard sequence that collects user information. Upon completion of the sequence, user information is registered. Since this API requires an authored user interface, the user interface level should be set to full by calling
[MsiSetInternalUI](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msisetinternalui) as INSTALLUILEVEL_FULL.

The
**MsiCollectUserInfo** invokes a
[FirstRun Dialog](https://learn.microsoft.com/windows/desktop/Msi/firstrun-dialog).

> [!NOTE]
> The msi.h header defines MsiCollectUserInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Application-Only Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)

[Error Codes](https://learn.microsoft.com/windows/desktop/Msi/error-codes)

[Initialization Error](https://learn.microsoft.com/windows/desktop/Msi/initialization-errors)