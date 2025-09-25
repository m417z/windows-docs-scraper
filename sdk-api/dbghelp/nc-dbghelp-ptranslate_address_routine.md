# PTRANSLATE_ADDRESS_ROUTINE callback function

## Description

An application-defined callback function used with the
[StackWalk64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-stackwalk) function. It provides address translation for 16-bit addresses.

The **PTRANSLATE_ADDRESS_ROUTINE64** type defines a pointer to this callback function.
**TranslateAddressProc64** is a placeholder for the application-defined function name.

## Parameters

### `hProcess` [in]

A handle to the process for which the stack trace is generated.

### `hThread` [in]

A handle to the thread for which the stack trace is generated.

### `lpaddr` [in]

An address to be translated.

## Return value

The function returns the translated address.

## Remarks

This callback function supersedes the *PTRANSLATE_ADDRESS_ROUTINE* callback function. *PTRANSLATE_ADDRESS_ROUTINE* is defined as follows in Dbghelp.h.

```cpp
#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define PTRANSLATE_ADDRESS_ROUTINE PTRANSLATE_ADDRESS_ROUTINE64
#else
typedef
DWORD
(__stdcall *PTRANSLATE_ADDRESS_ROUTINE)(
    __in HANDLE hProcess,
    __in HANDLE hThread,
    __out LPADDRESS lpaddr
    );
#endif
```

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[StackWalk64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-stackwalk)