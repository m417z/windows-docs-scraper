# IEnumSpellingError::Next

## Description

Gets the next spelling error.

## Parameters

### `value` [out, retval]

The spelling error ([ISpellingError](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ispellingerror)) returned.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Successful. |
| **S_FALSE** | There is no spelling error left to return. *value* does not point at a valid [ISpellingError](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ispellingerror). |

## Remarks

If there are no spelling errors, this will return **S_FALSE**.
This provides a way for a provider to implement spell checking lazily if desired—instead of doing the spell checking work on [ISpellCheckProvider::Check](https://learn.microsoft.com/windows/desktop/api/spellcheck/nf-spellcheck-ispellchecker-check) and getting all the errors at once, you can do it only as needed when this method is called, getting one error per call.

## See also

[IEnumSpellingError](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ienumspellingerror)

[ISpellingError](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ispellingerror)