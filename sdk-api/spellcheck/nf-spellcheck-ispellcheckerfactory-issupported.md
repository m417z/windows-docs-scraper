# ISpellCheckerFactory::IsSupported

## Description

Determines if the specified language is supported by a registered spell checker.

## Parameters

### `languageTag` [in]

A [BCP47](http://tools.ietf.org/html/bcp47) language tag that identifies the language for the requested spell checker.

### `value` [out, retval]

**TRUE** if supported; **FALSE** if not supported.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Successful. |
| **E_ INVALIDARG** | *languageTag* is an empty string. |
| **E_POINTER** | *languageTag* is a null pointer. |

## See also

[BCP47 Tags for Identifying Languages](http://tools.ietf.org/html/bcp47)

[ISpellCheckerFactory](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ispellcheckerfactory)