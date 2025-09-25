# BindProperty(get_lambda, set_lambda) function

## Description

 A binder which converts two lambdas to a read/write property accessor. The lambdas must hold reference on outer objects they
reference through a by value capture.

Usage: BindProperty(get_lambda, set_lambda)

## Parameters

### `getFunctor`

A functor of signature (PCWSTR, [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) *, [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) **) which will act as the getter for the newly created property accessor.

### `setFunctor`

A functor of signature (PCWSTR, [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) *, [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) *) which will act as the setter for the newly created property accessor.

## Return value

This function returns Microsoft::WRL::ComPtr<[IModelPropertyAccessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelpropertyaccessor)>.

## Remarks

This sample code shows usage.

```cpp
// Define a native type that we wish to project into the data model
struct MyNativeType
{
    std::wstring Name;
    int Id;
    int WriteableValue;
};

// Declare a type factory for the type
class MyNativeTypeFactory : public TypedInstanceModel<MyNativeType>
{
public:
    MyNativeTypeFactory()
    {
        BindReadOnlyProperty(L"Name", &MyNativeType::Name);
        BindReadOnlyProperty(L"Id", &MyNativeType::Id);
        BindProperty(L"WriteableValue", &MyNativeType::WriteableValue);
    }
};

// Create the type factory and make an instance
MyNativeTypeFactory factory;
Object instance = factory.CreateInstance(MyNativeType { L"Foo", 42, 37 });

// There are "Name/Id" read-only properties on instance and a "WriteableValue" property.
```

## See also

[Debugger Data Model C++ Overview](https://learn.microsoft.com/windows-hardware/drivers/debugger/data-model-cpp-overview)