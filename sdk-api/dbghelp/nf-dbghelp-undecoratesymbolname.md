# UnDecorateSymbolName function

## Description

Undecorates the specified decorated C++ symbol name.

## Parameters

### `name` [in]

The decorated C++ symbol name. This name can be identified by the first character of the name, which is
always a question mark (?).

### `outputString` [out]

A pointer to a string buffer that receives the undecorated name.

### `maxStringLength` [in]

The size of the *UnDecoratedName* buffer, in characters.

### `flags` [in]

The options for how the decorated name is undecorated. This parameter can be zero or more of the following
values.

| Value | Meaning |
| --- | --- |
| **UNDNAME_32_BIT_DECODE**<br><br>0x0800 | Undecorate 32-bit decorated names. |
| **UNDNAME_COMPLETE**<br><br>0x0000 | Enable full undecoration. |
| **UNDNAME_NAME_ONLY**<br><br>0x1000 | Undecorate only the name for primary declaration. Returns [scope::]name. Does expand template parameters. |
| **UNDNAME_NO_ACCESS_SPECIFIERS**<br><br>0x0080 | Disable expansion of access specifiers for members. |
| **UNDNAME_NO_ALLOCATION_LANGUAGE**<br><br>0x0010 | Disable expansion of the declaration language specifier. |
| **UNDNAME_NO_ALLOCATION_MODEL**<br><br>0x0008 | Disable expansion of the declaration model. |
| **UNDNAME_NO_ARGUMENTS**<br><br>0x2000 | Do not undecorate function arguments. |
| **UNDNAME_NO_CV_THISTYPE**<br><br>0x0040 | Disable expansion of CodeView modifiers on the **this** type for primary declaration. |
| **UNDNAME_NO_FUNCTION_RETURNS**<br><br>0x0004 | Disable expansion of return types for primary declarations. |
| **UNDNAME_NO_LEADING_UNDERSCORES**<br><br>0x0001 | Remove leading underscores from Microsoft keywords. |
| **UNDNAME_NO_MEMBER_TYPE**<br><br>0x0200 | Disable expansion of the static or virtual attribute of members. |
| **UNDNAME_NO_MS_KEYWORDS**<br><br>0x0002 | Disable expansion of Microsoft keywords. |
| **UNDNAME_NO_MS_THISTYPE**<br><br>0x0020 | Disable expansion of Microsoft keywords on the **this** type for primary declaration. |
| **UNDNAME_NO_RETURN_UDT_MODEL**<br><br>0x0400 | Disable expansion of the Microsoft model for user-defined type returns. |
| **UNDNAME_NO_SPECIAL_SYMS**<br><br>0x4000 | Do not undecorate special names, such as vtable, vcall, vector, metatype, and so on. |
| **UNDNAME_NO_THISTYPE**<br><br>0x0060 | Disable all modifiers on the **this** type. |
| **UNDNAME_NO_THROW_SIGNATURES**<br><br>0x0100 | Disable expansion of throw-signatures for functions and pointers to functions. |

## Return value

If the function succeeds, the return value is the number of characters in the
*UnDecoratedName* buffer, not including the NULL terminator.

If the function fails, the return value is zero. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If the function fails and returns zero, the content of the *UnDecoratedName* buffer
is undetermined.

## Remarks

To use undecorated symbols, call the [SymSetOptions](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsetoptions)
function with the **SYMOPT_UNDNAME** option.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to
this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize
all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define **DBGHELP_TRANSLATE_TCHAR**.

#### Examples

For an example, see
[Retrieving Undecorated Symbol Names](https://learn.microsoft.com/windows/desktop/Debug/retrieving-undecorated-symbol-names).

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[SymSetOptions](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsetoptions)