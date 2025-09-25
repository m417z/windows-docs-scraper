## Description

The CreateNoValue method creates a "no value" object, boxes it into an [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject), and returns it. The returned model object has a kind of ObjectNoValue.

A "no value" object has several semantic meanings:

- (Depending on language), it can be considered the semantic equivalent of void, null, or undefined
- Any property accessor's GetValue method which returns success and a resulting "no value" object is indicating that the particular property has no value for the given instance and should be treated as if the property did not exist for that particular instance.
- Data model methods which do not semantically have a return value use this as a sentinel to indicate such (as a method must return a valid [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)).

## Parameters

### `object`

The newly created/boxed "no value" object will be returned here.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDataModelManager4> spManager; /* get the data model manager */

ComPtr<IModelObject> spNoValue;
if (SUCCEEDED(spManager->CreateNoValue(&spNoValue)))
{
    // spNoValue contains a "no value" object.  This can be
    // returned from IModelMethod::Call (an indication of no return value).
    // It can be returned from a property accessor to indicate that the
    // property has "no value" for the given instance.
}
```

## See also

[IDataModelManager4 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelmanager4)