# PSCreateSimplePropertyChange function

## Description

Creates a simple property change.

## Parameters

### `flags` [in]

Type: **[PKA_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-pka_flags)**

[PKA_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-pka_flags) flags.

### `key` [in]

Type: **REFPROPERTYKEY**

Reference to a [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure.

### `propvar` [in]

Type: **REFPROPVARIANT**

Reference to a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `riid` [in]

Type: **REFIID**

Reference to a specified IID.

### `ppv` [out]

Type: **void****

The address of an [IPropertyChange](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertychange) interface pointer.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Property changes can be placed into an [IPropertyChangeArray](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertychangearray) which can then be used with [IFileOperation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperation) to modify the properties on an item.