# ISpellChecker::Add

## Description

Treats the provided word as though it were part of the original dictionary.

The word will no longer be considered misspelled, and will also be considered as a candidate for suggestions.

## Parameters

### `word` [in]

The word to be added to the list of added words.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Successful. |
| **E_ INVALIDARG** | *word* is an empty string, or its length is greater than **MAX_WORD_LENGTH**. |
| **E_POINTER** | *word* is a null pointer. |

## See also

[ISpellChecker](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ispellchecker)