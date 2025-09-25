# MsiGetFileHashW function

## Description

The
**MsiGetFileHash** function takes the path to a file and returns a 128-bit hash of that file. Authoring tools may use
**MsiGetFileHash** to obtain the file hash needed to populate the
[MsiFileHash table](https://learn.microsoft.com/windows/desktop/Msi/msifilehash-table).

Windows Installer uses file hashing as a means to detect and eliminate unnecessary file copying. A file hash stored in the MsiFileHash table may be compared to a hash of an existing file on the user's computer.

## Parameters

### `szFilePath` [in]

Path to file that is to be hashed.

### `dwOptions` [in]

The value in this column must be 0. This parameter is reserved for future use.

### `pHash` [out]

Pointer to the returned file hash information.

## Return value

| Value | Meaning |
| --- | --- |
| **ERROR_SUCCESS** | The function completed successfully. |
| **ERROR_FILE_NOT_FOUND** | The file does not exist. |
| **ERROR_ACCESS_DENIED** | The file could not be opened to get version information. |
| **E_FAIL** | Unexpected error has occurred. |

## Remarks

The entire 128-bit file hash is returned as four 32-bit fields. The numbering of the four fields is zero-based. The values returned by
**MsiGetFileHash** correspond to the four fields of the
[MSIFILEHASHINFO](https://learn.microsoft.com/windows/desktop/api/msi/ns-msi-msifilehashinfo) structure. The first field corresponds to the HashPart1 column of the MsiFileHash table, the second field corresponds to the HashPart2 column, the third field corresponds to the HashPart3 column, and the fourth field corresponds to the HashPart4 column.

The hash information entered into the MsiFileHash table must be obtained by calling
**MsiGetFileHash** or the
[FileHash](https://learn.microsoft.com/windows/desktop/Msi/installer-filehash) method. Do not attempt to use other methods to generate the file hash.

> [!NOTE]
> The msi.h header defines MsiGetFileHash as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Default File Versioning](https://learn.microsoft.com/windows/desktop/Msi/default-file-versioning)

[MSIFILEHASHINFO](https://learn.microsoft.com/windows/desktop/api/msi/ns-msi-msifilehashinfo)

[MsiFileHash table](https://learn.microsoft.com/windows/desktop/Msi/msifilehash-table)