# ICreateTypeInfo2::DeleteFuncDesc

## Description

Deletes a function description specified by the index number.

## Parameters

### `index` [in]

The index of the function whose description is to be deleted. The index should be in the range of 0 to 1 less than the number of functions in this type.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## See also

[ICreateTypeInfo2](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypeinfo2)