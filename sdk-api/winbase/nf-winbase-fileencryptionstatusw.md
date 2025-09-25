# FileEncryptionStatusW function

## Description

Retrieves the encryption status of the specified file.

## Parameters

### `lpFileName` [in]

The name of the file.

### `lpStatus` [out]

A pointer to a variable that receives the encryption status of the file. This parameter can be one of the
following values.

| Value | Meaning |
| --- | --- |
| **FILE_ENCRYPTABLE**<br><br>0 | The file can be encrypted.<br><br>**Home, Home Premium, Starter, and ARM Editions of Windows:** **FILE_ENCRYPTABLE** may be returned but EFS does not support encrypting files on these editions of Windows. |
| **FILE_IS_ENCRYPTED**<br><br>1 | The file is encrypted. |
| **FILE_READ_ONLY**<br><br>8 | The file is a read-only file. |
| **FILE_ROOT_DIR**<br><br>3 | The file is a root directory. Root directories cannot be encrypted. |
| **FILE_SYSTEM_ATTR**<br><br>2 | The file is a system file. System files cannot be encrypted. |
| **FILE_SYSTEM_DIR**<br><br>4 | The file is a system directory. System directories cannot be encrypted. |
| **FILE_SYSTEM_NOT_SUPPORT**<br><br>6 | The file system does not support file encryption. |
| **FILE_UNKNOWN**<br><br>5 | The encryption status is unknown. The file may be encrypted. |
| **FILE_USER_DISALLOWED**<br><br>7 | Reserved for future use. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | No |
| Resilient File System (ReFS) | No |

SMB 3.0 does not support EFS on shares with continuous availability capability.

> [!NOTE]
> The winbase.h header defines FileEncryptionStatus as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[EncryptFile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-encryptfilea)

[File Encryption](https://learn.microsoft.com/windows/desktop/FileIO/file-encryption)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)