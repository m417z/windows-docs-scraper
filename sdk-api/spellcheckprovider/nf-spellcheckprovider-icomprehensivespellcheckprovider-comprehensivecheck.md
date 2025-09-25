# IComprehensiveSpellCheckProvider::ComprehensiveCheck

## Description

Spell-check the provider text in a more thorough manner than [ISpellCheckProvider::Check](https://learn.microsoft.com/windows/desktop/api/spellcheckprovider/nf-spellcheckprovider-ispellcheckprovider-check).

## Parameters

### `text` [in]

The text to check.

### `value` [out]

The result of checking this text, as an enumeration of spelling errors ([IEnumSpellingError](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ienumspellingerror)), if any.

## Return value

This method can return one of these values.

| Return value | Description |
| --- | --- |
| S_OK | Successful. |
| E_INVALIDARG | *text* is an empty string. |
| E_POINTER | *text* is a null pointer. |

## Remarks

This interface isn't required to be implemented by a spell check provider. But if the provider supports two "modes" of spell checking (a faster one and a slower but more thorough one), it should implement this interface in the same object that implements [ISpellCheckProvider](https://learn.microsoft.com/windows/desktop/api/spellcheckprovider/nn-spellcheckprovider-ispellcheckprovider) to support the more thorough checking mode.
When a client calls [ISpellChecker::ComprehensiveCheck](https://learn.microsoft.com/windows/desktop/api/spellcheck/nf-spellcheck-ispellchecker-comprehensivecheck), the spell checking functionality will [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) the provider for [IComprehensiveSpellCheckProvider](https://learn.microsoft.com/windows/desktop/api/spellcheckprovider/nn-spellcheckprovider-icomprehensivespellcheckprovider), and call **IComprehensiveSpellCheckProvider.ComprehensiveCheck** if the interface is supported. If the interface isn't supported, it will silently fall back to [ISpellCheckProvider::Check](https://learn.microsoft.com/windows/desktop/api/spellcheckprovider/nf-spellcheckprovider-ispellcheckprovider-check).

## See also

[IComprehensiveSpellCheckProvider](https://learn.microsoft.com/windows/desktop/api/spellcheckprovider/nn-spellcheckprovider-icomprehensivespellcheckprovider)

[IEnumSpellingError](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ienumspellingerror)

[ISpellCheckProvider](https://learn.microsoft.com/windows/desktop/api/spellcheckprovider/nn-spellcheckprovider-ispellcheckprovider)

[ISpellCheckProvider::Check](https://learn.microsoft.com/windows/desktop/api/spellcheckprovider/nf-spellcheckprovider-ispellcheckprovider-check)

[ISpellChecker::ComprehensiveCheck](https://learn.microsoft.com/windows/desktop/api/spellcheck/nf-spellcheck-ispellchecker-comprehensivecheck)