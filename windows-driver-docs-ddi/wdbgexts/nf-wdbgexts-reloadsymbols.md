# ReloadSymbols function

## Description

The **ReloadSymbols** function deletes symbol information from the debugger so that it can be reloaded as needed. This function behaves the same way as the debugger command [.reload](https://learn.microsoft.com/windows-hardware/drivers/debugger/-reload--reload-module-).

## Parameters

### `Arg`

Optional -

Specifies the arguments for the debugger command **.reload**. For example, setting *Arg* to **/u ntdll.dll** has the same effect as the command **.reload /u ntdll.dll**.

## See also

[.reload (Reload Module)](https://learn.microsoft.com/windows-hardware/drivers/debugger/-reload--reload-module-)