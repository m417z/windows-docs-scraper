# _WIAS_CHANGED_VALUE_INFO structure

## Description

The WIAS_CHANGED_VALUE_INFO structure is used to store the current and previous values of a property.

## Members

### `bChanged`

Is a Boolean that indicates whether a property has changed. That is, if the property's current value is different from its value before [IWiaMiniDrv::drvValidateItemProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvvalidateitemproperties) was called. Upon return from one of the **wiasGetChangedValue**_Xxx_ functions, this member is **TRUE** if the property changed, and **FALSE** if the property did not change.

### `vt`

Specifies the variant data type for the property. This member can be one of the following:

VT_UI1

VT_UI2

VT_UI4

VT_I2

VT_I4

VT_R4

VT_R8

VT_CLSID

VT_BSTR

See the [PROPVARIANT](https://learn.microsoft.com/windows/win32/api/propidl/ns-propidl-propvariant) structure for more information.

### `Old`

### `Old.lVal`

### `Old.fltVal`

### `Old.bstrVal`

### `Old.guidVal`

### `Current`

### `Current.lVal`

### `Current.fltVal`

### `Current.bstrVal`

### `Current.guidVal`

## Remarks

The **wiasGetChangedValue**_Xxx_ functions, use this structure to determine whether a property of a certain type has been changed by an application. These functions are used when the minidriver performs property validation, which occurs within the body of [IWiaMiniDrv::drvValidateItemProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvvalidateitemproperties).

## See also

[IWiaMiniDrv::drvValidateItemProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvvalidateitemproperties)

[wiasGetChangedValueFloat](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasgetchangedvaluefloat)

[wiasGetChangedValueGuid](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasgetchangedvalueguid)

[wiasGetChangedValueLong](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasgetchangedvaluelong)

[wiasGetChangedValueStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasgetchangedvaluestr)