# IShellItem2::GetPropertyStoreWithCreateObject

## Description

Uses the specified [ICreateObject](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-icreateobject) instead of [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) to create an instance of the property handler associated with the Shell item on which this method is called. Most calling applications do not need to call this method, and can call [IShellItem2::GetPropertyStore](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellitem2-getpropertystore) instead.

## Parameters

### `flags` [in]

Type: **[GETPROPERTYSTOREFLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-getpropertystoreflags)**

The [GETPROPERTYSTOREFLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-getpropertystoreflags) constants that modify the property store object.

### `punkCreateObject` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to a factory for low-rights creation of type [ICreateObject](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-icreateobject).

The method [CreateObject](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-icreateobject-createobject) creates an instance of a COM object. The implementation of **IShellItem2::GetPropertyStoreWithCreateObject** uses **CreateObject** instead of [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) to create the property handler, which is a Shell extension, for a given file type. The property handler provides many of the important properties in the property store that this method returns.

This method is useful only if the [ICreateObject](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-icreateobject) object is created in a separate process (as a LOCALSERVER instead of an INPROCSERVER), and also if this other process has lower rights than the process calling **IShellItem2::GetPropertyStoreWithCreateObject**.

### `riid` [in]

Type: **REFIID**

A reference to the IID of the object to be retrieved.

### `ppv` [out]

Type: **void****

When this method returns, contains the address of the requested [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) interface pointer.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Note** When this method is called on a property store for a file, that file is held open for the lifetime of the [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) object.