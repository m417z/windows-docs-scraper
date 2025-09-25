# IDebugHostSymbol2::EnumerateChildrenEx

## Description

Enumerates all child symbols of the given type, name, and extended information which is present.

This behaves identically to EnumerateChildren when searchInfo is nullptr. SymbolType::Symbol
can be used to search to search for any kind of child. Note that if name is nullptr, children of any name will be produced by the resulting enumerator.

## Parameters

### `kind`

Indicates what kinds of child symbols the caller wishes to enumerate. If the flat value Symbol is passed, all kinds of child symbols will be enumerated.

### `name`

If specified, only child symbols with a name as given in this argument will be enumerated.

### `searchInfo`

A pointer to a [SymbolSearchInfo structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/ns-dbgmodel-symbolsearchinfo) which describes attributes of how the symbol search should proceed. The caller should ensure that the HeaderSize and InfoSize fields of the SymbolSearchInfo are filled out appropriately prior to passing the structure to this method. For searches involving types, a TypeSearchInfo structure follows.

### `ppEnum`

An enumerator which enumerates child symbols of the specified kind and name will be returned here.

## Return value

This method returns HRESULT which indicate success or failure.

## Remarks

## See also

[SymbolSearchInfo structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/ns-dbgmodel-symbolsearchinfo)

[IDebugHostSymbol2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostsymbol2)