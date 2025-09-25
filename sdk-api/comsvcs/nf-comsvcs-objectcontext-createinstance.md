# ObjectContext::CreateInstance

## Description

Creates an object using current object's context.

The object will have context only if its component is registered with COM+.

## Parameters

### `bstrProgID` [in]

The ProgID of the type of object to be instantiated.

### `pObject` [out]

A reference to the new object.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_UNEXPECTED** | An unexpected error occurred. This can happen if one object passes its [ObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-objectcontext) pointer to another object and the other object calls [CreateInstance](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-objectcontext-createinstance) using this pointer. An **ObjectContext** pointer is not valid outside the context of the object that originally obtained it. |

## Remarks

When you create an object by using **CreateInstance**, the new object's context is derived from the current object's [ObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-objectcontext) and the declarative properties of the new object's component. The new object always executes within the same activity as the object that created it. If the current object has a transaction, the transaction attribute of the new object's component determines whether the new object executes within the scope of that transaction.

If the component's transaction attribute setting either requires a transaction or supports transactions, the new object inherits its creator's transaction. If the component's transaction attribute requires a new transaction, COM+ initiates a new transaction for the new object. If the component's transaction attribute does not support transactions, the new object does not execute under any transaction.

## See also

[ObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-objectcontext)