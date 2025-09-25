# IDebugSymbols3::GetModuleByIndex

## Description

The **GetModuleByIndex** method returns the location of the module with the specified index.

## Parameters

### `Index` [in]

Specifies the index of the module whose location is requested.

### `Base` [out]

Receives the location in the target's memory address space of the module.

## Return value

This method may also return other error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The specified module was not loaded, and information about the module was not available. |

## Remarks

For more information about modules, see [Modules](https://learn.microsoft.com/windows-hardware/drivers/debugger/modules).