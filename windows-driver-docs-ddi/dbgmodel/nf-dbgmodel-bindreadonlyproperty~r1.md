# BindReadOnlyProperty(get_lambda) function

## Description

A binder which converts one instance method on a class to a read-only property accessor. The class must be IUnknown derived.

The returned binder will hold reference on the class object.

A binder which converts one lambda to a read-only property accessor. The lambda must hold reference on outer objects through a by value capture.

Usage: BindReadOnlyProperty(get_lambda)

## Parameters

### `getFunctor`

A functor of signature (PCWSTR, [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) *, [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) **) which will act as the getter for the newly created read-only property accessor.

## Return value

This function returns Microsoft::WRL::ComPtr<[IModelPropertyAccessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelpropertyaccessor)>.

## Remarks

## See also