# PENUMLOADED_MODULES_CALLBACK callback function

## Description

An application-defined callback function used with the
[EnumerateLoadedModules64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-enumerateloadedmodules) function.

The **PENUMLOADED_MODULES_CALLBACK64** and **PENUMLOADED_MODULES_CALLBACKW64** types define a pointer to this callback function.
*EnumerateLoadedModulesProc64* is a placeholder for the application-defined function name.

## Parameters

### `ModuleName` [in]

The name of the enumerated module.

### `ModuleBase` [in]

The base address of the module. Note that it is possible for this address to become invalid (for example, the module may be unloaded). Use exception handling when accessing the address or passing the address to another function to prevent an access violation from occurring.

### `ModuleSize` [in]

The size of the module, in bytes.

### `UserContext` [in, optional]

Optional user-defined data. This value is passed from
[EnumerateLoadedModules64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-enumerateloadedmodules).

## Return value

To continue enumeration, the callback function must return **TRUE**.

To stop enumeration, the callback function must return **FALSE**.

## Remarks

This callback function supersedes the *PENUMLOADED_MODULES_CALLBACK* callback function. *PENUMLOADED_MODULES_CALLBACK* is defined as follows in DbgHelp.h.

```cpp
#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define PENUMLOADED_MODULES_CALLBACK PENUMLOADED_MODULES_CALLBACK64
#else
typedef BOOL (CALLBACK *PENUMLOADED_MODULES_CALLBACK)(
    __in PCSTR ModuleName,
    __in ULONG ModuleBase,
    __in ULONG ModuleSize,
    __in_opt PVOID UserContext
    );
#endif
```

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[EnumerateLoadedModules64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-enumerateloadedmodules)