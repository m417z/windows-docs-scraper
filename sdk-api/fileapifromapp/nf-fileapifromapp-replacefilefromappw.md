## Description

Replaces one file with another file, with the option of creating a backup copy of the original file. The behavior of this function is identical to [**ReplaceFile**](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-replacefilew), except that this function adheres to the Universal Windows Platform app security model.

## Parameters

### `lpReplacedFileName`

For information about opting out of the **MAX\_PATH** limitation without prepending "\\\\?\\", see the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.
This file is opened with the **GENERIC\_READ**, **DELETE**, and **SYNCHRONIZE** access rights. The sharing mode is **FILE\_SHARE\_READ** | **FILE\_SHARE\_WRITE** | **FILE\_SHARE\_DELETE**.
The caller must have write access to the file to be replaced. For more information, see [File Security and Access Rights](https://learn.microsoft.com/windows/win32/fileio/file-security-and-access-rights).

### `lpReplacementFileName`

 The name of the file that will replace the *lpReplacedFileName* file.
For information about opting out of the **MAX\_PATH** limitation without prepending "\\\\?\\", see the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

The function attempts to open this file with the **SYNCHRONIZE**, **GENERIC\_READ**, **GENERIC\_WRITE**, **DELETE**, and **WRITE\_DAC** access rights so that it can preserve all attributes and ACLs. If this fails, the function attempts to open the file with the **SYNCHRONIZE**, **GENERIC\_READ**, **DELETE**, and **WRITE\_DAC** access rights. No sharing mode is specified.

### `lpBackupFileName`

 The name of the file that will serve as a backup copy of the *lpReplacedFileName* file. If this parameter is **NULL**, no backup file is created. See the Remarks section for implementation details on the backup file.
For information about opting out of the **MAX\_PATH** limitation without prepending "\\\\?\\", see the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

### `dwReplaceFlags`

The replacement options. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **REPLACEFILE_WRITE_THROUGH** 0x00000001 | This value is not supported. |
| **REPLACEFILE_IGNORE_MERGE_ERRORS** 0x00000002 | Ignores errors that occur while merging information (such as attributes and ACLs) from the replaced file to the replacement file. Therefore, if you specify this flag and do not have **WRITE_DAC** access, the function succeeds but the ACLs are not preserved. |
| **REPLACEFILE_IGNORE_ACL_ERRORS** 0x00000004 | Ignores errors that occur while merging ACL information from the replaced file to the replacement file. Therefore, if you specify this flag and do not have **WRITE_DAC** access, the function succeeds but the ACLs are not preserved. To compile an application that uses this value, define the **_WIN32_WINNT** macro as 0x0600 or later. |

### `lpExclude`

Reserved for future use.

### `lpReserved`

Reserved for future use.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following are possible error codes for this function.

| Return code/value | Description |
| --- | --- |
| **ERROR_UNABLE_TO_MOVE_REPLACEMENT** 1176 (0x498) | The replacement file could not be renamed. If *lpBackupFileName* was specified, the replaced and replacement files retain their original file names. Otherwise, the replaced file no longer exists and the replacement file exists under its original name. |
| **ERROR_UNABLE_TO_MOVE_REPLACEMENT_2** 1177 (0x499) | The replacement file could not be moved. The replacement file still exists under its original name; however, it has inherited the file streams and attributes from the file it is replacing. The file to be replaced still exists with a different name. If *lpBackupFileName* is specified, it will be the name of the replaced file. |
| **ERROR_UNABLE_TO_REMOVE_REPLACED** 1175 (0x497) | The replaced file could not be deleted. The replaced and replacement files retain their original file names. |

If any other error is returned, such as **ERROR\_INVALID\_PARAMETER**, the replaced and replacement files will retain their original file names. In this scenario, a backup file does not exist and it is not guaranteed that the replacement file will have inherited all of the attributes and streams of the replaced file.

## Remarks

## See also