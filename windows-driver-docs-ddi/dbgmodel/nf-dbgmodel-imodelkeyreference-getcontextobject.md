# IModelKeyReference::GetContextObject

## Description

The GetContextObject method returns the context (this pointer) which will be passed to a property accessor's GetValue or SetValue method if the key in question refers to a property accessor. The context object returned here may or may not be the same as the original object fetched from GetOriginalObject. If a key is on a parent model and there is a context adjustor associated with that parent model, the original object is the instance object on which GetKeyReference or EnumerateKeyReferences was called. The context object would be whatever comes out of the final context adjustor between the original object and the parent model containing the key to which this key reference is a handle. If there are no context adjustors, the original object and the context object are identical.

## Parameters

### `containingObject`

The context object which will be passed to any property accessor method is returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Code Sample**

```cpp
ComPtr<IModelObject> spObject; /* get an object */

ComPtr<IModelKeyReference> spKeyRef;
if (SUCCEEDED(spObject->GetKeyReference(L"Id", &spKeyRef, nullptr)))
{
    ComPtr<IModelObject> spContextObject;
    if (SUCCEEDED(spKeyRef->GetContextObject(&spContextObject)))
    {
        // spObject and spContextObject should be the same.
        // This is *NOT* true if there was an intervening call to OverrideContextObject
    }
}
```

## See also

[IModelKeyReference interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelkeyreference)