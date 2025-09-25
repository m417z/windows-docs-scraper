# ISpellChecker::ComprehensiveCheck

## Description

Checks the spelling of the supplied text in a more thorough manner than [ISpellChecker::Check](https://learn.microsoft.com/windows/desktop/api/spellcheck/nf-spellcheck-ispellchecker-check), and returns a collection of spelling errors.

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

If the provider supports two "modes" of spell checking (a faster one and a slower but more thorough one), it implements [IComprehensiveSpellCheckProvider](https://learn.microsoft.com/windows/desktop/api/spellcheckprovider/nn-spellcheckprovider-icomprehensivespellcheckprovider) to support the more thorough checking mode.
When a client calls **ISpellChecker::ComprehensiveCheck**, the spell checking functionality will [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) the provider for **IComprehensiveSpellCheckProvider**, and call [IComprehensiveSpellCheckProvider.ComprehensiveCheck](https://learn.microsoft.com/windows/desktop/Intl/icomprehensivespellcheckprovider-comprehensivecheck) if the interface is supported. If the interface isn't supported, it will silently fall back to [ISpellCheckProvider::Check](https://learn.microsoft.com/windows/desktop/api/spellcheckprovider/nf-spellcheckprovider-ispellcheckprovider-check).

## See also

[IComprehensiveSpellCheckProvider](https://learn.microsoft.com/windows/desktop/api/spellcheckprovider/nn-spellcheckprovider-icomprehensivespellcheckprovider)

[IComprehensiveSpellCheckProvider.ComprehensiveCheck](https://learn.microsoft.com/windows/desktop/Intl/icomprehensivespellcheckprovider-comprehensivecheck)

[IEnumSpellingError](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ienumspellingerror)

[ISpellCheckProvider](https://learn.microsoft.com/windows/desktop/api/spellcheckprovider/nn-spellcheckprovider-ispellcheckprovider)

[ISpellCheckProvider::Check](https://learn.microsoft.com/windows/desktop/api/spellcheckprovider/nf-spellcheckprovider-ispellcheckprovider-check)

[ISpellChecker](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ispellchecker)