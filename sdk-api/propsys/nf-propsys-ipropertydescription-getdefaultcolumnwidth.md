# IPropertyDescription::GetDefaultColumnWidth

## Description

Gets the default column width of the property in a list view.

## Parameters

### `pcxChars` [out]

Type: **DWORD***

A pointer to the column width value, in characters.

## Return value

Type: **HRESULT**

Always returns **S_OK**.

## Remarks

The values retrieved by this method are originally set through the *defaultColumnWidth* attribute of the [displayInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-displayinfo) element in the property's .propdesc file.

If no value is set in the .propdesc file or if the method fails, the value pointed to by *pcxChars* is 20 characters.

## See also

[IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription)

[Property Description Schema](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-entry)