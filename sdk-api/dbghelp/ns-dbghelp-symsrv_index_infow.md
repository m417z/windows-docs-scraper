# SYMSRV_INDEX_INFOW structure

## Description

Contains symbol server index information.

## Members

### `sizeofstruct`

The size of the structure, in bytes. This member must be set to `sizeof(SYMSRV_INDEX_INFO)` or `sizeof(SYMSRV_INDEX_INFOW)`.

### `file`

The name of the .pdb, .dbg, or image file.

### `stripped`

A value that indicates whether the image file is stripped.

### `timestamp`

The timestamp from the PE header. This member is used only for image files.

### `size`

The file size from the PE header. This member is used only for image files.

### `dbgfile`

If the image file is stripped and there is a .dbg file, this member is the path to the .dbg file from the CV record.

### `pdbfile`

The .pdb file from the CV record. This member is used only for image and .dbg files.

### `guid`

The GUID of the .pdb file. If there is no GUID available, the signature of the .pdb file is copied into first **DWORD** of the GUID.

### `sig`

The signature of the .pdb file (for use with old-style .pdb files). This value can be 0 if it is a new-style .pdb file that uses a GUID-length signature.

### `age`

The age of the .pdb file.

## See also

[SymSrvGetFileIndexInfo](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsrvgetfileindexinfo)

## Remarks

> [!NOTE]
> The dbghelp.h header defines SYMSRV_INDEX_INFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).