# SaferSetLevelInformation function

## Description

The **SaferSetLevelInformation** function sets the information about a policy level.

## Parameters

### `LevelHandle` [in]

The handle of the level to be set.

### `dwInfoType` [in]

A [SAFER_OBJECT_INFO_CLASS](https://learn.microsoft.com/windows/desktop/api/winsafer/ne-winsafer-safer_object_info_class) enumeration value that specifies the type of object information that should be set. The specified value determines the size and type of the *lpQueryBuffer* parameter. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **SaferObjectLevelId**<br><br>1 | Sets the LEVELID constant.<br><br>*lpQueryBuffer* return type: **DWORD**. |
| **SaferObjectScopeId**<br><br>2 | Sets the user or machine scope.<br><br>*lpQueryBuffer* return type: **DWORD**. |
| **SaferObjectFriendlyName**<br><br>3 | Sets the display name.<br><br>*lpQueryBuffer* return type: **LPCWSTR**. |
| **SaferObjectDescription**<br><br>4 | Sets the description.<br><br>*lpQueryBuffer* return type: **LPCWSTR**. |

### `lpQueryBuffer` [in]

A buffer to contain the results of the query. For the type of the returned information for each possible value of the *dwInfoType* parameter, see the *dwInfoType* parameter.

### `dwInBufferSize` [in]

The size, in bytes, of the *lpQueryBuffer* parameter.

## Return value

**TRUE** if the function succeeds; otherwise, **FALSE**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).