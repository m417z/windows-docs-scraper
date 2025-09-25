# ISpellChecker::Check

## Description

Checks the spelling of the supplied text and returns a collection of spelling errors.

## Parameters

### `text` [in]

The text to check.

### `value` [out, retval]

The result of checking this text, returned as an [IEnumSpellingError](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ienumspellingerror) object.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Successful. |
| **E_ INVALIDARG** | *text* is an empty string. |
| **E_POINTER** | *text* is a null pointer. |

## Remarks

The returned [IEnumSpellingError](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ienumspellingerror) contains the results of spell checking. A correct *text* returns an empty (not a null) enumeration.

## See also

[IEnumSpellingError](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ienumspellingerror)

[ISpellChecker](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ispellchecker)