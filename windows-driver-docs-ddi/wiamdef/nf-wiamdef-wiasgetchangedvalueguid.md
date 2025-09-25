# wiasGetChangedValueGuid function

## Description

The **wiasGetChangedValueGuid** function determines whether a property with a GUID value has been changed by an application.

## Parameters

### `pWiasContext` [in]

Pointer to a WIA item context.

### `pContext` [in]

Pointer to a [WIA_PROPERTY_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_wia_property_context) structure that contains the current property context.

### `bNoValidation`

Indicates whether the property's current value should be validated against its set of valid values. If this parameter is set to **TRUE**, the function does not perform validation on the property. If it is **FALSE**, the function performs data validation.

### `propID`

Specifies the property identifier of the property being tested.

### `pInfo`

Pointer to a [WIAS_CHANGED_VALUE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_wias_changed_value_info) structure that contains the current and previous values of the property.

## Return value

On success, the function returns S_OK.

If the function fails, it returns a standard COM error or one of the [WIA error codes](https://learn.microsoft.com/windows/win32/wia/-wia-error-codes).

## Remarks

The driver should validate the property only after the driver has updated the values of the property. The driver updates the values as a result of property changes requested by the application.

## See also

[WIAS_CHANGED_VALUE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_wias_changed_value_info)

[WIA_PROPERTY_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_wia_property_context)

[wiasGetChangedValueFloat](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasgetchangedvaluefloat)

[wiasGetChangedValueLong](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasgetchangedvaluelong)

[wiasGetChangedValueStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasgetchangedvaluestr)