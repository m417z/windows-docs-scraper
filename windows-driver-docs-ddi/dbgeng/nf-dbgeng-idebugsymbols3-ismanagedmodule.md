# IDebugSymbols3::IsManagedModule

## Description

Checks whether the engine is using managed
debugging support when it retrieves information
for a module.

## Parameters

### `Index` [in]

The index of a module.

### `Base` [in]

The base of the module.

## Return value

**IDebugSymbols3::IsManagedModule** returns a value of **S_OK** if the engine is using managed
debugging support when it retrieves information
for a module.

## Remarks

It can be expensive to run this check.

## See also

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)