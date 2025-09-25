# ISpellCheckProvider::InitializeWordlist

## Description

Initialize the specified word list to contain only the specified words.

## Parameters

### `wordlistType` [in]

The type of word list.

### `words` [in]

The set of words to be included in the word list, passed as an [IEnumString](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstring) object..

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Successful. |
| **E_ INVALIDARG** | *wordlistType* is not a valid member of the [WORDLIST_TYPE](https://learn.microsoft.com/windows/desktop/api/spellcheck/ne-spellcheck-wordlist_type) enumeration. |

## Remarks

This method is called by the system (for example, when the client calls [ISpellChecker::Add](https://learn.microsoft.com/windows/desktop/api/spellcheck/nf-spellcheck-ispellchecker-add)), which passes the words from the respective word list to the provider so that it can consider the word list when spell checking.

## See also

[IEnumString](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstring)

[ISpellCheckProvider](https://learn.microsoft.com/windows/desktop/api/spellcheckprovider/nn-spellcheckprovider-ispellcheckprovider)

[ISpellChecker::Add](https://learn.microsoft.com/windows/desktop/api/spellcheck/nf-spellcheck-ispellchecker-add)

[WORDLIST_TYPE](https://learn.microsoft.com/windows/desktop/api/spellcheck/ne-spellcheck-wordlist_type)