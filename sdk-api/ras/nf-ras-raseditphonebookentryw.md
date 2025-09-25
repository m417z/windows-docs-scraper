# RasEditPhonebookEntryW function

## Description

[This function has been deprecated as of Windows Vista and its functionality has been replaced by [RasEntryDlg](https://learn.microsoft.com/windows/desktop/api/rasdlg/nf-rasdlg-rasentrydlga).]

The
**RasEditPhonebookEntry** function edits an existing phone-book entry. The function displays a dialog box in which the user can modify the existing information.

## Parameters

### `unnamedParam1` [in]

Handle to the parent window of the dialog box.

### `unnamedParam2` [in]

Pointer to a null-terminated string that specifies the full path and file name of a phone-book (PBK) file. If this parameter is **NULL**, the function uses the current default phone-book file. The default phone-book file is the one selected by the user in the **User Preferences** property sheet of the **Dial-Up Networking** dialog box.

### `unnamedParam3` [in]

Pointer to a null-terminated string that specifies the name of an existing entry in the phone-book file.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

| Return code | Description |
| --- | --- |
| **ERROR_BUFFER_INVALID** | The phone-book entry buffer is invalid. |
| **ERROR_CANNOT_OPEN_PHONEBOOK** | The phone book is corrupted or missing components. |
| **ERROR_CANNOT_FIND_PHONEBOOK_ENTRY** | The phone-book entry does not exist. |

## Remarks

When calling [RasEntryDlg](https://learn.microsoft.com/windows/desktop/api/rasdlg/nf-rasdlg-rasentrydlga), set each member of the [RASENTRYDLG](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377260(v=vs.85)) structure passed to *lpinfo* to zero except:

* *dwSize* = sizeof([RASENTRYDLG](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377260(v=vs.85)))
* *hwndOwner* = the *hwnd* parameter above

> [!NOTE]
> The ras.h header defines RasEditPhonebookEntry as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RasCreatePhonebookEntry](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rascreatephonebookentrya)

[RasEntryDlg](https://learn.microsoft.com/windows/desktop/api/rasdlg/nf-rasdlg-rasentrydlga)

[RasGetEntryDialParams](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetentrydialparamsa)

[RasSetEntryDialParams](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rassetentrydialparamsa)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)