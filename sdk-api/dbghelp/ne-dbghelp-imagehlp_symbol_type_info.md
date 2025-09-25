# IMAGEHLP_SYMBOL_TYPE_INFO enumeration

## Description

Identifies the type of symbol information to be retrieved.

## Constants

### `TI_GET_SYMTAG`

The symbol tag.

The data type is **DWORD***.

### `TI_GET_SYMNAME`

The symbol name.

The data type is **WCHAR****. The caller must free the buffer.

### `TI_GET_LENGTH`

The length of the type.

The data type is **ULONG64***.

### `TI_GET_TYPE`

The type.

The data type is **DWORD***.

### `TI_GET_TYPEID`

The type index.

The data type is **DWORD***.

### `TI_GET_BASETYPE`

The base type for the type index.

The data type is **DWORD***.

### `TI_GET_ARRAYINDEXTYPEID`

The type index for index of an array type.

The data type is **DWORD***.

### `TI_FINDCHILDREN`

The type index of all children.

The data type is a pointer to a
[TI_FINDCHILDREN_PARAMS](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-ti_findchildren_params) structure.

- The **Count** member should be initialized with the number of children.
- The **Start** member should also be initialized. In most cases, to zero.

### `TI_GET_DATAKIND`

The data kind.

The data type is **DWORD***.

### `TI_GET_ADDRESSOFFSET`

The address offset.

The data type is **DWORD***.

### `TI_GET_OFFSET`

The offset of the type in the parent. Members can use this to get their offset in a structure.

The data type is **DWORD***.

### `TI_GET_VALUE`

The value of a constant or enumeration value.

The data type is **VARIANT***.

### `TI_GET_COUNT`

The count of array elements.

The data type is **DWORD***.

### `TI_GET_CHILDRENCOUNT`

The number of children.

The data type is **DWORD***.

### `TI_GET_BITPOSITION`

The bit position of a bitfield.

The data type is **DWORD***.

### `TI_GET_VIRTUALBASECLASS`

A value that indicates whether the base class is virtually inherited.

The data type is **BOOL**.

### `TI_GET_VIRTUALTABLESHAPEID`

The symbol interface of the type of virtual table, for a user-defined type.

### `TI_GET_VIRTUALBASEPOINTEROFFSET`

The offset of the virtual base pointer.

The data type is **DWORD***.

### `TI_GET_CLASSPARENTID`

The type index of the class parent.

The data type is **DWORD***.

### `TI_GET_NESTED`

A value that indicates whether the type index is nested.

The data type is **DWORD***.

### `TI_GET_SYMINDEX`

The symbol index for a type.

The data type is **DWORD***.

### `TI_GET_LEXICALPARENT`

The lexical parent of the type.

The data type is **DWORD***.

### `TI_GET_ADDRESS`

The index address.

The data type is **ULONG64***.

### `TI_GET_THISADJUST`

The offset from the **this** pointer to its actual value.

The data type is **DWORD***.

### `TI_GET_UDTKIND`

The UDT kind.

The data type is **DWORD***.

### `TI_IS_EQUIV_TO`

The equivalency of two types.

The data type is **DWORD***. The value is S_OK is the two types are equivalent, and S_FALSE otherwise.

### `TI_GET_CALLING_CONVENTION`

The calling convention.

The data type is **DWORD**. The following are the valid values:

### `TI_IS_CLOSE_EQUIV_TO`

The equivalency of two symbols. This is not guaranteed to be accurate.

The data type is **DWORD***. The value is S_OK is the two types are equivalent, and S_FALSE otherwise.

### `TI_GTIEX_REQS_VALID`

The element where the valid request bitfield should be stored.

The data type is **ULONG64***.

This value is only used with the [SymGetTypeInfoEx](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgettypeinfoex) function.

### `TI_GET_VIRTUALBASEOFFSET`

The offset in the virtual function table of a virtual function.

The data type is **DWORD**.

### `TI_GET_VIRTUALBASEDISPINDEX`

The index into the virtual base displacement table.

The data type is **DWORD**.

### `TI_GET_IS_REFERENCE`

Indicates whether a pointer type is a reference.

The data type is **Boolean**.

### `TI_GET_INDIRECTVIRTUALBASECLASS`

Indicates whether the user-defined data type is an indirect virtual base.

The data type is **BOOL**.

**DbgHelp 6.6 and earlier:** This value is not supported.

### `TI_GET_VIRTUALBASETABLETYPE`

### `IMAGEHLP_SYMBOL_TYPE_INFO_MAX`

## See also

[SymGetTypeInfo](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgettypeinfo)

[SymGetTypeInfoEx](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgettypeinfoex)