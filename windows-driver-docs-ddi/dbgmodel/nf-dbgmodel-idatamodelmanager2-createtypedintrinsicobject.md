# IDataModelManager2::CreateTypedIntrinsicObject

## Description

The CreateTypedintrinsicObject method is similar to the CreateIntrinsicObject method excepting that it allows a native/language type to be associated with the data and carried along with the boxed value. This allows the data model to represent constructs such as native enumeration types (which are simply VT_UI* or VT_I* values). Pointer types are also created with this method. A native pointer in the data model is a zero extended 64-bit quantity representing an offset into the virtual address space of the debug target. It is boxed inside a VT_UI8 and is created with this method and a type which indicates a native/language pointer.

## Parameters

### `intrinsicData`

A VARIANT containing the value which is going to be boxd inside an [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) container. Note that this method does not support VT_UNKNOWN constructs. Anything passed to this method must be expressable as ObjectIntrinsic

### `type`

The native/language type of the value.

### `object`

The newly boxed value (as an [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)) will be returned here.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDataModelManager> spManager; /* get the data model manager */
ComPtr<IDebugHostType> spEnumType;   /* get an enum type (see CreateTypedObject) */
ComPtr<IDebugHostType> spPtrType;    /* get a pointer type (see CreateTypedObject) */

// Box an enum
VARIANT vtEnumValue;
vtEnumValue.vt = VT_I4;
vtEnumValue.lVal = 2;

ComPtr<IModelObject> spEnumValue;
if (SUCCEEDED(spManager->CreateTypedIntrinsicObject(&vtEnumValue,
                                                    spEnumType.Get(),
                                                    &spEnumValue)))
{
    // spEnumValue now contains the value '2' expressed as the enum type
    // in spEnumType.  The value will still present as 2 and operate as any other int.
    // A type query on the object will, however, yield the enum type.
}

// Box a pointer.  All pointers are represented as unsigned 64-bit values.
// 32-bit pointers are **ZERO EXTENDED** to 64-bits.
VARIANT vtPtrValue;
vtPtrValue.vt = VT_UI8;
vtPtrValue.ullVal = 0x100; // the pointer address

ComPtr<IModelObject> spPtrValue;
if (SUCCEEDED(spManager->CreateTypedIntrinsicObject(&vtPtrValue, spPtrType.Get(), &spPtrValue)))
{
    // spPtrValue now contains a <TYPE (POINTER)>(0x100).  You can fetch
    // the pointer address through standard means of GetIntrinsicValue(As).
    // Dereference() will work on spPtrValue!
}
```

## See also

[IDataModelManager2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelmanager2)