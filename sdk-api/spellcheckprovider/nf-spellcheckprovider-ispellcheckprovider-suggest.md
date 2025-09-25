# ISpellCheckProvider::Suggest

## Description

Retrieves spelling suggestions for the supplied text.

## Parameters

### `word` [in]

The word or phrase to get suggestions for.

### `value` [out, retval]

The list of suggestions, returned as an [IEnumString](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstring) object.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Successful. |
| **S_FALSE** | *word* is correctly spelled. *value* contains one entry, which is the text that was passed in. |
| **E_ INVALIDARG** | *word* is an empty string. |
| **E_POINTER** | *word* is a null pointer. |

## See also

[IEnumString](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstring)

[ISpellCheckProvider](https://learn.microsoft.com/windows/desktop/api/spellcheckprovider/nn-spellcheckprovider-ispellcheckprovider)