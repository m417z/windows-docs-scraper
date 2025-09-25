# MAPIADDRESS callback function

## Description

[The use of this function is discouraged. It may be altered or unavailable in subsequent versions of Windows.]

The **MAPIAddress** function creates or modifies a set of address list entries.

## Parameters

### `lhSession` [in]

Session handle that represents a Simple MAPI session or zero. If the value of the *lhSession* parameter is zero, MAPI logs on the user and creates a session that exists only for the duration of the call. This temporary session can be an existing shared session or a new one. If necessary, a logon dialog box is displayed.

### `ulUIParam` [in]

Parent window handle or zero, indicating that if a dialog box is displayed, it is application modal. If the *ulUIParam* parameter contains a parent window handle, it is of type HWND (cast to a ULONG_PTR). If no dialog box is displayed during the call,  *ulUIParam* is ignored.

### `lpszCaption` [in]

Pointer to the caption for the address list dialog box, **NULL**, or an empty string. When the *lpszCaption* parameter is **NULL** or points to an empty string, **MAPIAddress** uses the default caption "Address Book."

### `nEditFields` [in]

The number of edit controls that should be present in the address list. The values 0 through 4 are valid. If the value of the *nEditFields* parameter is 4, each recipient class supported by the underlying messaging system has an edit control. If the value of *nEditFields* is zero, only address list browsing is possible. Values of 1, 2, or 3 control the number of edit controls present. However, if the number of recipient classes in the array pointed to by the *lpRecips* parameter is greater than the value of *nEditFields*, the number of classes in *lpRecips* is used to indicate the number of edit controls instead of the value of *nEditFields*. If the value of *nEditFields* is 1 and more than one kind of entry exists in *lpRecips*, then the *lpszLabels* parameter is ignored. Entries selected for the different controls are differentiated by the **ulRecipClass** member in the returned recipient structure.

### `lpszLabels` [in]

Pointer to a string to be used as an edit control label in the address-list dialog box. When the *nEditFields* parameter is set to any value other than 1, the *lpszLabels* parameter is ignored and should be **NULL** or point to an empty string. Also, if the caller requires the default control label "To," *lpszLabels* should be **NULL** or point to an empty string.

### `nRecips` [in]

The number of entries in the array indicated by the *lpRecips* parameter. If the value of the *nRecips* parameter is zero, *lpRecips* is ignored.

### `lpRecips` [in]

Pointer to an array of [MapiRecipDesc](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapirecipdesc) structures defining the initial recipient entries to be used to populate the address-list dialog box. The entries do not need to be grouped by recipient class; they are differentiated by the values of the **ulRecipClass** members of the **MapiRecipDesc** structures in the array. If the number of different recipient classes is greater than the value indicated by the *nEditFields* parameter, the *nEditFields* and *lpszLabels* parameters are ignored.

### `flFlags` [in]

Bitmask of option flags. The following flags can be set.

| Value | Meaning |
| --- | --- |
| **MAPI_LOGON_UI** | A dialog box should be displayed to prompt the user to log on if required. When the MAPI_LOGON_UI flag is not set, the client application does not display a logon dialog box and returns an error value if the user is not logged on. |
| **MAPI_NEW_SESSION** | An attempt should be made to create a new session rather than acquire the environment's shared session. If the MAPI_NEW_SESSION flag is not set, **MAPIAddress** uses an existing shared session. |

### `ulReserved`

Reserved; must be zero.

### `lpnNewRecips` [out]

Pointer to the number of entries in the *lppNewRecips* recipient output array. If the value of the *lpnNewRecips* parameter is zero, the *lppNewRecips* parameter is ignored.

### `*lppNewRecips` [out]

Pointer to an array of [MapiRecipDesc](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapirecipdesc) structures containing the final list of recipients. This array is allocated by **MAPIAddress**, cannot be **NULL**, and must be freed using [MAPIFreeBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nf-mapi-mapifreebuffer), even if there are no new recipients. Recipients are grouped by recipient class in the following order: MAPI_TO, MAPI_CC, MAPI_BCC.

## Return value

This function returns one of the following values.

| Return code | Description |
| --- | --- |
| **MAPI_E_FAILURE** | One or more unspecified errors occurred while addressing the message. No list of recipient entries was returned. |
| **MAPI_E_INSUFFICIENT_MEMORY** | There was insufficient memory to proceed. No list of recipient entries was returned. |
| **MAPI_E_INVALID_EDITFIELDS** | The value of the *nEditFields* parameter was outside the range of 0 through 4. No list of recipient entries was returned. |
| **MAPI_E_INVALID_RECIPS** | One or more of the recipients in the address list was not valid. No list of recipient entries was returned. |
| **MAPI_E_INVALID_SESSION** | An invalid session handle was used for the *lhSession* parameter. No list of recipient entries was returned. |
| **MAPI_E_LOGIN_FAILURE** | There was no default logon, and the user failed to log on successfully when the logon dialog box was displayed. No list of recipient entries was returned. |
| **MAPI_E_NOT_SUPPORTED** | The operation was not supported by the underlying messaging system. |
| **MAPI_E_USER_ABORT** | The user canceled one of the dialog boxes. No list of recipient entries was returned. |
| **SUCCESS_SUCCESS** | The call succeeded and a list of recipient entries was returned. |

## Remarks

The **MAPIAddress** function displays a standard address-list dialog box to show an initial set of zero or more recipients. The user can choose new entries to add to the set or make changes to existing entries. This dialog box cannot be suppressed, but the caller can set dialog box characteristics. The changed set of recipients is returned to the caller.

Before **MAPIAddress** writes new or changed recipient information, it must allocate memory for the structure array that will contain the information. Memory is also allocated as part of preloading the address book, regardless of whether new or changed recipient data is written. Client applications must call the [MAPIFreeBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nf-mapi-mapifreebuffer) function to free this memory after **MAPIAddress** returns. If any error occurs, no memory was allocated and clients do not need to call **MAPIFreeBuffer**.

## See also

[MAPIFreeBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nf-mapi-mapifreebuffer)

[MAPILogon](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapilogon)

[MapiRecipDesc](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapirecipdesc)

[Simple MAPI](https://learn.microsoft.com/previous-versions/dd296734(v=vs.85))