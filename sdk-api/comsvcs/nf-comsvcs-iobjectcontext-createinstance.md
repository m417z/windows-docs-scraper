# IObjectContext::CreateInstance

## Description

Creates an object using current object's context.

## Parameters

### `rclsid` [in]

The CLSID of the type of object to instantiate.

### `riid` [in]

Any interface that's implemented by the object you want to instantiate.

### `ppv` [out]

A reference to the requested interface on the new object. If instantiation fails, this parameter is set to **NULL**.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **REGDB_E_CLASSNOTREG** | The component specified by clsid is not registered as a COM component. |
| **E_OUTOFMEMORY** | There's not enough memory available to instantiate the object. |
| **E_INVALIDARG** | The argument passed in the *ppvObj* parameter is invalid. |
| **E_UNEXPECTED** | An unexpected error occurred. This can happen if one object passes its [IObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjectcontext) pointer to another object and the other object calls [CreateInstance](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iobjectcontext-createinstance) using this pointer. An **IObjectContext** pointer is not valid outside the context of the object that originally obtained it. |

## Remarks

**CreateInstance** creates a COM object. However, the object will have context only if its component is registered with COM+.

When you create an object by using **CreateInstance**, the new object's context is derived from the current object's [IObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjectcontext) and the declarative properties of the new object's component. The new object always executes within the same activity as the object that created it. If the current object has a transaction, the transaction attribute of the new object's component determines whether the new object executes within the scope of that transaction.

If the component's transaction attribute setting either requires a transaction or supports transactions, the new object inherits its creator's transaction. If the component's transaction attribute requires a new transaction, COM+ initiates a new transaction for the new object. If the component's transaction attribute does not support transactions, the new object doesn't execute under any transaction.

**CreateInstance** always returns the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface on the newly instantiated object. You should immediately cast the returned value to the interface through which you want to communicate with the new object. The interface ID you pass in the *riid* parameter does not need to be the same interface as the one to which you cast the returned value, but it must be an interface that is implemented by the object you are instantiating.

## See also

[IObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjectcontext)