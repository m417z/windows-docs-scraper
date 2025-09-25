# RASPBDLGFUNCA callback function

## Description

The
**RasPBDlgFunc** function is an application-defined callback function that receives notifications of user activity while the
[RasPhonebookDlg](https://learn.microsoft.com/windows/desktop/api/rasdlg/nf-rasdlg-rasphonebookdlga) dialog box is open.

## Parameters

### `unnamedParam1`

### `unnamedParam2`

### `unnamedParam3`

### `unnamedParam4`

#### - dwCallbackId [in]

Specifies the application-defined value that was specified in the **dwCallback** member of the
[RASPBDLG](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377607(v=vs.85)) structure passed to the
[RasPhonebookDlg](https://learn.microsoft.com/windows/desktop/api/rasdlg/nf-rasdlg-rasphonebookdlga) function.

#### - dwEvent [in]

A set of bit flags that specifies the event that occurred. This parameter is one of the following values.

| Value | Meaning |
| --- | --- |
| **RASPBDEVENT_AddEntry** | Received when the user creates a new phone-book entry or copies an existing phone-book entry. The *pszText* parameter is the name of the new or copied entry. The *pData* parameter is undefined. |
| **RASPBDEVENT_EditEntry** | Received when the user changes an existing phone-book entry. The *pszText* parameter is the name of the modified entry. The *pData* parameter is undefined. |
| **RASPBDEVENT_RemoveEntry** | Received when the user deletes a phone-book entry. The *pszText* parameter is the name of the deleted entry. The *pData* parameter is undefined. |
| **RASPBDEVENT_DialEntry** | Received when the user successfully dials an entry. The *pszText* parameter is the name of the newly connected entry. The *pData* parameter is undefined. |
| **RASPBDEVENT_EditGlobals** | Received when the user makes changes in the **User Preferences** property sheet. The *pszText* parameter is the full path of the default phone-book file selected by the user. The *pData* parameter is undefined. <br><br>This event is also received during dialog startup if the *lpszPhonebook* parameter of the [RasPhonebookDlg](https://learn.microsoft.com/windows/desktop/api/rasdlg/nf-rasdlg-rasphonebookdlga) call is **NULL**. In this case, the event informs the caller of the path of the default phone book. |
| **RASPBDEVENT_NoUser** | Received during dialog box initialization when the RASPBDFLAG_NoUser flag is set. The *pData* parameter is a pointer to a [RASNOUSER](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377598(v=vs.85)) structure. The callback function should fill the structure with the user's logon credentials and dialog time out. The [RasPhonebookDlg](https://learn.microsoft.com/windows/desktop/api/rasdlg/nf-rasdlg-rasphonebookdlga) function then uses the supplied credentials for authentication by the remote server. The *pszText* parameter is undefined. |
| **RASPBDEVENT_NoUserEdit** | Received if the RASPBDFLAG_NoUser flag is set and the user changes the credentials that are supplied during the **RASPBDEVENT_NoUser** event. The *pData* parameter is a pointer to the [RASNOUSER](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377598(v=vs.85)) structure that contains the updated credentials. This occurs during a dialing operation if the user changes his or her password, or if the authentication fails and the user retries authentication with different credentials. The *pszText* parameter is undefined. |

#### - pData [in]

Pointer to an additional buffer argument whose meaning depends on the event indicated in the *dwEvent* parameter.

#### - pszText [in]

Pointer to an additional string argument whose meaning depends on the event indicated in the *dwEvent* parameter.

## See also

[RASNOUSER](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377598(v=vs.85))

[RasPhonebookDlg](https://learn.microsoft.com/windows/desktop/api/rasdlg/nf-rasdlg-rasphonebookdlga)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)

## Remarks

> [!NOTE]
> The rasdlg.h header defines RASPBDLGFUNC as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).