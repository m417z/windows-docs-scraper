## Description

Creates a new directory. The behavior of this function is identical to [**CreateDirectory**](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-createdirectory), except that this function adheres to the Universal Windows Platform app security model.

## Parameters

### `lpPathName`

The path of the directory to be created.
For information about opting out of the **MAX\_PATH** limitation without prepending "\\\\?\\", see the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

### `lpSecurityAttributes`

A pointer to a [**SECURITY\_ATTRIBUTES**](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure. The **lpSecurityDescriptor** member of the structure specifies a security descriptor for the new directory. If *lpSecurityAttributes* is **NULL**, the directory gets a default security descriptor. The ACLs in the default security descriptor for a directory are inherited from its parent directory.
The target file system must support security on files and directories for this parameter to have an effect.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). Possible errors include the following.

| Return code | Description |
| --- | --- |
| **ERROR_ALREADY_EXISTS** | The specified directory already exists. |
| **ERROR_PATH_NOT_FOUND** | One or more intermediate directories do not exist; this function will only create the final directory in the path. |

## Remarks

## See also