# IAccDictionary::GetLocalizedString

## Description

Clients call the **IAccDictionary::GetLocalizedString** method to get localized strings for all system properties and their values.

**Note** Active Accessibility Text Services is deprecated. Please see
[Microsoft Windows Text Services Framework](https://learn.microsoft.com/windows/win32/tsf/text-services-framework) for more information on advanced text input and natural language technologies.

## Parameters

### `Term` [in]

Type: **REFGUID**

A globally unique identifier (GUID) that represents a property.

### `lcid` [in]

Type: **[LCID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The locale of the string to be returned.

### `pResult` [out]

Type: **BSTR***

A localized string that represents the term.

### `plcid` [out]

Type: **[LCID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The language of the returned string.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

## Remarks

This method returns the names of a property in the language specified by *lcid*. If that language is not on the system, Microsoft Active Accessibility finds the best match and returns the string in that language. If the *Term* parameter is not found in the dictionary, the *pResult* will be **NULL**.