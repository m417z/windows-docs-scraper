# IPropertyEnumTypeList::GetAt

## Description

Gets the [IPropertyEnumType](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertyenumtype) object at the specified index in the list.

## Parameters

### `itype` [in]

Type: **UINT**

The index of the object in the list.

### `riid` [in]

Type: **REFIID**

A reference to the IID of the interface to retrieve through ppv, typically IID_IShellItem.

### `ppv` [out]

Type: **void****

When this method returns successfully, contains the interface pointer requested in riid. This is typically [IPropertyEnumType](https://learn.microsoft.com/windows/win32/api/propsys/nn-propsys-ipropertyenumtype).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.