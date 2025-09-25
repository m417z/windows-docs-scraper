# _DEBUG_SYMBOL_SOURCE_ENTRY structure

## Description

The DEBUG_SYMBOL_SOURCE_ENTRY structure describes a section of the source code and a corresponding region of the target's memory.

## Members

### `ModuleBase`

The base address, in the target's virtual address space, of the module that the source symbol came from.

### `Offset`

The location of the memory corresponding to the source code in the target's virtual address space.

### `FileNameId`

Identifier for the source code file name. If this information is not available, **FieldNameId** is set to zero.

### `EngineInternal`

Reserved for internal debugger engine use.

### `Size`

The size of the region of memory corresponding to the source code. If this information is not available, **Size** is set to one.

### `Flags`

Set to zero.

### `FileNameSize`

The number of characters in the source filename, including the terminator.

### `StartLine`

The line number of the start of the region of source code in the file. The number of the first line in the file is one. If this information is not available, **StartLine** is set to DEBUG_ANY_ID.

### `EndLine`

The line number of the end of the region of source code in the file. The number of the first line in the file is one. If this information is not available, **StartLine** is set to DEBUG_ANY_ID.

### `StartColumn`

The column number of the start of the region of source code. The number of the first column is one. If this information is not available, **StartLine** is set to DEBUG_ANY_ID.

### `EndColumn`

The column number of the end of the region of source code. The number of the first column is one. If this information is not available, **StartLine** is set to DEBUG_ANY_ID.

### `Reserved`

Reserved for future use.