# IContact::GetPath

## Description

Retrieves the file system path used to load this contact.

## Parameters

### `pszPath` [in, out]

Type: **LPWSTR**

User-allocated buffer to store the contact ID.

### `cchPath` [in]

Type: **DWORD**

Specifies the allocated buffer size in characters.

### `pdwcchPathRequired` [in, out]

Type: **DWORD***

Upon failure due to insufficient buffer, contains the required size for *pszPath*.

## Return value

Type: **HRESULT**

Returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | Success. *pszPath* contains the path. |
| **E_UNEXPECTED** | Contact ID was not loaded from a file path. |
| **ERROR_INSUFFICIENT_BUFFER** | Macro HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER) returned when *pszPath* was not large enough to store the value. The required buffer size is stored in *pdwcchPathRequired*. |