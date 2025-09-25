# ISearchLanguageSupport::GetDiacriticSensitivity

## Description

Gets the sensitivity of an implemented [ISearchLanguageSupport](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchlanguagesupport) interface to diacritics. A diacritic is an accent mark added to a letter to indicate a special phonetic value or pronunciation.

## Parameters

### `pfDiacriticSensitive` [out, retval]

Type: **BOOL***

On return, contains a pointer to the sensitivity setting. **FALSE** indicates that the interface ignores diacritics; **TRUE** indicates the interface recognizes diacritics.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.