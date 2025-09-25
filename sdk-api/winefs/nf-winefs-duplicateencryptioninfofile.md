# DuplicateEncryptionInfoFile function

## Description

Copies the EFS metadata from one file or directory to another.

## Parameters

### `SrcFileName` [in]

The name of the file or directory from which the EFS metadata is to be copied. This source file or directory must be encrypted.

### `DstFileName` [in]

The name of the file or directory to which the EFS metadata is to be copied.

This destination file or directory does not have to be encrypted before the call to this function; however if this function completes successfully, it will be encrypted.

If the value of *SrcFileName* specifies a file, the value of this parameter must also specify a file, and likewise for directories. If a file or directory with the name specified by this parameter does not exist, a file or directory (depending on whether *SrcFileName* specifies a file or directory) will be created.

### `dwCreationDistribution` [in]

Describes how the destination file or directory identified by the *DstFileName* parameter value is to be opened. The following are the valid values of this parameter.

| Value | Meaning |
| --- | --- |
| **CREATE_ALWAYS**<br><br>2 | Always create the destination file or directory. Any value passed in this parameter other than **CREATE_NEW** will be processed as **CREATE_ALWAYS**. |
| **CREATE_NEW**<br><br>1 | Create the destination file or directory only if it does not already exist. If it does exist, and this value is specified, this function will fail. |

### `dwAttributes` [in]

The file attributes of the destination file or directory. The **FILE_READ_ONLY** attribute is currently not processed by this function.

### `lpSecurityAttributes` [in, optional]

A pointer to a
[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure that specifies the security attributes of the destination file or directory, if it does not already exist. If you specify **NULL**, the file or directory gets a default security descriptor. The ACLs in the default security descriptor for a file or directory are inherited from its parent directory.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is a system error code. For a complete list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or the header file WinError.h.

## Remarks

Exclusive access to the destination file or directory is required by EFS for the call to this function. If this access is not provided, this function will fail.

The caller should have the EFS key for the source file or directory, and at least the **READ_ATTRIBUTE** ACL for the source file or directory.

The specified source and destination file or directories should reside on the same computer; otherwise, an error will be returned.

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

[File Encryption](https://learn.microsoft.com/windows/desktop/FileIO/file-encryption)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)