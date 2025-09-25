# IEnumSTATPROPSTG::Clone

## Description

The **Clone** method creates an enumerator that contains the same enumeration state as the current [STATPROPSTG](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-statpropstg) structure enumerator. Using this method, a client can record a particular point in the enumeration sequence and then return to that point later. The new enumerator supports the same [IEnumSTATPROPSTG](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ienumstatpropstg) interface.

## Parameters

### `ppenum` [out]

 A pointer to the variable that receives the [IEnumSTATPROPSTG](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ienumstatpropstg) interface pointer.

If the method is unsuccessful, the value of the *ppenum* parameter is undefined.

## Return value

This method supports the following return values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The *ppenum* parameter is **NULL**. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_UNEXPECTED** | An unexpected exception occurred. |