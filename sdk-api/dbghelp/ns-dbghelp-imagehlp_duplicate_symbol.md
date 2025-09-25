# IMAGEHLP_DUPLICATE_SYMBOL structure

## Description

Contains duplicate symbol information.

## Members

### `SizeOfStruct`

The size of the structure, in bytes. The caller must set this member to `sizeof(IMAGEHLP_DUPLICATE_SYMBOL64)`.

### `NumberOfDups`

The number of duplicate symbols.

### `Symbol`

A pointer to an array of symbols (
[IMAGEHLP_SYMBOL64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_symbol) structures). The number of entries in the array is specified by the **NumberOfDups** member.

### `SelectedSymbol`

The index into the symbol array for the selected symbol.

## Remarks

This structure supersedes the **IMAGEHLP_DUPLICATE_SYMBOL** structure. For more information, see
[Updated Platform Support](https://learn.microsoft.com/windows/desktop/Debug/updated-platform-support). **IMAGEHLP_DUPLICATE_SYMBOL** is defined as follows in DbgHelp.h.

```cpp
#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define IMAGEHLP_DUPLICATE_SYMBOL IMAGEHLP_DUPLICATE_SYMBOL64
#define PIMAGEHLP_DUPLICATE_SYMBOL PIMAGEHLP_DUPLICATE_SYMBOL64
#else
typedef struct _IMAGEHLP_DUPLICATE_SYMBOL {
    DWORD            SizeOfStruct;
    DWORD            NumberOfDups;
    PIMAGEHLP_SYMBOL Symbol;
    DWORD            SelectedSymbol;
} IMAGEHLP_DUPLICATE_SYMBOL, *PIMAGEHLP_DUPLICATE_SYMBOL;
#endif
```

## See also

[IMAGEHLP_SYMBOL64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_symbol)

[SymRegisterCallbackProc64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-psymbol_registered_callback)