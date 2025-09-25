# ICreateTypeInfo2::SetVarHelpStringContext

## Description

Sets a Help context value for a specified variable.

## Parameters

### `index` [in]

The index of the variable.

### `dwHelpStringContext` [in]

The Help string context for a localized string.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## See also

[ICreateTypeInfo2](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypeinfo2)