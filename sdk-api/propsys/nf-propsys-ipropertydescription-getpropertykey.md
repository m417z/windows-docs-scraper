# IPropertyDescription::GetPropertyKey

## Description

Gets a structure that acts as a property's unique identifier.

## Parameters

### `pkey` [out]

Type: **[PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey)***

When this method returns, contains a pointer to a [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The information retrieved by this method comes from the [propertyDescription](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-propertydescription) element in the property's .propdesc file.

## See also

[IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription)

[Property Description Schema](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-entry)