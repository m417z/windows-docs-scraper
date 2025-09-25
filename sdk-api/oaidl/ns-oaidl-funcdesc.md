# FUNCDESC structure

## Description

Describes a function.

## Members

### `memid`

The function member ID.

### `lprgscode`

The status code.

### `lprgelemdescParam`

Description of the element.

### `funckind`

Indicates the type of function (virtual, static, or dispatch-only).

### `invkind`

The invocation type. Indicates whether this is a property function, and if so, which type.

### `callconv`

The calling convention.

### `cParams`

The total number of parameters.

### `cParamsOpt`

The number of optional parameters.

### `oVft`

For FUNC_VIRTUAL, specifies the offset in the VTBL.

### `cScodes`

The number of possible return values.

### `elemdescFunc`

The function return type.

### `wFuncFlags`

The function flags. See [FUNCFLAGS](https://learn.microsoft.com/windows/desktop/api/oaidl/ne-oaidl-funcflags).

## Remarks

The **cParams** field specifies the total number of required and optional parameters.

The **cParamsOpt** field specifies the form of optional parameters accepted by the function, as follows:

* A value of 0 specifies that no optional arguments are supported.
* A value of –1 specifies that the method's last parameter is a pointer to a safe array of variants. Any number of variant arguments greater than **cParams** –1 must be packaged by the caller into a safe array and passed as the final parameter. This array of optional parameters must be freed by the caller after control is returned from the call.
* Any other number indicates that the last n parameters of the function are variants and do not need to be specified by the caller explicitly. The parameters left unspecified should be filled in by the compiler or interpreter as variants of type VT_ERROR with the value DISP_E_PARAMNOTFOUND.