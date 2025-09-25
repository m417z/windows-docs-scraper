# ISpellChecker2::Remove

## Description

Removes a word that was previously added by [ISpellChecker.Add](https://learn.microsoft.com/windows/desktop/api/spellcheck/nf-spellcheck-ispellchecker-add), or set by [ISpellChecker.Ignore](https://learn.microsoft.com/windows/desktop/api/spellcheck/nf-spellcheck-ispellchecker-ignore) to be ignored.

## Parameters

### `word` [in]

The word to be removed from the list of added words, or from the list of ignored words. If the word is not present, nothing will be removed.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Successful. |
| **E_ INVALIDARG** | *word* is an empty string, or its length is greater than **MAX_WORD_LENGTH**. |
| **E_POINTER** | *word* is a null pointer. |

## See also

[ISpellChecker](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ispellchecker)

[ISpellChecker.Add](https://learn.microsoft.com/windows/desktop/api/spellcheck/nf-spellcheck-ispellchecker-add)

[ISpellChecker.Ignore](https://learn.microsoft.com/windows/desktop/api/spellcheck/nf-spellcheck-ispellchecker-ignore)

[ISpellChecker2](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ispellchecker2)