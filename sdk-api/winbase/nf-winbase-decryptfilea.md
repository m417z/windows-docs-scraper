# DecryptFileA function

## Description

Decrypts an encrypted file or directory.

## Parameters

### `lpFileName` [in]

The name of the file or directory to be decrypted.

The caller must have the **FILE_READ_DATA**, **FILE_WRITE_DATA**, **FILE_READ_ATTRIBUTES**, **FILE_WRITE_ATTRIBUTES**, and **SYNCHRONIZE** access rights. For more information, see
[File Security and Access Rights](https://learn.microsoft.com/windows/desktop/FileIO/file-security-and-access-rights).

### `dwReserved`

Reserved; must be zero.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**DecryptFile** function requires exclusive access to the file being decrypted, and will fail if another process is using the file. If the file is not encrypted,
**DecryptFile** simply returns a nonzero value, which indicates success.

If *lpFileName* specifies a read-only file, the function fails and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_FILE_READ_ONLY**. If *lpFileName* specifies a directory that contains a read-only file, the functions succeeds but the directory is not decrypted.

In Windows 8, Windows Server 2012, and later, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | No |
| Resilient File System (ReFS) | No |

SMB 3.0 does not support EFS on shares with continuous availability capability.

> [!NOTE]
> The winbase.h header defines DecryptFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[EncryptFile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-encryptfilea)

[File Encryption](https://learn.microsoft.com/windows/desktop/FileIO/file-encryption)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)