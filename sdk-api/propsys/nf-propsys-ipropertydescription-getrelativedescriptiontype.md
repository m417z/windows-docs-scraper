# IPropertyDescription::GetRelativeDescriptionType

## Description

Gets the relative description type for a property description.

## Parameters

### `prdt` [out]

Type: **[PROPDESC_RELATIVEDESCRIPTION_TYPE](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_relativedescription_type)***

When this method returns, contains a pointer to the relative description type value. See [PROPDESC_RELATIVEDESCRIPTION_TYPE](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_relativedescription_type) for valid values.

## Return value

Type: **HRESULT**

Always returns **S_OK**.

## Remarks

The information retrieved by this method comes from the *relativeDescriptionType* attribute of the [displayInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-displayinfo) element in the property's .propdesc file.

## See also

[IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription)

[Property Description Schema](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-entry)