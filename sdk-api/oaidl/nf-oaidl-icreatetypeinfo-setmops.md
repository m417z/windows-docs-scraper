# ICreateTypeInfo::SetMops

## Description

Sets the marshaling opcode string associated with the type description or the function.

## Parameters

### `index` [in]

The index of the member for which to set the opcode string. If index is –1, sets the opcode string for the type description.

### `bstrMops` [in]

The marshaling opcode string.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **E_ACCESSDENIED** | Cannot write to the destination. |
| **STG_E_INSUFFICIENTMEMORY** | Insufficient memory to complete the operation. |

## See also

[ICreateTypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypeinfo)