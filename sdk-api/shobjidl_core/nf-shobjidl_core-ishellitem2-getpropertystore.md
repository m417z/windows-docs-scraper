# IShellItem2::GetPropertyStore

## Description

Gets a property store object for specified property store flags.

## Parameters

### `flags` [in]

Type: **[GETPROPERTYSTOREFLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-getpropertystoreflags)**

The [GETPROPERTYSTOREFLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-getpropertystoreflags) constants that modify the property store object.

### `riid` [in]

Type: **REFIID**

A reference to the IID of the object to be retrieved.

### `ppv` [out]

Type: **void****

When this method returns, contains the address of an [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) interface pointer.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Note** When this method is called on a property store for a file, that file is held open for the lifetime of the [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) object.