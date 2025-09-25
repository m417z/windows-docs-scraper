# VerInstallFileW function

## Description

Installs the specified file based on information returned from the [VerFindFile](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-verfindfilea) function. **VerInstallFile** decompresses the file, if necessary, assigns a unique filename, and checks for errors, such as outdated files.

## Parameters

### `uFlags` [in]

Type: **DWORD**

This parameter can be one of the following values. All other bits are reserved.

| Value | Meaning |
| --- | --- |
| **VIFF_FORCEINSTALL**<br><br>0x0001 | Installs the file regardless of mismatched version numbers. The function checks only for physical errors during installation. |
| **VIFF_DONTDELETEOLD**<br><br>0x0002 | Installs the file without deleting the previously installed file, if the previously installed file is not in the destination directory. |

### `szSrcFileName` [in]

Type: **LPCTSTR**

The name of the file to be installed. This is the filename in the directory pointed to by the
*szSrcDir* parameter; the filename can include only the filename and extension, not a path.

### `szDestFileName` [in]

Type: **LPCTSTR**

The name **VerInstallFile** will give the new file upon installation. This file name may be different from the filename in the
*szSrcFileName* directory. The new name should include only the file name and extension, not a path.

### `szSrcDir` [in]

Type: **LPCTSTR**

The name of the directory where the file can be found.

### `szDestDir` [in]

Type: **LPCTSTR**

The name of the directory where the file should be installed. [VerFindFile](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-verfindfilea) returns this value in its
*szDestDir* parameter.

### `szCurDir` [in]

Type: **LPCTSTR**

The name of the directory where a preexisting version of this file can be found. [VerFindFile](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-verfindfilea) returns this value in its
*szCurDir* parameter.

### `szTmpFile` [out]

Type: **LPTSTR**

The name of a temporary copy of the source file. The buffer should be at least **_MAX_PATH** characters long, although this is not required, and should be empty on input.

### `puTmpFileLen` [in, out]

Type: **PUINT**

The length of the
*szTmpFile* buffer. This pointer must not be **NULL**.

When the function returns,
*lpuTmpFileLen* receives the size, in characters, of the data returned in
*szTmpFile*, including the terminating null character. If the buffer is too small to contain all the data,
*lpuTmpFileLen* will be the size of the buffer required to hold the data.

## Return value

Type: **DWORD**

The return value is a bitmask that indicates exceptions. It can be one or more of the following values. All other values are reserved.

| Return code/value | Description |
| --- | --- |
| **VIF_ACCESSVIOLATION**<br><br>0x00000200L | A read, create, delete, or rename operation failed due to an access violation. |
| **VIF_BUFFTOOSMALL**<br><br>0x00040000L | The *szTmpFile* buffer was too small to contain the name of the temporary source file. When the function returns, *lpuTmpFileLen* contains the size of the buffer required to hold the filename. |
| **VIF_CANNOTCREATE**<br><br>0x00000800L | The function cannot create the temporary file. The specific error may be described by another flag. |
| **VIF_CANNOTDELETE**<br><br>0x00001000L | The function cannot delete the destination file, or cannot delete the existing version of the file located in another directory. If the **VIF_TEMPFILE** bit is set, the installation failed, and the destination file probably cannot be deleted. |
| **VIF_CANNOTDELETECUR**<br><br>0x00004000L | The existing version of the file could not be deleted and **VIFF_DONTDELETEOLD** was not specified. |
| **VIF_CANNOTLOADCABINET**<br><br>0x00100000L | The function cannot load the cabinet file. |
| **VIF_CANNOTLOADLZ32**<br><br>0x00080000L | The function cannot load the compressed file. |
| **VIF_CANNOTREADDST**<br><br>0x00020000L | The function cannot read the destination (existing) files. This prevents the function from examining the file's attributes. |
| **VIF_CANNOTREADSRC**<br><br>0x00010000L | The function cannot read the source file. This could mean that the path was not specified properly. |
| **VIF_CANNOTRENAME**<br><br>0x00002000L | The function cannot rename the temporary file, but already deleted the destination file. |
| **VIF_DIFFCODEPG**<br><br>0x00000010L | The new file requires a code page that cannot be displayed by the version of the system currently running. This error can be overridden by calling [VerInstallFile](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-verinstallfilea) with the **VIFF_FORCEINSTALL** flag set. |
| **VIF_DIFFLANG**<br><br>0x00000008L | The new and preexisting files have different language or code-page values. This error can be overridden by calling [VerInstallFile](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-verinstallfilea) again with the **VIFF_FORCEINSTALL** flag set. |
| **VIF_DIFFTYPE**<br><br>0x00000020L | The new file has a different type, subtype, or operating system from the preexisting file. This error can be overridden by calling [VerInstallFile](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-verinstallfilea) again with the **VIFF_FORCEINSTALL** flag set. |
| **VIF_FILEINUSE**<br><br>0x00000080L | The preexisting file is in use by the system and cannot be deleted. |
| **VIF_MISMATCH**<br><br>0x00000002L | The new and preexisting files differ in one or more attributes. This error can be overridden by calling [VerInstallFile](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-verinstallfilea) again with the **VIFF_FORCEINSTALL** flag set. |
| **VIF_OUTOFMEMORY**<br><br>0x00008000L | The function cannot complete the requested operation due to insufficient memory. Generally, this means the application ran out of memory attempting to expand a compressed file. |
| **VIF_OUTOFSPACE**<br><br>0x00000100L | The function cannot create the temporary file due to insufficient disk space on the destination drive. |
| **VIF_SHARINGVIOLATION**<br><br>0x00000400L | A read, create, delete, or rename operation failed due to a sharing violation. |
| **VIF_SRCOLD**<br><br>0x00000004L | The file to install is older than the preexisting file. This error can be overridden by calling [VerInstallFile](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-verinstallfilea) again with the **VIFF_FORCEINSTALL** flag set. |
| **VIF_TEMPFILE**<br><br>0x00000001L | The temporary copy of the new file is in the destination directory. The cause of failure is reflected in other flags. |
| **VIF_WRITEPROT**<br><br>0x00000040L | The preexisting file is write-protected. This error can be overridden by calling [VerInstallFile](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-verinstallfilea) again with the **VIFF_FORCEINSTALL** flag set. |

## Remarks

This function works on 16-, 32-, and 64-bit file images.

**VerInstallFile** copies the file from the source directory to the destination directory. If
*szCurDir* indicates that a previous version of the file exists on the system, **VerInstallFile** compares the files' version stamp information. If the previously installed version of the file is more recent than the new version, or if the files' attributes are significantly different, for example, if they are in different languages, then **VerInstallFile** returns with one or more recoverable error codes.

**VerInstallFile** leaves the temporary file in the destination directory. The application can either override the error or delete the temporary file. If the application overrides the error, **VerInstallFile** deletes the previously installed version and renames the temporary file with the original filename.

> [!NOTE]
> The winver.h header defines VerInstallFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

**Reference**

[VerFindFile](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-verfindfilea)

[Version Information](https://learn.microsoft.com/windows/desktop/menurc/version-information)