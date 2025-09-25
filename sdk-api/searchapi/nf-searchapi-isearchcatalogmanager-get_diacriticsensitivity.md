# ISearchCatalogManager::get_DiacriticSensitivity

## Description

Gets a value that indicates whether the catalog is sensitive to diacritics. A diacritic is a mark added to a letter to indicate a special phonetic value or pronunciation.

## Parameters

### `pfDiacriticSensitive` [out, retval]

Type: **BOOL***

Receives a pointer to a Boolean value that indicates whether the catalog is sensitive to diacritics. **TRUE** if the catalog is sensitive to and recognizes diacritics; otherwise, **FALSE**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.