# IAccDictionary::ConvertValueToString

## Description

Clients call the **IAccDictionary::ConvertValueToString** method to convert a value to a localized string.

**Note** Active Accessibility Text Services is deprecated. Please see
[Microsoft Windows Text Services Framework](https://learn.microsoft.com/windows/win32/tsf/text-services-framework) for more information on advanced text input and natural language technologies.

## Parameters

### `Term` [in]

Type: **REFGUID**

A GUID that represents a property.

### `lcid` [in]

Type: **[LCID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The locale of the string to be returned.

### `varValue` [in]

Type: **VARIANT**

The value of the item.

### `pbstrResult` [out]

Type: **BSTR***

A pointer to the converted value.

### `plcid` [out]

Type: **[LCID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to the language of the returned string.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

## Remarks

If the *Term* parameter can be true or false, **ConvertValueToString** will return a localized string or **TRUE** or **FALSE**. If the *Term* parameter represents a color, **ConvertValueToString** will return a string for the closest color name. If the *Term* parameter is not found in the dictionary, then *pbstrResult* will be **NULL**.