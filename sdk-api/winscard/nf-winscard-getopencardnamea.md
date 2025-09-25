# GetOpenCardNameA function

## Description

The **GetOpenCardName** function displays the [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) "select card" dialog box. Call the function
[SCardUIDlgSelectCard](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scarduidlgselectcarda) instead of **GetOpenCardName**. The **GetOpenCardName** function is maintained for backward compatibility with version 1.0 of the Microsoft Smart Card Base Components, but calls to **GetOpenCardName** are mapped to **SCardUIDlgSelectCard**.

## Parameters

### `unnamedParam1` [in]

A pointer to the
[OPENCARDNAME](https://learn.microsoft.com/windows/desktop/api/winscard/ns-winscard-opencardnamea) structure for the "select card" dialog box.

## Return value

The function returns different values depending on whether it succeeds or fails.

| Return code | Description |
| --- | --- |
| **Success** | SCARD_S_SUCCESS. |
| **Failure** | An error code. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values). |

## See also

[OPENCARDNAME](https://learn.microsoft.com/windows/desktop/api/winscard/ns-winscard-opencardnamea)

## Remarks

> [!NOTE]
> The winscard.h header defines GetOpenCardName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).