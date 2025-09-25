# IPropertyDescription::GetTypeFlags

## Description

Gets a set of flags that describe the uses and capabilities of the property.

## Parameters

### `mask` [in]

Type: **[PROPDESC_TYPE_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_type_flags)**

A mask that specifies which type flags to retrieve. A combination of values found in the [PROPDESC_TYPE_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_type_flags) constants. To retrieve all type flags, pass [PDTF_MASK_ALL](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_type_flags)

### `ppdtFlags` [out]

Type: **[PROPDESC_TYPE_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_type_flags)***

When this method returns, contains a pointer to a value that consists of bitwise [PROPDESC_TYPE_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_type_flags) values.

## Return value

Type: **HRESULT**

Always returns **S_OK**.

## Remarks

If the property description instance comes from [PSGetPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetpropertydescription) or [PSGetPropertyDescriptionByName](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetpropertydescriptionbyname), these flags come from the .propdesc file that defines the property description.

If the instance comes from [GetAt](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomcolorprofileresourcecollection-getat), the type flags come from the .propdesc file and may be influenced by the specific proplist. This means that flags obtained from one property description instance may be slightly different from another instance (both referring to the same property).

For additional information on type flags, see the *canGroupBy*, *canStackBy*, *isInnate*, *multipleValues*, *isGroup*, *isTreeProperty*, *isViewable*, *isQueryable*, and *includeInFullTextQuery* attributes of the [typeInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-typeinfo) element in the property's .propdesc file.

## See also

[IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription)

[Property Description Schema](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-entry)