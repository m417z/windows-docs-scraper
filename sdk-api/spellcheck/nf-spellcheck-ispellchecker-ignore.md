# ISpellChecker::Ignore

## Description

Ignores the provided word for the rest of this session.

Until this [ISpellChecker](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ispellchecker) interface is released, the word will no longer be considered misspelled, but it will not be considered as a candidate for suggestions.

## Parameters

### `word` [in]

The word to ignore.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Successful. |
| **E_ INVALIDARG** | *word* is an empty string, or its length is greater than **MAX_WORD_LENGTH**. |
| **E_POINTER** | *word* is a null pointer. |

## See also

[ISpellChecker](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ispellchecker)