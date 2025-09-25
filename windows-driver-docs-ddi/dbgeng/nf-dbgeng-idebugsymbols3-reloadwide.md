# IDebugSymbols3::ReloadWide

## Description

The **ReloadWide** method deletes the engine's symbol information for the specified module and reload these symbols as needed.

## Parameters

### `Module` [in]

Specifies the module to reload.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful |

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

This method behaves the same way as the debugger command **.reload**. The *Module* parameter is treated the same way as the arguments to **.reload**. For example, setting the *Module* parameter to "/u ntdll.dll" has the same effect as the command **.reload /u ntdll.dll**.

For more information about symbols, see [Symbols](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbols4).

## See also

[.reload (Reload Module)](https://learn.microsoft.com/windows-hardware/drivers/debugger/-reload--reload-module-)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)