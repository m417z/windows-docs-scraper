# ICreateTypeLib::SaveAllChanges

## Description

Saves the [ICreateTypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypelib) instance following the layout of type information.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **STG_E_INSUFFICIENTMEMORY** | Insufficient memory to complete the operation. |
| **TYPE_E_IOERROR** | The function cannot write to the file. |
| **TYPE_E_INVALIDSTATE** | The state of the type library is not valid for this operation. |

## Remarks

You should not call any other [ICreateTypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypelib) methods after calling **SaveAllChanges**.

## See also

[ICreateTypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypelib)