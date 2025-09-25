## Description

The FindTypeByName2 method finds a type by name within the module. If an enclosing symbol is given, the type is looked for by name within that enclosing symbol; otherwise, the type is looked for globally.

## Parameters

### `pEnclosingSymbol`

Optional parameter. If provided, the method looks for the type within this enclosing symbol.

### `typeName`

The name of the type to search for.

### `type`

Pointer to where the found IDebugHostType object will be stored.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

## See also

[IDebugHostModule4 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostmodule4)