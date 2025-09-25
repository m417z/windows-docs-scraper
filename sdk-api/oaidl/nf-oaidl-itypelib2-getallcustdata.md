# ITypeLib2::GetAllCustData

## Description

Gets all custom data items for the library.

## Parameters

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

[ITypeLib2](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypelib2)