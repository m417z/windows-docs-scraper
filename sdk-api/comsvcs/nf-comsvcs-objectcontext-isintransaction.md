# ObjectContext::IsInTransaction

## Description

Indicates whether the current object is executing in a transaction.

## Parameters

### `pbIsInTx` [out]

**TRUE** if the current object is executing within a transaction; **FALSE** otherwise.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_UNEXPECTED** | An unexpected error has occurred. This can happen if one object passes its [ObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-objectcontext) pointer to another object and the other object calls [IsInTransaction](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-objectcontext-isintransaction) using this pointer. An **ObjectContext** pointer is not valid outside the context of the object that originally obtained it. |

## Remarks

You can use this method to ensure that an object that requires a transaction never runs without one. For example, if a component that requires a transaction is improperly configured in the Component Services administration tool, you can use this method to determine that the object does not have a transaction. Then you can return an error to alert the user to the problem, or take whatever action is appropriate.

## See also

[ObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-objectcontext)