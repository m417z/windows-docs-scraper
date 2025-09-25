# IModelObject::Dereference

## Description

The Dereference method dereferences an object. This method can be used to dereference a data model based reference (ObjectTargetObjectReference, ObjectKeyReference) or a native language reference (a pointer or a language reference). It is important to note that this method removes a single level of reference semantics on the object. It is entirely possible to, for instance, have a data model reference to a language reference. In such a case, calling the Dereference method the first time would remove the data model reference and leave the language reference. Calling Dereference on that resulting object would subsequently remove the language reference and return the native value under that reference.

## Parameters

### `object`

The result of dereferencing the object will be returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Code Sample**

```cpp
ComPtr<IModelObject> spPointer; /* get a pointer */

ComPtr<IModelObject> spPointedTo;
if (SUCCEEDED(spPointer->Dereference(&spPointedTo)))
{
    // spPointedTo is a dereference of the pointer (or other applicable type of reference)
}
```

## See also

[IModelObject interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)