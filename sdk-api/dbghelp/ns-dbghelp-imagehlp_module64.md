## Description

Contains module information.

## Members

### `SizeOfStruct`

The size of the structure, in bytes. The caller must set this member to `sizeof(IMAGEHLP_MODULE64)`.

### `BaseOfImage`

The base virtual address where the image is loaded.

### `ImageSize`

The size of the image, in bytes.

### `TimeDateStamp`

The date and timestamp value. The value is represented in the number of seconds elapsed since midnight (00:00:00), January 1, 1970, Universal Coordinated Time, according to the system clock. The timestamp can be printed using the C run-time (CRT) function **ctime**.

### `CheckSum`

The checksum of the image. This value can be zero.

### `NumSyms`

The number of symbols in the symbol table. The value of this parameter is not meaningful when **SymPdb** is specified as the value of the *SymType* parameter.

### `SymType`

The type of symbols that are loaded. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SymCoff** | COFF symbols. |
| **SymCv** | CodeView symbols. |
| **SymDeferred** | Symbol loading deferred. |
| **SymDia** | DIA symbols. |
| **SymExport** | Symbols generated from a DLL export table. |
| **SymNone** | No symbols are loaded. |
| **SymPdb** | PDB symbols. |
| **SymSym** | .sym file. |
| **SymVirtual** | The virtual module created by [SymLoadModuleEx](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symloadmoduleex) with **SLMFLAG_VIRTUAL**. |

### `ModuleName`

The module name.

### `ImageName`

The image name. The name may or may not contain a full path.

### `LoadedImageName`

The full path and file name of the file from which symbols were loaded.

### `LoadedPdbName`

The full path and file name of the .pdb file.

### `CVSig`

The signature of the CV record in the debug directories.

### `CVData`

The contents of the CV record.

### `PdbSig`

The PDB signature.

### `PdbSig70`

The PDB signature (Visual C/C++ 7.0 and later)

### `PdbAge`

The DBI age of PDB.

### `PdbUnmatched`

A value that indicates whether the loaded PDB is unmatched.

### `DbgUnmatched`

A value that indicates whether the loaded DBG is unmatched.

### `LineNumbers`

A value that indicates whether line number information is available.

### `GlobalSymbols`

A value that indicates whether symbol information is available.

### `TypeInfo`

A value that indicates whether type information is available.

### `SourceIndexed`

A value that indicates whether the .pdb supports the source server.

**DbgHelp 6.1 and earlier:** This member is not supported.

### `Publics`

A value that indicates whether the module contains public symbols.

**DbgHelp 6.1 and earlier:** This member is not supported.

### `MachineType`

TBD

### `Reserved`

TBD

## Remarks

This structure supersedes the **IMAGEHLP_MODULE** structure. For more information, see
[Updated Platform Support](https://learn.microsoft.com/windows/desktop/Debug/updated-platform-support). **IMAGEHLP_MODULE** is defined as follows in DbgHelp.h.

```cpp
#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define IMAGEHLP_MODULE IMAGEHLP_MODULE64
#define PIMAGEHLP_MODULE PIMAGEHLP_MODULE64
#define IMAGEHLP_MODULEW IMAGEHLP_MODULEW64
#define PIMAGEHLP_MODULEW PIMAGEHLP_MODULEW64
#else
typedef struct _IMAGEHLP_MODULE {
    DWORD    SizeOfStruct;
    DWORD    BaseOfImage;
    DWORD    ImageSize;
    DWORD    TimeDateStamp;
    DWORD    CheckSum;
    DWORD    NumSyms;
    SYM_TYPE SymType;
    CHAR     ModuleName[32];
    CHAR     ImageName[256];
    CHAR     LoadedImageName[256];
} IMAGEHLP_MODULE, *PIMAGEHLP_MODULE;

typedef struct _IMAGEHLP_MODULEW {
    DWORD    SizeOfStruct;
    DWORD    BaseOfImage;
    DWORD    ImageSize;
    DWORD    TimeDateStamp;
    DWORD    CheckSum;
    DWORD    NumSyms;
    SYM_TYPE SymType;
    WCHAR    ModuleName[32];
    WCHAR    ImageName[256];
    WCHAR    LoadedImageName[256];
} IMAGEHLP_MODULEW, *PIMAGEHLP_MODULEW;
#endif
```

## See also

[SymGetModuleInfo64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetmoduleinfo)