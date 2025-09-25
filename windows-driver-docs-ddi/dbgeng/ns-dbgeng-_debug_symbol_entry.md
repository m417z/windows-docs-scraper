# _DEBUG_SYMBOL_ENTRY structure

## Description

The DEBUG_SYMBOL_ENTRY structure describes a symbol in a symbol group.

## Members

### `ModuleBase`

The base address of the module in the target's virtual address space.

### `Offset`

The location of the symbol in the target's virtual address space.

### `Id`

The symbol ID of the symbol. If the symbol ID is not known, **Id** is DEBUG_INVALID_OFFSET.

### `Arg64`

The interpretation of **Arg64** depends on the type of the symbol. If the value is not known, **Arg64** is zero.

### `Size`

The size, in bytes, of the symbol's value. This might not be known or might not completely represent all of the data for a symbol. For example, a function's code might be split among multiple regions and the size only describes one region.

### `Flags`

Symbol entry flags. Currently, no flags are defined.

### `TypeId`

The type ID of the symbol.

### `NameSize`

The size, in characters, of the symbol's name. If the size is not known, **NameSize** is zero.

### `Token`

The managed token of the symbol. If the token value is not known or the symbol does not have a token, **Token** is zero.

### `Tag`

The symbol tag for the type of the symbol. This is a value from the **SymTagEnum** enumeration.

### `Arg32`

The interpretation of **Arg32** depends on the type of the symbol. Currently, the value of **Arg32** is the register that holds the value or a pointer to the value of the symbol. If the symbol is not held in a register, or the register is not known, **Arg32** is zero.

### `Reserved`

Set to zero.

## See also

[IdebugSymbolGroup2::GetSymbolEntryInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbolgroup2-getsymbolentryinformation)

[IdebugSymbols3::GetSymbolEntryInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getsymbolentryinformation)