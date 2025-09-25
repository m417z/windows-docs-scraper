## Description

The **wiasCreatePropContext** function allocates a property context to indicate which of an item's properties are being changed by the application.

## Parameters

### `cPropSpec`

Specifies the total number of PROPSPEC structures in the *pPropSpec* array.

### `pPropSpec` [in]

Pointer to the first element of an array of PROPSPEC structures identifying which properties are changing.

### `cProps`

Specifies the number of property identifiers stored in this context.

### `pProps` [in, optional]

Pointer to the first element of an array of property identifiers that indicate the properties to put into this property context.

### `pContext` [in]

Pointer to a [**WIA_PROPERTY_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_wia_property_context) structure that contains a property context.

## Return value

On success, the function returns S_OK. If the function fails, it returns a standard COM error or one of the [WIA error codes](https://learn.microsoft.com/windows/win32/wia/-wia-error-codes).

## Remarks

This function allocates a property context and fills in its values. This function is generally used in [wiasValidateItemProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasvalidateitemproperties) where the properties written by the application are validated.

Entries in the property context are identifiers for properties that either have dependents, or are themselves dependent on other properties. A context is used to mark which properties are being changed. When the property context is no longer needed, it should be freed by a call to [wiasFreePropContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasfreepropcontext).

The properties to which an application writes are specified by the *pPropSpec* array. The properties that were changed by the application, as well as any properties dependent on the changed properties, are specified by the *pProps* array. Only properties that have been changed by the application (and any dependent properties) can be specified in *pProps*.

For more information. see the [**PROPSPEC**](https://learn.microsoft.com/windows/win32/api/propidl/ns-propidl-propspec) structure.

Drivers can specify additional properties when creating a property context with wiasCreatePropContext.

The following properties are always present in WIA_PROPERTY_CONTEXT:

- WIA_IPA_DATATYPE

- WIA_IPA_DEPTH

- WIA_IPS_XRES

- WIA_IPS_XPOS

- WIA_IPS_XEXTENT

- WIA_IPA_PIXELS_PER_LINE

- WIA_IPS_YRES

- WIA_IPS_YPOS

- WIA_IPS_YEXTENT

- WIA_IPA_NUMBER_OF_LINES

- WIA_IPS_CUR_INTENT

- WIA_IPA_TYMED

- WIA_IPA_FORMAT

## See also

[**WIA_PROPERTY_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_wia_property_context)

[wiasFreePropContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasfreepropcontext)

[wiasValidateItemProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasvalidateitemproperties)