# IPropertyDescription::GetDisplayType

## Description

Gets the current data type used to display the property.

## Parameters

### `pdisplaytype` [out]

Type: **PROPDESC_DISPLAYTYPE***

Contains a pointer to a value that indicates the display type. One of the following values.

#### PDDT_STRING (0x00000000) (0)

The value is displayed as a string.

#### PDDT_NUMBER (0x00000001) (1)

The value is displayed as an integer.

#### PDDT_BOOLEAN (0x00000002) (2)

The value is displayed as a Boolean value.

#### PDDT_DATETIME (0x00000003) (3)

The value is displayed as date and time.

#### PDDT_ENUMERATED (0x00000004) (4)

The value is displayed as an enumerated type-list.
Use [IPropertyDescription::GetEnumTypeList](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertydescription-getenumtypelist) to handle this type.

## Return value

Type: **HRESULT**

Always returns **S_OK**.

## Remarks

The value retrieved by this method is originally set through the *displayType* attribute of the [displayInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-displayinfo) element in the property's .propdesc file.

## See also

[IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription)

[Property Description Schema](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-entry)