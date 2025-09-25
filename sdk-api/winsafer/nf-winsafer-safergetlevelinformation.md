# SaferGetLevelInformation function

## Description

The **SaferGetLevelInformation** function retrieves information about a policy level.

## Parameters

### `LevelHandle` [in]

The handle of the level to be queried.

### `dwInfoType` [in]

A SAFER_OBJECT_INFO_CLASS enumeration value that specifies the type of object information that should be returned. The specified value determines the size and type of the *lpQueryBuffer* parameter. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **SaferObjectLevelId**<br><br>1 | Queries for the LEVELID constant.<br><br>*lpQueryBuffer* return type: **DWORD**. |
| **SaferObjectScopeId**<br><br>2 | Queries for the user or machine scope.<br><br>*lpQueryBuffer* return type: **DWORD**. |
| **SaferObjectFriendlyName**<br><br>3 | Queries for the display name.<br><br>*lpQueryBuffer* return type: **LPCWSTR**. |
| **SaferObjectDescription**<br><br>4 | Queries for the description.<br><br>*lpQueryBuffer* return type: **LPCWSTR**. |

### `lpQueryBuffer` [out, optional]

A buffer to contain the results of the query. For the type of the returned information for each possible value of the *dwInfoType* parameter, see the *dwInfoType* parameter.

### `dwInBufferSize` [in]

The size of the *lpQueryBuffer* parameter in bytes.

### `lpdwOutBufferSize` [out]

A pointer to return the output size of the *lpQueryBuffer* parameter.

## Return value

**TRUE** if the function succeeds; otherwise, **FALSE**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).