# IContactProperties::GetDate

## Description

Retrieves the date and time value at a specified property into a caller's
[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure. All times are stored
and returned as Coordinated Universal Time (UTC).

## Parameters

### `pszPropertyName` [in]

Type: **LPCWSTR**

Specifies the property to retrieve.

### `dwFlags` [in]

Type: **DWORD**

Must be CGD_DEFAULT.

### `pftDateTime` [in, out]

Type: **[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)***

Specifies caller-allocated [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure.

## Return value

Type: **HRESULT**

Returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | *pftDateTime* contains a valid [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime). |
| **S_FALSE** | The property has been present in the past but its value has been removed. The [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) has been zeroed. |
| **ERROR_PATH_NOT_FOUND** | No data found for this property name. |

## Remarks

To retrieve a single level property, set *pszPropertyName* to the property name.

To retrieve a value from a multi-value (hierarchical) property, include the desired index as part of *pszPropertyName* using the form: toplevel/secondlevel[1]/thirdlevel. NOTE: the first element of a set is index 1, so index [0] is invalid.