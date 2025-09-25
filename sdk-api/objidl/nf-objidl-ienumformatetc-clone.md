# IEnumFORMATETC::Clone

## Description

Creates a new enumerator that contains the same enumeration state as the current one.

This method makes it possible to record a particular point in the enumeration sequence and then return to that point at a later time. The caller must release this new enumerator separately from the first enumerator.

## Parameters

### `ppenum` [out]

Address of an [IEnumFORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumformatetc) pointer variable that receives the interface pointer to the enumeration object. If the method is unsuccessful, the value of this output variable is undefined.

## Return value

This method returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | An unexpected error has occurred. |
| **E_INVALIDARG** | The specified enumerator is invalid. |
| **E_OUTOFMEMORY** | Insufficient memory available for this operation. |

## See also

[IEnumFORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumformatetc)