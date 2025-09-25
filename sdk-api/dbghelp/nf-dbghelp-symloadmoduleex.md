# SymLoadModuleEx function

## Description

Loads the symbol table for the specified module.

## Parameters

### `hProcess` [in]

A handle to the process that was originally passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `hFile` [in]

A handle to the file for the executable image. This argument is used mostly by debuggers, where the debugger passes the file handle obtained from a debugging event. A value of **NULL** indicates that *hFile* is not used.

### `ImageName` [in]

The name of the executable image. This name can contain a partial path, a full path, or no path at all. If the file cannot be located by the name provided, the symbol search path is used.

### `ModuleName` [in]

A shortcut name for the module. If the pointer value is **NULL**, the library creates a name using the base name of the symbol file.

### `BaseOfDll` [in]

The load address of the module. If the value is zero, the library obtains the load address from the symbol file. The load address contained in the symbol file is not necessarily the actual load address. Debuggers and other applications having an actual load address should use the real load address when calling this function.

If the image is a .pdb file, this parameter cannot be zero.

### `DllSize` [in]

The size of the module, in bytes. If the value is zero, the library obtains the size from the symbol file. The size contained in the symbol file is not necessarily the actual size. Debuggers and other applications having an actual size should use the real size when calling this function.

If the image is a .pdb file, this parameter cannot be zero.

### `Data` [in]

A pointer to a
[MODLOAD_DATA](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-modload_data) structure that represents headers other than the standard PE header. This parameter is optional and can be **NULL**.

### `Flags` [in]

This parameter can be zero or one or more of the following values. If this parameter is zero, the function loads the modules and the symbols for the module.

| Value | Meaning |
| --- | --- |
| **SLMFLAG_NO_SYMBOLS**<br><br>0x4 | Loads the module but not the symbols for the module. |
| **SLMFLAG_VIRTUAL**<br><br>0x1 | Creates a virtual module named *ModuleName* at the address specified in *BaseOfDll*. To add symbols to this module, call the [SymAddSymbol](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symaddsymbol) function. |

## Return value

If the function succeeds, the return value is the base address of the loaded module.

If the function fails, the return value is zero. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If the module is already loaded, the return value is zero and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_SUCCESS.

## Remarks

The symbol handler creates an entry for the module and if the deferred symbol loading option is turned off, an attempt is made to load the symbols. If deferred symbol loading is enabled, the module is marked as deferred and the symbols are not loaded until a reference is made to a symbol in the module. Therefore, you should always call the [SymGetModuleInfo64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetmoduleinfo64) function after calling **SymLoadModuleEx**.

To unload the symbol table, use the
[SymUnloadModule64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symunloadmodule64) function.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define DBGHELP_TRANSLATE_TCHAR.

#### Examples

For an example, see
[Loading a Symbol Module](https://learn.microsoft.com/windows/desktop/Debug/loading-a-symbol-module).

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[MODLOAD_DATA](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-modload_data)

[SymAddSymbol](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symaddsymbol)

[SymUnloadModule64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symunloadmodule)