# SYMBOL_INFO structure

## Description

Contains symbol information.

## Members

### `SizeOfStruct`

The size of the structure, in bytes. This member must be set to `sizeof(SYMBOL_INFO)`. Note that the total size of the data is the `SizeOfStruct + (MaxNameLen - 1) * sizeof(TCHAR)`. The reason to subtract one is that the first character in the name is accounted for in the size of the structure.

### `TypeIndex`

A unique value that identifies the type data that describes the symbol. This value does not persist between sessions.

### `Reserved`

This member is reserved for system use.

### `Index`

The unique value for the symbol. The value associated with a symbol is not guaranteed to be the same each time you run the process.

For PDB symbols, the index value for a symbol is not generated until the symbol is enumerated or retrieved through a search by name or address. The index values for all CodeView and COFF symbols are generated when the symbols are loaded.

### `Size`

The symbol size, in bytes (or bits, if the symbol is a bitfield member).

This value is meaningful only if the module symbols are from a pdb file; otherwise, this value is typically zero and should be ignored.

### `ModBase`

The base address of the module that contains the symbol.

### `Flags`

This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **SYMFLAG_CLR_TOKEN**<br><br>0x00040000 | The symbol is a CLR token. |
| **SYMFLAG_CONSTANT**<br><br>0x00000100 | The symbol is a constant. |
| **SYMFLAG_EXPORT**<br><br>0x00000200 | The symbol is from the export table. |
| **SYMFLAG_FORWARDER**<br><br>0x00000400 | The symbol is a forwarder. |
| **SYMFLAG_FRAMEREL**<br><br>0x00000020 | Offsets are frame relative. |
| **SYMFLAG_FUNCTION**<br><br>0x00000800 | The symbol is a known function. |
| **SYMFLAG_ILREL**<br><br>0x00010000 | The symbol address is an offset relative to the beginning of the intermediate language block. This applies to managed code only. |
| **SYMFLAG_LOCAL**<br><br>0x00000080 | The symbol is a local variable. |
| **SYMFLAG_METADATA**<br><br>0x00020000 | The symbol is managed metadata. |
| **SYMFLAG_PARAMETER**<br><br>0x00000040 | The symbol is a parameter. |
| **SYMFLAG_REGISTER**<br><br>0x00000008 | The symbol is a register. The **Register** member is used. |
| **SYMFLAG_REGREL**<br><br>0x00000010 | Offsets are register relative. |
| **SYMFLAG_SLOT**<br><br>0x00008000 | The symbol is a managed code slot. |
| **SYMFLAG_THUNK**<br><br>0x00002000 | The symbol is a thunk. |
| **SYMFLAG_TLSREL**<br><br>0x00004000 | The symbol is an offset into the TLS data area. |
| **SYMFLAG_VALUEPRESENT**<br><br>0x00000001 | The **Value** member is used. |
| **SYMFLAG_VIRTUAL**<br><br>0x00001000 | The symbol is a virtual symbol created by the [SymAddSymbol](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symaddsymbol) function. |

### `Value`

The value of a constant.

### `Address`

The virtual address of the start of the symbol.

### `Register`

The register.

### `Scope`

The DIA scope. For more information, see the *Debug Interface Access SDK* in the Visual Studio documentation. (This resource may not be available in some languages

and countries.)

### `Tag`

The PDB classification. These values are defined in Dbghelp.h in the [SymTagEnum](https://learn.microsoft.com/previous-versions/visualstudio/visual-studio-2010/bkedss5f(v=vs.100)) enumeration type.

### `NameLen`

The length of the name, in characters, not including the null-terminating character.

### `MaxNameLen`

The size of the **Name** buffer, in characters. If this member is 0, the **Name** member is not used.

### `Name`

The name of the symbol. The name can be undecorated if the SYMOPT_UNDNAME option is used with the
[SymSetOptions](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsetoptions) function.

## See also

[SymEnumSymbolsProc](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-psym_enumeratesymbols_callback)

[SymFromAddr](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symfromaddr)

[SymFromName](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symfromname)

[SymGetTypeFromName](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgettypefromname)