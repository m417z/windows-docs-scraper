# OROpenHive function

Loads the specified registry hive file into memory and validates the hive.

## Parameters

*lpHivePath* \[in\]

A pointer to a Unicode string that specifies the name of the registry hive file to be loaded into memory. This can be a hive file that was saved with the [**ORSaveHive**](https://learn.microsoft.com/windows/win32/devnotes/orsavehive) function or created with the [RegSaveKey](https://learn.microsoft.com/windows/win32/api/winreg/nf-winreg-regsavekeya) or [RegSaveKeyEx](https://learn.microsoft.com/windows/win32/api/winreg/nf-winreg-regsavekeyexa) function. The file must be less than 4 GB in size, and the caller must have FILE\_READ\_DATA access to the file. For more information, see [File Security and Access Rights](https://learn.microsoft.com/windows/win32/fileio/file-security-and-access-rights).

*phkResult* \[out\]

A pointer to a variable that receives a handle to the root key of the loaded offline registry hive. If the registry hive file cannot be opened or validation fails, the function sets this parameter to **NULL**.

## Return value

If the function succeeds, the return value is ERROR\_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function with the FORMAT\_MESSAGE\_FROM\_SYSTEM flag to get a generic description of the error. Possible error codes include the following:

- If the file is empty or larger than 4 GB in size, the function returns ERROR\_BADDB.
- If the caller does not have the necessary access rights to open the file, the function returns ERROR\_ACCESS\_DENIED.
- If the registry hive fails validation, the function returns ERROR\_NOT\_REGISTRY\_FILE.

## Remarks

The **OROpenHive** function is the only offline registry function that validates a registry hive. If the validation fails, no attempt is made to repair the hive.

## Requirements

| Requirement | Value |
|----------------------------|---------------------------------------------------------------------------------------|
| Redistributable<br> | Windows Offline Registry library version 1.0 or later<br> |
| Header<br> | Offreg.h |
| DLL<br> | Offreg.dll |

## See also

[**ORCloseHive**](https://learn.microsoft.com/windows/win32/devnotes/orclosehive)

[**ORCreateHive**](https://learn.microsoft.com/windows/win32/devnotes/orcreatehive)

[**ORSaveHive**](https://learn.microsoft.com/windows/win32/devnotes/orsavehive)

[RegSaveKey](https://learn.microsoft.com/windows/win32/api/winreg/nf-winreg-regsavekeya)

[RegSaveKeyEx](https://learn.microsoft.com/windows/win32/api/winreg/nf-winreg-regsavekeyexa)

