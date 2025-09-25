# IMAGEHLP_LINE structure

## Description

Represents a source file line.

## Members

### `SizeOfStruct`

The size of the structure, in bytes. The caller must set this member to `sizeof(IMAGEHLP_LINE64)`.

### `Key`

This member is reserved for use by the operating system.

### `LineNumber`

The line number in the file.

### `FileName`

The name of the file, including the full path.

### `Address`

The address of the first instruction in the line.

## Remarks

This structure supersedes the **IMAGEHLP_LINE** structure. For more information, see
[Updated Platform Support](https://learn.microsoft.com/windows/desktop/Debug/updated-platform-support). **IMAGEHLP_LINE** is defined as follows in DbgHelp.h.

```cpp
#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define IMAGEHLP_LINE IMAGEHLP_LINE64
#define PIMAGEHLP_LINE PIMAGEHLP_LINE64
#else
typedef struct _IMAGEHLP_LINE {
    DWORD    SizeOfStruct;
    PVOID    Key;
    DWORD    LineNumber;
    PCHAR    FileName;
    DWORD    Address;
} IMAGEHLP_LINE, *PIMAGEHLP_LINE;

typedef struct _IMAGEHLP_LINEW {
    DWORD    SizeOfStruct;
    PVOID    Key;
    DWORD    LineNumber;
    PCHAR    FileName;
    DWORD64  Address;
} IMAGEHLP_LINEW, *PIMAGEHLP_LINEW;
#endif
```

## See also

[SymGetLineFromAddr64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetlinefromaddr)

[SymGetLineFromName64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetlinefromname)

[SymGetLineNext64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetlinenext)

[SymGetLinePrev64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetlineprev)