# IPropertyChange::ApplyToPropVariant

## Description

Applies a change to a property value.

## Parameters

### `propvarIn` [in]

Type: **REFPROPVARIANT**

A reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `ppropvarOut` [out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

A pointer to a changed [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IPropertyChange](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertychange)

[PSCreateSimplePropertyChange](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pscreatesimplepropertychange)