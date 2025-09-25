# wiasIsPropChanged function

## Description

The **wiasIsPropChanged** function tests whether a specified property has been changed by an application.

## Parameters

### `propid`

Specifies the property identifier of the property to be checked.

### `pContext` [in]

Pointer to a [WIA_PROPERTY_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_wia_property_context) structure that contains the current property context.

### `pbChanged` [out]

Pointer to a memory location that receives a BOOL value. The BOOL value is **TRUE** if the property changed, and **FALSE** if the property did not change.

## Return value

On success, the function returns S_OK.

If the function fails, it returns a standard COM error or one of the [WIA error codes](https://learn.microsoft.com/windows/win32/wia/-wia-error-codes).

## Remarks

This function determines whether a property is being changed by looking at the **bChanged** member value in the property's [WIA_PROPERTY_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_wia_property_context) structure. Minidrivers typically use this function to check when an independent property has been changed so that its dependents can be updated.

## See also

[WIA_PROPERTY_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_wia_property_context)

[wiasGetChangedValueFloat](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasgetchangedvaluefloat)

[wiasGetChangedValueGuid](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasgetchangedvalueguid)

[wiasGetChangedValueLong](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasgetchangedvaluelong)

[wiasGetChangedValueStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasgetchangedvaluestr)