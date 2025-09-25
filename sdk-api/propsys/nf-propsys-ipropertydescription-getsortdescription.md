# IPropertyDescription::GetSortDescription

## Description

Gets the current sort description flags for the property, which indicate the particular wordings of sort offerings.

## Parameters

### `psd` [out]

Type: **PROPDESC_SORTDESCRIPTION***

When this method returns, contains a pointer to the value of one or more of the following flags that indicate the sort types available to the user. Note that the strings shown are English versions only. Localized strings are used for other locales.

#### PDSD_GENERAL

Default. "Sort going up", "Sort going down"

#### PDSD_A_Z

"A on top", "Z on top"

#### PDSD_LOWEST_HIGHEST

"Lowest on top", "Highest on top"

#### PDSD_SMALLEST_BIGGEST

"Smallest on top", "Largest on top"

#### PDSD_OLDEST_NEWEST

"Oldest on top", "Newest on top"

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The settings retrieved by this method are set through the *sortDescription* attribute of the [labelInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-labelinfo) element in the property's .propdesc file.

## See also

[IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription)

[Property Description Schema](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-entry)