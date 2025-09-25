# IEnumSTATPROPSETSTG::Clone

## Description

The **Clone** method creates an enumerator that contains the same enumeration state as the current [STATPROPSETSTG](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-statpropsetstg) structure enumerator. Using this method, a client can record a particular point in the enumeration sequence and then return to that point later. The new enumerator supports the same [IEnumSTATPROPSETSTG](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ienumstatpropsetstg) interface.

## Parameters

### `ppenum` [out]

 A pointer to the variable that receives the [IEnumSTATPROPSETSTG](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ienumstatpropsetstg) interface pointer.

If the method does not succeed, the value of the *ppenum* parameter is undefined.

## Return value

This method supports return values listed in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The *ppenum* parameter is **NULL**. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_UNEXPECTED** | An unexpected exception occurred. |