# IModelObject::GetConcept

## Description

The GetConcept method will search for a concept on the object (or its parent model chain) and return an interface pointer to the concept interface. The behavior and methods on a concept interface are specific to each concept. It is important to note, however, that many of the concept interfaces require the caller to explicitly pass the context object (or what one might traditionally call the this pointer). It is important to ensure that the correct context object is passed to every concept interface.

## Parameters

### `conceptId`

The unique identifier of the concept being queried. This is also the IID of the core interface of the concept.

### `conceptInterface`

The interface defined by conceptId will be returned in this argument.

### `conceptMetadata`

The metadata store associated with this concept will be optionally returned in this argument

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Code Sample**

```cpp
ComPtr<IModelObject> spObject; /* get some object */

// Get the string conversion of spObject through the string displayable concept:
ComPtr<IStringDisplayableConcept> spStringDisplayable;
if (SUCCEEDED(spObject->GetConcept(__uuidof(IStringDisplayableConcept),
                                   &spStringDisplayable,
                                   nullptr)))
{
    BSTR stringConversion;
    if (SUCCEEDED(spStringDisplayable->ToDisplayString(spObject.Get(),
                                                       nullptr,
                                                       &stringConversion)))
    {
        // stringConversion contains the display string conversion for the object
        SysFreeString(stringConversion);
    }
}
```

## See also

[IModelObject interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)