# _DEBUG_MODULE_PARAMETERS structure

## Description

The DEBUG_MODULE_PARAMETERS structure contains most of the parameters for describing a module.

## Members

### `Base`

The location in the target's virtual address space of the module's base. If the value of **Base** is DEBUG_INVALID_OFFSET, the structure is invalid.

### `Size`

The size, in bytes, of the memory range that is occupied by the module.

### `TimeDateStamp`

The date and time stamp of the module's executable file. This is the number of seconds elapsed since midnight (00:00:00), January 1, 1970 Coordinated Universal Time (UTC) as stored in the image file header.

### `Checksum`

The checksum of the image. This value can be zero.

### `Flags`

A bit-set that contains the module's flags. The bit-flags that can be present are as follows.

| Value | Description |
| --- | --- |
| DEBUG_MODULE_UNLOADED | The module was unloaded. |
| DEBUG_MODULE_USER_MODE | The module is a user-mode module. |
| DEBUG_MODULE_SYM_BAD_CHECKSUM | The checksum in the symbol file did not match the checksum for the module image. |

### `SymbolType`

The type of symbols that are loaded for the module. This member can have one of the following values.

| Value | Description |
| --- | --- |
| DEBUG_SYMTYPE_NONE | No symbols are loaded. |
| DEBUG_SYMTYPE_COFF | The symbols are in common object file format (COFF). |
| DEBUG_SYMTYPE_CODEVIEW | The symbols are in Microsoft CodeView format. |
| DEBUG_SYMTYPE_PDB | Symbols in PDB format have been loaded through the pre-Debug Interface Access (DIA) interface. |
| DEBUG_SYMTYPE_EXPORT | No actual symbol files were found; symbol information was extracted from the binary file's export table. |
| DEBUG_SYMTYPE_DEFERRED | The module was loaded, but the engine has deferred its loading of the symbols. |
| DEBUG_SYMTYPE_SYM | Symbols in SYM format have been loaded. |
| DEBUG_SYMTYPE_DIA | Symbols in PDB format have been loaded through the DIA interface. |

### `ImageNameSize`

The size of the file name for the module. The size is measured in characters, including the terminator.

### `ModuleNameSize`

The size of the module name of the module. The size is measured in characters, including the terminator.

### `LoadedImageNameSize`

The size of the loaded image name for the module. The size is measured in characters, including the terminator.

### `SymbolFileNameSize`

The size of the symbol file name for the module. The size is measured in characters, including the terminator.

### `MappedImageNameSize`

The size of the mapped image name of the module. The size is measured in characters, including the terminator.

### `Reserved`

Reserved for system use.

## Remarks

This structure is returned by [GetModuleParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getmoduleparameters).

To locate the different names for the module, use [GetModuleNameString](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getmodulenamestring).

For more information about modules, see [Modules](https://learn.microsoft.com/windows-hardware/drivers/debugger/modules). For details about the different names for the module, see [GetModuleNameString](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getmodulenamestring).