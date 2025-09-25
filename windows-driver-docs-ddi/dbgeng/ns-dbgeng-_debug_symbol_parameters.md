# _DEBUG_SYMBOL_PARAMETERS structure

## Description

The **DEBUG_SYMBOL_PARAMETERS** structure describes a symbol in a symbol group.

## Members

### `Module`

The location in the target's virtual address space of the base of the module to which the symbol belongs.

### `TypeId`

The type ID of the symbol.

### `ParentSymbol`

The index within the symbol group of the symbol's parent symbol. If the parent symbol is not known, **ParentSymbol** is DEBUG_ANY_ID.

### `SubElements`

The number of children of the symbol. If this symbol has never been expanded within this symbol group, this number will be an estimate that is based on the symbol's type.

### `Flags`

The symbol flags. See [DEBUG_SYMBOL_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-symbol-xxx) for details.

### `Reserved`

Set to zero.