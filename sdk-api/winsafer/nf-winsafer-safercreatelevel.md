# SaferCreateLevel function

## Description

The **SaferCreateLevel** function opens a SAFER_LEVEL_HANDLE.

## Parameters

### `dwScopeId` [in]

The scope of the level to be created. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **SAFER_SCOPEID_MACHINE**<br><br>1 | The scope of the created level is by computer. |
| **SAFER_SCOPEID_USER**<br><br>2 | The scope of the created level is by user. |

### `dwLevelId` [in]

The level of the handle to be opened. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **SAFER_LEVELID_CONSTRAINED**<br><br>0x10000 | Software cannot access certain resources, such as cryptographic keys and credentials, regardless of the user rights of the user. |
| **SAFER_LEVELID_DISALLOWED**<br><br>0x00000 | Software will not run, regardless of the user rights of the user. |
| **SAFER_LEVELID_FULLYTRUSTED**<br><br>0x40000 | Software user rights are determined by the user rights of the user. |
| **SAFER_LEVELID_NORMALUSER**<br><br>0x20000 | Allows programs to execute as a user that does not have **Administrator** or **Power User** user rights. Software can access resources accessible by normal users. |
| **SAFER_LEVELID_UNTRUSTED**<br><br>0x01000 | Allows programs to execute with access only to resources granted to open well-known groups, blocking access to **Administrator** and **Power User** privileges and personally granted rights. |

### `OpenFlags` [in]

This can be the following value.

| Value | Meaning |
| --- | --- |
| **SAFER_LEVEL_OPEN**<br><br>1 |  |

### `pLevelHandle` [out]

The returned SAFER_LEVEL_HANDLE. When you have finished using the handle, close it by calling the [SaferCloseLevel](https://learn.microsoft.com/windows/desktop/api/winsafer/nf-winsafer-safercloselevel) function.

### `lpReserved`

This parameter is reserved for future use. Set it to **NULL**.

## Return value

Returns nonzero if successful or zero otherwise.

For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).