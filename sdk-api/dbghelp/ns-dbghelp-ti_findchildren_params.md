# TI_FINDCHILDREN_PARAMS structure

## Description

Contains type index information. It is used by the
[SymGetTypeInfo](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgettypeinfo) function.

## Members

### `Count`

The number of children.

### `Start`

The zero-based index of the child from which the child indexes are to be retrieved. For example, in an array with five elements, if Start is two, this indicates the third array element. In most cases, this member is zero.

### `ChildId`

An array of type indexes. There is one index per child.

## See also

[SymGetTypeInfo](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgettypeinfo)