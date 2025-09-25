# SymbolSearchInfo structure

## Description

This structure describes, the search record passed to EnumerateChildrenEx in order to restrict symbol searches.

A given kind of symbol (as indicated by the SymbolKind enumeration) searched may have its own derived type.

## Members

### `HeaderSize`

sizeof(SymbolSearchInfo)

### `InfoSize`

sizeof(* by SymbolKind *)

### `SearchOptions`

What follows is per SymbolKind.

## Remarks

## See also

[Debugger Data Model C++ Overview](https://learn.microsoft.com/windows-hardware/drivers/debugger/data-model-cpp-overview)