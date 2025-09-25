# VerFindFileW function

## Description

Determines where to install a file based on whether it locates another version of the file in the system. The values **VerFindFile** returns in the specified buffers are used in a subsequent call to the [VerInstallFile](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-verinstallfilea) function.

## Parameters

### `uFlags` [in]

Type: **DWORD**

This parameter can be the following value. All other bits are reserved.

| Value | Meaning |
| --- | --- |
| **VFFF_ISSHAREDFILE**<br><br>0x0001 | The source file can be shared by multiple applications. An application can use this information to determine where the file should be copied. |

### `szFileName` [in]

Type: **LPCTSTR**

The name of the file to be installed. Include only the file name and extension, not a path.

### `szWinDir` [in, optional]

Type: **LPCTSTR**

The directory in which Windows is running or will be run. This string is returned by the [GetWindowsDirectory](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getwindowsdirectorya) function.

### `szAppDir` [in]

Type: **LPCTSTR**

The directory where the installation program is installing a set of related files. If the installation program is installing an application, this is the directory where the application will reside. This parameter also points to the application's current directory unless otherwise specified.

### `szCurDir` [out]

Type: **LPWSTR**

A buffer that receives the path to a current version of the file being installed. The path is a zero-terminated string. If a current version is not installed, the buffer will contain a zero-length string. The buffer should be at least **_MAX_PATH** characters long, although this is not required.

### `puCurDirLen` [in, out]

Type: **PUINT**

The length of the
*szCurDir* buffer. This pointer must not be **NULL**.

When the function returns,
*lpuCurDirLen* contains the size, in characters, of the data returned in
*szCurDir*, including the terminating null character. If the buffer is too small to contain all the data,
*lpuCurDirLen* will be the size of the buffer required to hold the path.

### `szDestDir` [out]

Type: **LPTSTR**

A buffer that receives the path to the installation location recommended by **VerFindFile**. The path is a zero-terminated string. The buffer should be at least **_MAX_PATH** characters long, although this is not required.

### `puDestDirLen` [in, out]

Type: **PUINT**

A pointer to a variable that specifies the length of the
*szDestDir* buffer. This pointer must not be **NULL**.

When the function returns,
*lpuDestDirLen* contains the size, in characters, of the data returned in
*szDestDir*, including the terminating null character. If the buffer is too small to contain all the data,
*lpuDestDirLen* will be the size of the buffer needed to hold the path.

## Return value

Type: **DWORD**

The return value is a bitmask that indicates the status of the file. It can be one or more of the following values. All other values are reserved.

| Return code/value | Description |
| --- | --- |
| **VFF_CURNEDEST**<br><br>0x0001 | The currently installed version of the file is not in the recommended destination. |
| **VFF_FILEINUSE**<br><br>0x0002 | The system is using the currently installed version of the file; therefore, the file cannot be overwritten or deleted. |
| **VFF_BUFFTOOSMALL**<br><br>0x0004 | At least one of the buffers was too small to contain the corresponding string. An application should check the output buffers to determine which buffer was too small. |

## Remarks

This function works on 16-, 32-, and 64-bit file images.

**VerFindFile** searches for a copy of the specified file by using the [OpenFile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openfile) function. However, it determines the system directory from the specified Windows directory, or searches the path.

If the
*dwFlags* parameter indicates that the file is private to this application (not **VFFF_ISSHAREDFILE**), **VerFindFile** recommends installing the file in the application's directory. Otherwise, if the system is running a shared copy of the system, the function recommends installing the file in the Windows directory. If the system is running a private copy of the system, the function recommends installing the file in the system directory.

> [!NOTE]
> The winver.h header defines VerFindFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[GetWindowsDirectory](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getwindowsdirectorya)

[OpenFile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openfile)

**Other Resources**

**Reference**

[VerInstallFile](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-verinstallfilea)

[Version Information](https://learn.microsoft.com/windows/desktop/menurc/version-information)