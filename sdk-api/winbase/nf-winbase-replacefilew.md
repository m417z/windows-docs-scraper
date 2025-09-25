# ReplaceFileW function

## Description

Replaces one file with another file, with the option of creating a backup copy of the original
file. The replacement file assumes the name of the replaced file and its identity.

## Parameters

### `lpReplacedFileName` [in]

The name of the file to be replaced.

By default, the name is limited to MAX_PATH characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt-in to remove the MAX_PATH limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

This file is opened with the **GENERIC_READ**, **DELETE**, and
**SYNCHRONIZE** access rights. The sharing mode is
**FILE_SHARE_READ** | **FILE_SHARE_WRITE** |
**FILE_SHARE_DELETE**.

The caller must have write access to the file to be replaced. For more information, see
[File Security and Access Rights](https://learn.microsoft.com/windows/desktop/FileIO/file-security-and-access-rights).

### `lpReplacementFileName` [in]

The name of the file that will replace the *lpReplacedFileName* file.

By default, the name is limited to MAX_PATH characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt-in to remove the MAX_PATH limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

The function attempts to open this file with the **SYNCHRONIZE**,
**GENERIC_READ**, **GENERIC_WRITE**,
**DELETE**, and **WRITE_DAC** access rights so that it can preserve
all attributes and ACLs. If this fails, the function attempts to open the file with the
**SYNCHRONIZE**, **GENERIC_READ**,
**DELETE**, and **WRITE_DAC** access rights. No sharing mode is
specified.

### `lpBackupFileName` [in, optional]

The name of the file that will serve as a backup copy of the *lpReplacedFileName*
file. If this parameter is **NULL**, no backup file is created. See the Remarks section for implementation details on the backup file.

By default, the name is limited to MAX_PATH characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt-in to remove the MAX_PATH limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

### `dwReplaceFlags` [in]

The replacement options. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **REPLACEFILE_WRITE_THROUGH**<br><br>0x00000001 | This value is not supported. |
| **REPLACEFILE_IGNORE_MERGE_ERRORS**<br><br>0x00000002 | Ignores errors that occur while merging information (such as attributes and ACLs) from the replaced file to the replacement file. Therefore, if you specify this flag and do not have **WRITE_DAC** access, the function succeeds but the ACLs are not preserved. |
| **REPLACEFILE_IGNORE_ACL_ERRORS**<br><br>0x00000004 | Ignores errors that occur while merging ACL information from the replaced file to the replacement file. Therefore, if you specify this flag and do not have **WRITE_DAC** access, the function succeeds but the ACLs are not preserved. To compile an application that uses this value, define the **_WIN32_WINNT** macro as 0x0600 or later.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |

### `lpExclude`

Reserved for future use.

### `lpReserved`

Reserved for future use.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following are possible error codes
for this function.

| Return code/value | Description |
| --- | --- |
| **ERROR_UNABLE_TO_MOVE_REPLACEMENT**<br><br>1176 (0x498) | The replacement file could not be renamed. If *lpBackupFileName* was specified, the replaced and replacement files retain their original file names. Otherwise, the replaced file no longer exists and the replacement file exists under its original name. |
| **ERROR_UNABLE_TO_MOVE_REPLACEMENT_2**<br><br>1177 (0x499) | The replacement file could not be moved. The replacement file still exists under its original name; however, it has inherited the file streams and attributes from the file it is replacing. The file to be replaced still exists with a different name. If *lpBackupFileName* is specified, it will be the name of the replaced file. |
| **ERROR_UNABLE_TO_REMOVE_REPLACED**<br><br>1175 (0x497) | The replaced file could not be deleted. The replaced and replacement files retain their original file names. |

If any other error is returned, such as **ERROR_INVALID_PARAMETER**, the replaced and
replacement files will retain their original file names. In this scenario, a backup file
does not exist and it is not guaranteed that the
replacement file will have inherited all of the attributes and streams of the replaced file.

## Remarks

**Tip** Starting with Windows 10, version 1607, for the unicode version of this function (**ReplaceFileW**), you can opt-in to remove the **MAX_PATH** limitation. See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file) for details.

The **ReplaceFile** function combines several steps within a
single function. An application can call **ReplaceFile** instead
of calling separate functions to save the data to a new file, rename the original file using a temporary name,
rename the new file to have the same name as the original file, and delete the original file. Another advantage is
that **ReplaceFile** not only copies the new file data, but also
preserves the following attributes of the original file:

* Creation time
* Short file name
* Object identifier
* DACLs
* Security resource attributes
* Encryption
* Compression
* Named streams not already in the replacement file

For example, if the replacement file is encrypted, but the replaced file is not encrypted, the resulting file
is not encrypted.

**Windows 7, Windows Server 2008 R2, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** Security resource attributes (**ATTRIBUTE_SECURITY_INFORMATION**) for the original
file are not preserved until Windows 8 and Windows Server 2012.

**Note**

If the replacement file is protected using [Selective Wipe](https://learn.microsoft.com/previous-versions/windows/dn440592(v=win.10)), then the replaced file will be protected by the enterprise id of the replacement file.

The resulting file has the same file ID as the replacement file.

The backup file, replaced file, and replacement file must all reside on the same volume.

To delete or rename a file, you must have either delete permission on the file or delete child permission in
the parent directory. If you set up a directory with all access except delete and delete child and the DACLs of
new files are inherited, then you should be able to create a file without being able to delete it. However, you
can then create a file, and you will get all the access you request on the handle returned to you at the time you
create the file. If you requested delete permission at the time you created the file, you could delete or rename
the file with that handle but not with any other.

> [!NOTE]
> The winbase.h header defines ReplaceFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CopyFile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-copyfile)

[CopyFileEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-copyfileexa)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[MoveFile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-movefile)

[MoveFileEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-movefileexa)

[MoveFileWithProgress](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-movefilewithprogressa)