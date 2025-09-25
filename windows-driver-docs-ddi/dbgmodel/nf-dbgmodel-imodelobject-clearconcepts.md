# IModelObject::ClearConcepts

## Description

The ClearConcepts method will remove all concepts from the instance of the object specified by this.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Code Sample**

```cpp
ComPtr<IModelObject> spObject; /* get an object */

if (SUCCEEDED(spObject->ClearConcepts()))
{
    // All concepts are gone from spObject.  Parent models may still have concepts.
    // GetConcept may find concepts from parent models.
}
```

## See also

[IModelObject interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)