# SCardUIDlgSelectCardW function

## Description

The **SCardUIDlgSelectCard** function displays the [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) **Select Card** dialog box.

## Parameters

### `unnamedParam1` [in]

Pointer to the
[OPENCARDNAME_EX](https://learn.microsoft.com/windows/desktop/api/winscard/ns-winscard-opencardname_exa) structure for the **Select Card** dialog box.

## Return value

If the function successfully displays the
**Select Card** dialog box, the return value is SCARD_S_SUCCESS.

If the function fails, it returns an error code. For more information, see
[Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values).

## Remarks

The **SCardUIDlgSelectCard** function provides a method for connecting to a specific [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). When called, this function performs a search for appropriate smart cards matching the [OPENCARD_SEARCH_CRITERIA](https://learn.microsoft.com/windows/desktop/api/winscard/ns-winscard-opencard_search_criteriaa) member specified by the *pDlgStruc* parameter. Depending on the **dwFlags** member of **pDlgStruc**, this function takes the following actions.

| Value | Action |
| --- | --- |
| SC_DLG_FORCE_UI | Connects to the card selected by the user from the smart card **Select Card** dialog box. |
| SC_DLG_MINIMAL_UI | Selects the smart card if only one smart card meets the criteria, or returns information about the user's selection if more than one smart card meets the criteria. |
| SC_DLG_NO_UI | Selects the first available card. |

This function replaces
[GetOpenCardName](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-getopencardnamea). The **GetOpenCardName** function is maintained for backward compatibility with version 1.0 of the Microsoft Smart Card Base Components.

#### Examples

The following example shows how to display the smart card **Select Card** dialog box.

```cpp
SCARDCONTEXT     hSC;
OPENCARDNAME_EX  dlgStruct;
WCHAR            szReader[256];
WCHAR            szCard[256];
LONG             lReturn;

// Establish a context.
// It will be assigned to the structure's hSCardContext field.
lReturn = SCardEstablishContext(SCARD_SCOPE_USER,
                                NULL,
                                NULL,
                                &hSC );
if ( SCARD_S_SUCCESS != lReturn )
{
    printf("Failed SCardEstablishContext\n");
    exit(1);
}

// Initialize the structure.
memset(&dlgStruct, 0, sizeof(dlgStruct));
dlgStruct.dwStructSize = sizeof(dlgStruct);
dlgStruct.hSCardContext = hSC;
dlgStruct.dwFlags = SC_DLG_FORCE_UI;
dlgStruct.lpstrRdr = (LPSTR) szReader;
dlgStruct.nMaxRdr = 256;
dlgStruct.lpstrCard = (LPSTR) szCard;
dlgStruct.nMaxCard = 256;
dlgStruct.lpstrTitle = (LPSTR) "My Select Card Title";

// Display the select card dialog box.
lReturn = SCardUIDlgSelectCard(&dlgStruct);
if ( SCARD_S_SUCCESS != lReturn )
    printf("Failed SCardUIDlgSelectCard - %x\n", lReturn );
else
    printf("Reader: %S\nCard: %S\n", szReader, szCard );

// Release the context (by SCardReleaseContext - not shown here).

```

> [!NOTE]
> The winscard.h header defines SCardUIDlgSelectCard as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[OPENCARDNAME_EX](https://learn.microsoft.com/windows/desktop/api/winscard/ns-winscard-opencardname_exa)