# ITypeInfo::CreateInstance

## Description

Creates a new instance of a type that describes a component object class (coclass).

## Parameters

### `pUnkOuter` [in]

The controlling **IUnknown**. If Null, then a stand-alone instance is created. If valid, then an aggregate object is created.

### `riid` [in]

An ID for the interface that the caller will use to communicate with the resulting object.

### `ppvObj` [out]

An instance of the created object.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **E_NOINTERFACE** | OLE could not find an implementation of one or more required interfaces. |

Additional errors may be returned from [GetActiveObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-getactiveobject) or **CoCreateInstance**.

## Remarks

For types that describe a component object class (coclass), **CreateInstance** creates a new instance of the class. Normally, **CreateInstance** calls **CoCreateInstance** with the type description's GUID. For an Application object, it first calls [GetActiveObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-getactiveobject). If the application is active, **GetActiveObject** returns the active object; otherwise, if **GetActiveObject** fails, **CreateInstance** calls **CoCreateInstance**.

## See also

[ITypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo)