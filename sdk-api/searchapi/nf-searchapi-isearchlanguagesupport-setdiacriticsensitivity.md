# ISearchLanguageSupport::SetDiacriticSensitivity

## Description

Sets a value that indicates whether an implemented [ISearchLanguageSupport](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchlanguagesupport) interface is sensitive to diacritics. A diacritic is an accent mark added to a letter to indicate a special phonetic value or pronunciation.

## Parameters

### `fDiacriticSensitive` [in]

Type: **BOOL**

A Boolean value that indicates whether the interface is sensitive to diacritics. The default setting is **FALSE**, indicating that the interface ignores diacritical characters.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.