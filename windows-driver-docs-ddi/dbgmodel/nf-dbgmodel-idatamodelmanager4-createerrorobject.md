## Description

The CreateErrorObject method creates an "error object". The data model does not have the notion of exceptions and exception flow. Failure comes out of a property/method in two ways:

- A single failing HRESULT with no extended error information. Either there is no more information which can be given for the error or the error itself is self-explanatory from the returned HRESULT.

- A single failing HRESULT coupled with extended error information. The extended error information is an error object returned in the output argument of the property/method.

## Parameters

### `hrError`

The error code for which the extended error information is being created. If a given function is the entity creating an error object for a failure, this code must match the failing HRESULT returned by the function.

### `pwszMessage`

An optional message giving a deeper indication of what failed and why. This message will be the display string conversion of the created error object.

### `object`

The newly constructed/boxed error object will be returned here.

## Return value

This method returns HRESULT.

## Remarks

**Sample Code**

```cpp
ComPtr<IDataModelManager4> spManager; /* get the data model manager */

ComPtr<IModelObject> spError;
if (SUCCEEDED(spManager->CreateErrorObject(
    E_INVALIDARG,
    L"Calls to the Sum() method must pass at least one argument",
    &spError)))
{
    // You can pass this back in places where you see
    // _COM_Errorptr_ annotated.  Methods, for instance, may return
    // E_INVALIDARG and an error object to channel out additional information.
    // Property accessor GetValue implementations can also do this.
    // Indexers can do this.
}
```
## See also

[IDataModelManager4 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelmanager4)