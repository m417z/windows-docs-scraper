# IEnumSTATSTG::Clone

## Description

The **Clone** method creates a new enumerator that contains the same enumeration state as the current [STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg) structure enumerator. Using this method, a client can record a particular point in the enumeration sequence and then return to that point at a later time. The new enumerator supports the same [IEnumSTATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstatstg) interface.

## Parameters

### `ppenum` [out]

 A pointer to the variable that receives the [IEnumSTATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstatstg) interface pointer.

If the method is unsuccessful, the value of the *ppenum* parameter is undefined.

## Return value

This method supports the following return values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The *ppenum* parameter is **NULL**. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_UNEXPECTED** | An unexpected exception occurred. |