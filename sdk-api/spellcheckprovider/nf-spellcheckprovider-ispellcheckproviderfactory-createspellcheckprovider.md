# ISpellCheckProviderFactory::CreateSpellCheckProvider

## Description

Creates a spell checker (implemented by a spell check provider) that supports the specified language. This interface is not used directly by clients, but by the Spell Checking API.

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

[ISpellCheckProviderFactory::IsSupported](https://learn.microsoft.com/windows/desktop/api/spellcheckprovider/nf-spellcheckprovider-ispellcheckproviderfactory-issupported) can be called to determine if *languageTag* is supported.

## See also

[BCP47 Tags for Identifying Languages](http://tools.ietf.org/html/bcp47)

[ISpellCheckProvider](https://learn.microsoft.com/windows/desktop/api/spellcheckprovider/nn-spellcheckprovider-ispellcheckprovider)

[ISpellCheckProviderFactory](https://learn.microsoft.com/windows/desktop/api/spellcheckprovider/nn-spellcheckprovider-ispellcheckproviderfactory)

[ISpellCheckProviderFactory::IsSupported](https://learn.microsoft.com/windows/desktop/api/spellcheckprovider/nf-spellcheckprovider-ispellcheckproviderfactory-issupported)