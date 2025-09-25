# SymUnDName64 function

## Description

Undecorates a decorated C++ symbol name.

Applications can also use the [UnDecorateSymbolName](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-undecoratesymbolname) function.

## Parameters

### `sym` [in]

A pointer to an
[IMAGEHLP_SYMBOL64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_symbol) structure that specifies the symbol to be undecorated.

### `UnDecName` [out]

A pointer to a buffer that receives the undecorated name.

### `UnDecNameLength` [in]

The size of the *UnDecName* buffer, in characters.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

This function supersedes the **SymUnDName** function. For more information, see
[Updated Platform Support](https://learn.microsoft.com/windows/desktop/Debug/updated-platform-support). **SymUnDName** is defined as follows in Dbghelp.h.

```cpp
#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define SymUnDName SymUnDName64
#else
BOOL
IMAGEAPI
SymUnDName(
    __in PIMAGEHLP_SYMBOL sym,
    __out_ecount(UnDecNameLength) PSTR UnDecName,
    __in DWORD UnDecNameLength
    );
#endif
```

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[UnDecorateSymbolName](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-undecoratesymbolname)