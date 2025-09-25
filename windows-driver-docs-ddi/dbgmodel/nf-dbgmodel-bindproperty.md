# BindProperty function(this, &MyClass::GetMyProperty, &MyClass::SetMyProperty) (dbgmodel.h)

## Description

 A binder which converts two instance methods on a class to a read/write property accessor. The class must be IUnknown derived.
The returned binder will hold reference on the class object.

 Usage: BindProperty(this, &MyClass::GetMyProperty, &MyClass::SetMyProperty)

## Parameters

### `classObject`

The instance of a given class to which the newly created property accessor will be bound.

### `getMethod`

A pointer-to-member function pointer of signature (PCWSTR, [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) *, [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)**) which will act as the getter for the newly created property accessor.

### `setMethod`

A pointer-to-member function of signature (PCWSTR, [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) *, [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) *) which will act as the setter for the newly created property accessor.

## Return value

This function returns Microsoft::WRL::ComPtr<[IModelPropertyAccessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelpropertyaccessor)>.

## Remarks

This sample code shows usage of the BindProperty function.

> [!NOTE]
>The code sample uses the recommended DbgModelClientEx.h library header available from GitHub. For more information, see [Using the DbgModelClientEx Library](https://learn.microsoft.com/windows-hardware/drivers/debugger/data-model-cpp-overview#-using-the-dbgmodelclientex-library).
>
> To see how the DbgModelClientEx library are used, for example, specifying the Debugger::DataModel namespaces, review the Data Model HelloWorld C++ sample:
> https://github.com/microsoft/WinDbg-Samples/tree/master/DataModelHelloWorld/Cpp

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