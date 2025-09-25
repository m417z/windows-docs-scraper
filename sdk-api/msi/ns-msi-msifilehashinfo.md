# MSIFILEHASHINFO structure

## Description

The
**MSIFILEHASHINFO** structure contains the file hash information returned by
[MsiGetFileHash](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msigetfilehasha) and used in the
[MsiFileHash table](https://learn.microsoft.com/windows/desktop/Msi/msifilehash-table).

## Members

### `dwFileHashInfoSize`

Specifies the size, in bytes, of this data structure. Set this member to `sizeof(MSIFILEHASHINFO)` before calling the
[MsiGetFileHash](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msigetfilehasha) function.

### `dwData`

The entire 128-bit file hash is contained in four 32-bit fields. The first field corresponds to the HashPart1 column of the MsiHashFile table, the second field corresponds to the HashPart2 column, the third field corresponds to the HashPart3 column, and the fourth field corresponds to the HashPart4 column.

## Remarks

The file hash entered into the fields of the MsiFileHash table must be obtained by calling
[MsiGetFileHash](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msigetfilehasha) or the
[FileHash method](https://learn.microsoft.com/windows/desktop/Msi/installer-filehash). Do not use other methods to generate a file hash.

## See also

[Default File Versioning](https://learn.microsoft.com/windows/desktop/Msi/default-file-versioning)

[MsiFileHash table](https://learn.microsoft.com/windows/desktop/Msi/msifilehash-table)

[MsiGetFileHash](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msigetfilehasha)