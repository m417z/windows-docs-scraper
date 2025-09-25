# IContactProperties::SetDate

## Description

Sets the date and time value at a specified property to a given
[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime). All times are stored and returned as Coordinated Universal Time (UTC).

## Parameters

### `pszPropertyName` [in]

Type: **LPCWSTR**

Specifies the property to set.

### `dwFlags` [in]

Type: **DWORD**

CGD_DEFAULT can be used to create or overwrite value at *pszPropertyName*.

### `ftDateTime` [in]

Type: **[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)**

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure to use for date.

## Return value

Type: **HRESULT**

Returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | Value is set at this property. |
| **ERROR_PATH_NOT_FOUND** | Property name invalid for set. |
| **ERROR_INVALID_DATATYPE** | Unable to set the value for this property due to schema. |