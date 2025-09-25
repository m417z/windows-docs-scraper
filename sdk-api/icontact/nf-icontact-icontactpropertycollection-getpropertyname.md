# IContactPropertyCollection::GetPropertyName

## Description

Retrieves the name for the current property in the enumeration.

## Parameters

### `pszPropertyName` [in, out]

Type: **LPWSTR**

On success, contains the name to use for querying on [IContactProperties](https://learn.microsoft.com/previous-versions/windows/desktop/api/icontact/nn-icontact-icontactproperties).
EX: toplevel -or- toplevel/secondlevel[4]/thirdlevel.

### `cchPropertyName` [in]

Type: **DWORD**

Specifies caller-allocated buffer size in characters.

### `pdwcchPropertyNameRequired` [in, out]

Type: **DWORD***

On failure, contains the required size for *pszPropertyName*.

## Return value

Type: **HRESULT**

Returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | Query is successful. |
| **ERROR_INSUFFICIENT_BUFFER** | *pszPropertyName* was not large enough to store the value. The required buffer size is stored in **pdwcchPropertyNameRequired*. |