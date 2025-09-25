# ISpellCheckerFactory::CreateSpellChecker

## Description

Creates a spell checker that supports the specified language.

## Parameters

### `languageTag` [in]

A [BCP47](http://tools.ietf.org/html/bcp47) language tag that identifies the language for the requested spell checker.

### `value` [out, retval]

The created spell checker.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Successful. |
| **E_ INVALIDARG** | *languageTag* is an empty string, or there is no spell checker available for *languageTag*. |
| **E_POINTER** | *languageTag* is a null pointer. |

## Remarks

[ISpellCheckerFactory::IsSupported](https://learn.microsoft.com/windows/desktop/api/spellcheck/nf-spellcheck-ispellcheckerfactory-issupported) can be called to determine if *languageTag* is supported.
This will create the preferred spell checker (according to user ranking) for the given language.

## See also

[BCP47 Tags for Identifying Languages](http://tools.ietf.org/html/bcp47)

[ISpellChecker](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ispellchecker)

[ISpellCheckerFactory](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ispellcheckerfactory)

[ISpellCheckerFactory::IsSupported](https://learn.microsoft.com/windows/desktop/api/spellcheck/nf-spellcheck-ispellcheckerfactory-issupported)