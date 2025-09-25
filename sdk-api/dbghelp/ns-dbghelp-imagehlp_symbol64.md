# IMAGEHLP_SYMBOL64 structure

## Description

Contains symbol information.

## Members

### `SizeOfStruct`

The size of the structure, in bytes. The caller must set this member to `sizeof(IMAGEHLP_SYMBOL64)`.

### `Address`

The virtual address for the symbol.

### `Size`

The size of the symbol, in bytes. This value is a best guess and can be zero.

### `Flags`

This member is reserved for use by the operating system.

### `MaxNameLength`

The maximum length of the string that the **Name** member can contain, in characters, not including the null-terminating character. Because symbol names can vary in length, this data structure is allocated by the caller. This member is used so the library knows how much memory is available for use by the symbol name.

### `Name`

The decorated or undecorated symbol name. If the buffer is not large enough for the complete name, it is truncated to **MaxNameLength** characters, including the null-terminating character.

## Remarks

This structure supersedes the **IMAGEHLP_SYMBOL** structure. For more information, see
[Updated Platform Support](https://learn.microsoft.com/windows/desktop/Debug/updated-platform-support). **IMAGEHLP_SYMBOL** is defined as follows in DbgHelp.h.

```cpp
#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
 #define IMAGEHLP_SYMBOL IMAGEHLP_SYMBOL64
 #define PIMAGEHLP_SYMBOL PIMAGEHLP_SYMBOL64
#else
 typedef struct _IMAGEHLP_SYMBOL {
     DWORD SizeOfStruct;
     DWORD Address;
     DWORD Size;
     DWORD Flags;
     DWORD MaxNameLength;
     CHAR  Name[1];
 } IMAGEHLP_SYMBOL, *PIMAGEHLP_SYMBOL;
#endif
```

## See also

[SymGetSymFromAddr64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetsymfromaddr)

[SymGetSymFromName64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetsymfromname)