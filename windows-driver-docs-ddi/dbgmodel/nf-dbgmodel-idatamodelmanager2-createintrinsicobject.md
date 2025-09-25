# IDataModelManager2::CreateIntrinsicObject

## Description

The CreateIntrinsicObject method is the method which boxes intrinsic values into [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject). The caller places the value in a COM VARIANT and calls this method. The data model manager returns an [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) representing the object. Note that this method is also used to box fundamental IUnknown based types: property accessors, methods, contexts, etc... In such cases, the objectKind method indicates what kind of IUnknown based construct the object represents and the punkVal field of the passed variant is the IUnknown derived type. The type must be statically castable to the appropriate model interface (e.g.: [IModelPropertyAccessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelpropertyaccessor), [IModelMethod](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelmethod), [IDebugHostContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostcontext), etc...) in process.

The VARIANT types that are supported by this method are VT_UI1, VT_I1, VT_UI2, VT_I2, VT_UI4, VT_I4, VT_UI8, VT_I8, VT_R4, VT_R8, VT_BOOL, VT_BSTR, and VT_UNKNOWN (for a specialized set of IUnknown derived types as indicated by the enumeration ModelObjectKind.

## Parameters

### `objectKind`

Indicates the kind of object which is being boxed. For normal intrinsics which differ by the variant type, ObjectIntrinsic is passed here. For others which are effectively IUnknown derived interfaces, the object type is one of the values in the ModelObjectKind enumeration and the interface in the VARIANT must match.

### `intrinsicData`

A VARIANT containing the value which is going to be boxed inside an [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) container.

### `object`

The newly boxed value (as an [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)) will be returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDataModelManager2> spManager; /* get the data model manager */

VARIANT vtValue;
vtValue.vt = VT_I4;
vtValue.lVal = 42;

// If the object is an VT_UNKNOWN, the first argument to CreateIntrinsicObject
// indicates what KIND of IUnknown.  For example, ObjectPropertyAccessor would
// indicate IModelPropertyAccessor.  ObjectMethod would indicate IModelMethod, etc...
ComPtr<IModelObject> spValue;
if (SUCCEEDED(spManager->CreateIntrinsicObject(ObjectIntrinsic, &vtValue, &spValue)))
{
    // spValue now contains the object (boxed) representation of the int value 42.
}
```

[IDataModelManager2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelmanager2)