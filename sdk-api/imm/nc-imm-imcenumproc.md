## Description

An application-defined callback function that processes input contexts provided by the [ImmEnumInputContext](https://learn.microsoft.com/windows/desktop/api/imm/nf-imm-immenuminputcontext) function. The IMCENUMPROC type defines a pointer to this callback function. **EnumInputContext** is a placeholder for the application-defined function name.

## Parameters

### `unnamedParam1`

Handle to the input context.

### `unnamedParam2`

Application-supplied data.

## Return value

Returns a nonzero value to continue enumeration, or 0 to stop enumeration.

## Remarks

An application must register this function by passing its address to the [ImmEnumInputContext](https://learn.microsoft.com/windows/desktop/api/imm/nf-imm-immenuminputcontext) function.

## See also

[ImmEnumInputContext](https://learn.microsoft.com/windows/desktop/api/imm/nf-imm-immenuminputcontext)

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)