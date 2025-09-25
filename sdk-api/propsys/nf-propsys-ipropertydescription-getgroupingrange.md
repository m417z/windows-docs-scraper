# IPropertyDescription::GetGroupingRange

## Description

Gets the grouping method to be used when a view is grouped by a property, and retrieves the grouping type.

## Parameters

### `pgr` [out]

Type: **PROPDESC_GROUPING_RANGE***

Receives a pointer to a flag value that indicates the grouping type. The possible values are:

#### PDGR_DISCRETE

Displays individual values.

#### PDGR_ALPHANUMERIC

Displays static alphanumeric ranges.

#### PDGR_SIZE

Displays static size ranges.

#### PDGR_DYNAMIC

Displays dynamically created ranges.

#### PDGR_DATE

Displays month and year groups.

#### PDGR_PERCENT

Displays percent groups.

#### PDGR_ENUMERATED

Displays percent groups returned by [IPropertyDescription::GetEnumTypeList](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertydescription-getenumtypelist).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The information retrieved by this method comes from the *groupingRange* attribute of the [typeInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-typeinfo) element in the property's .propdesc file.

## See also

[IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription)

[Property Description Schema](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-entry)