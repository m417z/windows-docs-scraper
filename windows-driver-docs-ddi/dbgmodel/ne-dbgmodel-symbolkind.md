# SymbolKind enumeration

## Description

Defines the kind of a symbol.

## Constants

### `Symbol`

Unspecified symbol type.

### `SymbolModule`

The symbol is a module and can be queried for [IDebugHostModule](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostmodule).

### `SymbolType`

The symbol is a type and can be queried for [IDebugHostType](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype).

### `SymbolField`

The symbol is a field (a data member within a structure or class) and can be queried for [IDebugHostField](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostfield).

### `SymbolConstant`

The symbol is a constant value and can be queried for [IDebugHostConstant](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostconstant).

### `SymbolData`

The symbol is data which is not a member of a structure or class and is queryable for [IDebugHostData](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostdata).

### `SymbolBaseClass`

The symbol is a base class and is queryable for [IDebugHostBaseClass](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostbaseclass).

### `SymbolPublic`

The symbol is an entry in a module's publics table (having no type information) and is queryable for [IDebugHostPublic](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostpublic).

### `SymbolFunction`

The symbol is a function and is queryable for [IDebugHostData](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostdata).

## Remarks

## See also

[Debugger Data Model C++ Overview](https://learn.microsoft.com/windows-hardware/drivers/debugger/data-model-cpp-overview)