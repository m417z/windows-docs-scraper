# IContact::GetContactID

## Description

Retrieves the local computer unique contact ID.

## Parameters

### `pszContactID` [in, out]

Type: **LPWSTR**

User allocated buffer to store the contact ID.

### `cchContactID` [in]

Type: **DWORD**

Specifies allocated buffer size.

### `pdwcchContactIDRequired` [in, out]

Type: **DWORD***

Upon failure due to insufficient buffer, contains the required size for *pszContactID*. May be **NULL**.

## Return value

Type: **HRESULT**

Returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | Success. *pszContactID* contains a null-terminated ContactID. |
| **ERROR_INSUFFICIENT_BUFFER** | Macro HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER) returned when *pszContactID* was not large enough to store the value. The required buffer size is stored in *pdwcchContactIDRequired*. |

## See also

[IContact](https://learn.microsoft.com/previous-versions/windows/desktop/api/icontact/nn-icontact-icontact)

[Load](https://learn.microsoft.com/previous-versions/windows/desktop/api/icontact/nf-icontact-icontactmanager-load)