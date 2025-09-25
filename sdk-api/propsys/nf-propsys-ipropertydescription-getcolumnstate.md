# IPropertyDescription::GetColumnState

## Description

Gets the column state flag, which describes how the property should be treated by interfaces or APIs that use this flag.

## Parameters

### `pcsFlags` [out]

Type: **SHCOLSTATEF**

When this method returns, contains a pointer to the column state flag. See [SHCOLSTATE](https://learn.microsoft.com/windows/desktop/api/shtypes/ne-shtypes-shcolstate) for valid values.

## Return value

Type: **HRESULT**

Always returns **S_OK**.

## Remarks

The value retrieved by this method is originally set through the *displayType* attribute of the [displayInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-displayinfo) element in the property's .propdesc file.

## See also

[IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription)

[Property Description Schema](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-entry)