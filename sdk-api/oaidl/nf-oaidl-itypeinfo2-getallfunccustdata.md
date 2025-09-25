# ITypeInfo2::GetAllFuncCustData

## Description

Gets all custom data from the specified function.

## Parameters

### `index` [in]

The index of the function for which to get the custom data.

### `pCustData` [out]

The custom data items.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

After the call, the caller needs to release memory used to hold the custom data item by calling [ClearCustData](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-clearcustdata).

## See also

[ITypeInfo2](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo2)