# IPropertyDescription::GetSortDescriptionLabel

## Description

Gets the localized display string that describes the current sort order.

## Parameters

### `fDescending` [in]

Type: **BOOL***

**TRUE** if *ppszDescription* should reference the string "Z on top"; **FALSE** to reference the string "A on top".

### `ppszDescription` [out]

Type: **LPWSTR***

When this method returns, contains the address of a pointer to the sort description as a null-terminated Unicode string.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The string retrieved by this method is determined by flags set in the *sortDescription* attribute of the [labelInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-labelinfo) element in the property's .propdesc file.

It is the responsibility of the calling application to release *ppszDescription* when it is no longer needed.

## See also

[IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription)

[Property Description Schema](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-entry)