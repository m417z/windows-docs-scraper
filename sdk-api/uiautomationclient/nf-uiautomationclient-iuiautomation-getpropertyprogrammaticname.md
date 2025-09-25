# IUIAutomation::GetPropertyProgrammaticName

## Description

Retrieves the registered programmatic name of a property.

## Parameters

### `property` [in]

Type: **PROPERTYID**

The property identifier. For a list of property IDs, see [Property Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-entry-propids).

### `name` [out, retval]

Type: **BSTR***

Receives the registered programmatic name.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The programmatic name is intended for debugging and diagnostic purposes only. The string is not localized.

This property should not be used in string comparisons. To determine whether two properties are the same, compare the property identifiers directly.