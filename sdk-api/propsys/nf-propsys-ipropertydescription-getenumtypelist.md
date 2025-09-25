# IPropertyDescription::GetEnumTypeList

## Description

Gets an instance of an [IPropertyEnumTypeList](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertyenumtypelist), which can be used to enumerate the possible values for a property.

## Parameters

### `riid` [in]

Type: **REFIID**

A reference to the IID of the interface to retrieve through ppv, typically IID_IShellItem.

### `ppv` [out]

Type: **void****

When this method returns successfully, contains the interface pointer requested in riid. This is typically [IPropertyEnumTypeList](https://learn.microsoft.com/windows/win32/api/propsys/nn-propsys-ipropertyenumtypelist).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.