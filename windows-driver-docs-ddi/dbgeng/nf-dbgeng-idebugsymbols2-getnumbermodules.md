# IDebugSymbols2::GetNumberModules

## Description

The **GetNumberModules** method returns the number of [modules](https://learn.microsoft.com/windows-hardware/drivers/debugger/modules) in the current process's module list.

## Parameters

### `Loaded` [out]

Receives the number of loaded modules in the current process's module list.

### `Unloaded` [out]

Receives the number of unloaded modules in the current process's module list. This number will be zero if the version of Microsoft Windows running on the target computer does not track unloaded modules.

## Return value

This method may also return other error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The list of loaded and unloaded modules is maintained by Windows. The engine caches a copy of this list, but it may become out of date. [Reload](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-reload) can be used to synchronize the engine's copy of the list with the list maintained by Windows.

The unloaded modules are not tracked in all versions of Windows. Unloaded modules are tracked for user-mode targets in Microsoft Windows Server 2003 and later; for kernel-mode targets, the unloaded modules are tracked in earlier Windows versions as well. When they are tracked they are indexed after the loaded modules. Unloaded modules can be used to analyze failures caused by an attempt to call unloaded code.

For more information about modules, see [Modules](https://learn.microsoft.com/windows-hardware/drivers/debugger/modules).

## See also

[GetModuleByIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getmodulebyindex)

[IDebugSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols)

[IDebugSymbols2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols2)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)