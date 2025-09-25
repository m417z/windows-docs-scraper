# VarArgsKind enumeration

## Description

Defines the style of variable arguments that a function definition takes.

## Constants

### `VarArgsNone`

The function does not take any variable arguments.

### `VarArgsCStyle`

The function is a C-style varargs function (returnType(arg1, arg2, ...)). The number of arguments reported by the function does not include the ellipsis argument. Any variable argument passing occurs after the number of arguments returned by the GetFunctionParameterTypeCount method.

## Remarks

## See also

[Debugger Data Model C++ Overview](https://learn.microsoft.com/windows-hardware/drivers/debugger/data-model-cpp-overview)