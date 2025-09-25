# BindReadOnlyProperty(this, &MyClass::GetMyProperty, &MyClass::SetMyProperty) function (dbgmodel.h)

## Description

A binder which converts an instance methods on a class to a read only property accessor. The class must be IUnknown derived.
The returned binder will hold reference on the class object.

Usage: BindReadOnlyProperty(this, &MyClass::GetMyProperty, &MyClass::SetMyProperty)

## Parameters

### `classObject`

The instance of a given class to which the newly created read-only property accessor will be bound.

### `getMethod`

A pointer-to-member function pointer of signature (PCWSTR, [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) *, [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)**) which will act as the getter for the newly created read-only property accessor.

## Return value

This function returns Microsoft::WRL::ComPtr<[IModelPropertyAccessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelpropertyaccessor)>.

## Remarks

## See also