# IAccDictionary::GetMnemonicString

## Description

Retrieves a mnemonic string.

**Note** Active Accessibility Text Services is deprecated. Please see
[Microsoft Windows Text Services Framework](https://learn.microsoft.com/windows/win32/tsf/text-services-framework) for more information on advanced text input and natural language technologies.

## Parameters

### `Term` [in]

Type: **REFGUID**

A GUID representing a property.

### `pResult` [out]

Type: **BSTR***

A mnemonic string for the property. This string is not localized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

## Remarks

If the *Term* parameter is not found in the dictionary, then *pResult* will be **NULL**.