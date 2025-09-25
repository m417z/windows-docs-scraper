# ISpellChecker::AutoCorrect

## Description

Causes occurrences of one word to be replaced by another.

## Parameters

### `from` [in]

The incorrectly spelled word to be autocorrected.

### `to` [in]

The correctly spelled word that should replace *from*.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Successful. |
| **E_ INVALIDARG** | *from* or *to* is an empty string, or the length of at least one of the parameters is greater than **MAX_WORD_LENGTH**. |
| **E_POINTER** | *from* or *to* is a null pointer. |

## See also

[ISpellChecker](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ispellchecker)