# wiasSetPropChanged function

## Description

The **wiasSetPropChanged** function modifies a property context to indicate that a property is being changed.

## Parameters

### `propid`

Specifies the property identifier of the property being changed.

### `pContext` [in]

Pointer to a [WIA_PROPERTY_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_wia_property_context) structure that contains the current property context.

### `bChanged`

Specifies the BOOL value that is used to set a particular element in the array pointed to by the **pChanged** member of a WIA_PROPERTY_CONTEXT structure. See the **Remarks** section for more details.

## Return value

On success, the function returns S_OK. If the function fails, it returns a standard COM error or one of the WIA_ERROR_XXX errors (described in the Microsoft Windows SDK documentation).

## Remarks

The **pChanged** member of the [WIA_PROPERTY_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_wia_property_context) structure points to an array of BOOL values that indicate whether a particular property will be changed. This function sets one element in that array for the specified property in the property context. This function should be used whenever a driver changes a property that has dependent properties in validation. For example, by changing "Current Intent", the "Horizontal Resolution" is changed and should be marked as changed, so that validation of "X Resolution" ([WIA_IPS_XRES](https://learn.microsoft.com/windows-hardware/drivers/image/wia-ips-xres))and its dependents still takes place.

## See also

[WIA_PROPERTY_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_wia_property_context)

[wiasIsPropChanged](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasispropchanged)