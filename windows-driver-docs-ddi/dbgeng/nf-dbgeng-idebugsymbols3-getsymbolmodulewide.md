# IDebugSymbols3::GetSymbolModuleWide

## Description

The **GetSymbolModuleWide** method returns the base address of module which contains the specified symbol.

## Parameters

### `Symbol` [in]

Specifies the name of the symbol to look up. See the Remarks section for details of the syntax of this name.

### `Base` [out]

Receives the location in the target's memory address space of the base of the module. For more information, see [Modules](https://learn.microsoft.com/windows-hardware/drivers/debugger/modules).

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOINTERFACE** | The symbol or module could not be found. |

## Remarks

The string *Symbol* must contain an exclamation point ( **!** ). If *Symbol* is a module-qualified symbol name (for example, **mymodules!main**) or if the module name is omitted (for example, **!main**), the engine will search for this symbol and return the module in which it is found. If *Symbol* contains just a module name (for example, **mymodule!**) the engine returns the first module with this module name.

For more information about symbols, see [Symbols](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbols4).