# EncryptionDisable function

## Description

Disables or enables encryption of the specified directory and the files in it. It does not
affect encryption of subdirectories below the indicated directory.

## Parameters

### `DirPath` [in]

The name of the directory for which to enable or
disable encryption.

### `Disable` [in]

Indicates whether to disable encryption (**TRUE**) or enable it
(**FALSE**).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Under normal circumstances, [EncryptFile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-encryptfilea) will not encrypt
files and directories with the **FILE_ATTRIBUTE_SYSTEM** attribute set. It is possible to
override the **FILE_ATTRIBUTE_SYSTEM** attribute and encrypt files. Also, if a file or
directory is marked with the **FILE_ATTRIBUTE_SYSTEM** attribute, it will normally be
invisible to the user in directory listings and Windows Explorer directory windows.
**EncryptionDisable** disables encryption of directories and files. It does not
affect the visibility of files with the **FILE_ATTRIBUTE_SYSTEM** attribute set.

If **TRUE** is passed in,
**EncryptionDisable** will write the following to the
Desktop.ini file in the directory (creating it if necessary):

``` syntax
[Encryption]
Disable=1
```

If the section already exists but *Disable* is set to 0, it will be set to 1.

Thereafter, [EncryptFile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-encryptfilea) will fail on the
directory and the files in it, and the code that
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns will be
**ERROR_DIR_EFS_DISALLOWED**. This function does not affect encryption of subdirectories
within the given directory.

The user can also manually add or edit the above lines in the Desktop.ini file and produce the
same effect.

**EncryptionDisable** affects only
[FileEncryptionStatus](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-fileencryptionstatusa) and
[EncryptFile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-encryptfilea). After the directory is
encrypted, any new files and new subdirectories created without the
**FILE_ATTRIBUTE_SYSTEM** attribute will be encrypted.

If **FALSE** is passed in,
**EncryptionDisable** will write the following to the
Desktop.ini file:

``` syntax
[Encryption]
Disable=0
```

This means that file encryption is permitted on the files in that directory.

If you try to use **EncryptionDisable** to set the
directory to the state it is already in, the function succeeds but has no effect.

If you try to use **EncryptionDisable** to disable or
enable encryption on a file, the attempt will fail.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | No |
| Resilient File System (ReFS) | No |

SMB 3.0 does not support EFS on shares with continuous availability capability.

## See also

[DecryptFile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-decryptfilea)

[EncryptFile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-encryptfilea)

[File Attribute Constants](https://learn.microsoft.com/windows/desktop/FileIO/file-attribute-constants)

[File Encryption](https://learn.microsoft.com/windows/desktop/FileIO/file-encryption)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[FileEncryptionStatus](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-fileencryptionstatusa)

[GetFileAttributes](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileattributesa)