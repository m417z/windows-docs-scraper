# IShellItem2::GetPropertyDescriptionList

## Description

Gets a property description list object given a reference to a property key.

## Parameters

### `keyType` [in]

Type: **REFPROPERTYKEY**

A reference to a [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure.

### `riid` [in]

Type: **REFIID**

A reference to a desired IID.

### `ppv` [out]

Type: **void****

Contains the address of an [IPropertyDescriptionList](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescriptionlist) interface pointer.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.