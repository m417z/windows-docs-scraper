# RasCreatePhonebookEntryA function

## Description

[This function has been deprecated as of Windows Vista and its functionality has been replaced by [RasDialDlg](https://learn.microsoft.com/windows/desktop/api/rasdlg/nf-rasdlg-rasdialdlga). ]

The
**RasCreatePhonebookEntry** function creates a new phone-book entry. The function displays a dialog box in which the user types information for the phone-book entry.

## Parameters

### `unnamedParam1` [in]

Handle to the parent window of the dialog box.

### `unnamedParam2` [in]

 Pointer to a **null**-terminated string that specifies the full path and file name of a phone-book (PBK) file. If this parameter is **NULL**, the function uses the current default phone-book file. The default phone-book file is the one selected by the user in the **User Preferences** property sheet of the **Dial-Up Networking** dialog box.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

| Return code | Description |
| --- | --- |
| **ERROR_CANNOT_OPEN_PHONEBOOK** | The phone book is corrupted or missing components. |

## Remarks

When calling [RasDialDlg](https://learn.microsoft.com/windows/desktop/api/rasdlg/nf-rasdlg-rasdialdlga), set each member of the **RASDIALDLG** structure passed to *lpInfo* to zero except:

* *dwSize* = sizeof(**RASDIALDLG**)
* *hwndOwner* = the *hwnd* parameter above
* *dwFlags* = **RASEDFLAG_NewEntry**

> [!NOTE]
> The ras.h header defines RasCreatePhonebookEntry as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RasEditPhonebookEntry](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-raseditphonebookentrya)

[RasEntryDlg](https://learn.microsoft.com/windows/desktop/api/rasdlg/nf-rasdlg-rasentrydlga)

[RasGetEntryDialParams](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetentrydialparamsa)

[RasSetEntryDialParams](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rassetentrydialparamsa)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)