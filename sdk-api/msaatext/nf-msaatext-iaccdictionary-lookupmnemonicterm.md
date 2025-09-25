# IAccDictionary::LookupMnemonicTerm

## Description

Clients call the **IAccDictionary::LookupMnemonicTerm** method to find the property for a given mnemonic string.

**Note** Active Accessibility Text Services is deprecated. Please see
[Microsoft Windows Text Services Framework](https://learn.microsoft.com/windows/win32/tsf/text-services-framework) for more information on advanced text input and natural language technologies.

## Parameters

### `bstrMnemonic` [in]

Type: **BSTR**

A non-localized mnemonic string for a property.

### `pTerm` [out]

Type: **GUID***

A GUID representing the property in *bstrMnemonic*.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

## Remarks

If the *bstrMnemonic* parameter is not found in the dictionary, then *pTerm* will be **NULL**.