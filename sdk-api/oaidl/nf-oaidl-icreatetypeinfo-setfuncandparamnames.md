# ICreateTypeInfo::SetFuncAndParamNames

## Description

Sets the name of a function and the names of its parameters to the specified names.

## Parameters

### `index` [in]

The index of the function whose function name and parameter names are to be set.

### `rgszNames` [in]

An array of pointers to names. The first element is the function name. Subsequent elements are names of parameters.

### `cNames` [in]

The number of elements in the *rgszNames* array.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **E_ACCESSDENIED** | Cannot write to the destination. |
| **STG_E_INSUFFICIENTMEMORY** | Insufficient memory to complete the operation. |
| **TYPE_E_ELEMENTNOTFOUND** | The element cannot be found. |

## Remarks

This method must be used once for each property. The last parameter for put and putref accessor functions is unnamed.

## See also

[ICreateTypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypeinfo)