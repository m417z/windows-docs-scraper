# IModelKeyReference2::OverrideContextObject

## Description

The OverrideContextObject method (only present on [IModelKeyReference2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelkeyreference2)) is an advanced method which is used to permanently alter the context object which this key reference will pass to any underlying property accessor's GetValue or SetValue methods. The object passed to this method will also be returned from a call to GetContextObject. This method can be used by script providers to replicate certain dynamic language behaviors. Most clients should not call this method.

## Parameters

### `newContextObject`

The new context object to pass to any underlying property accessor's GetValue or SetValue methods.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Code Sample**

```cpp
ComPtr<IModelObject> spObject;          /* get an object */
ComPtr<IModelObject> spAdjustedContext; /* get the object you'd like to adjust context to */

ComPtr<IModelKeyReference> spKeyRef;
if (SUCCEEDED(spObject->GetKeyReference(L"Id", &spKeyRef, nullptr)))
{
    // At this moment, spKeyRef->GetContextObject() and
    // spKeyRef->GetOriginalObject() will return the same value
    ComPtr<IModelKeyReference2> spKeyRef2;
    if (SUCCEEDED(spKeyRef.As(&spKeyRef2)))
    {
        if (SUCCEEDED(spKeyRef2->OverrideContextObject(spAdjustedContext.Get())))
        {
            // Now, spKeyRef->GetContextObject() will return spAdjustedContext
            // and spKeyRef->GetOriginalObject() will return spObject
            // Very few clients will want to do this.  It is useful for some
            // bridges between dynamic languages and the data model.
        }
    }
}
```

## See also

[IModelKeyReference2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelkeyreference2)