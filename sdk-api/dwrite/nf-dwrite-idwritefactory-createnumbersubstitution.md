# IDWriteFactory::CreateNumberSubstitution

## Description

 Creates a number substitution object using a locale name,
substitution method, and an indicator whether to ignore user overrides (use NLS
defaults for the given culture instead).

## Parameters

### `substitutionMethod` [in]

Type: **[DWRITE_NUMBER_SUBSTITUTION_METHOD](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_number_substitution_method)**

A value that specifies how to apply number substitution on digits and related punctuation.

### `localeName` [in]

Type: **const WCHAR***

The name of the locale to be used in the *numberSubstitution* object.

### `ignoreUserOverride` [in]

Type: **BOOL**

A Boolean flag that indicates whether to ignore user overrides.

### `numberSubstitution` [out]

Type: **[IDWriteNumberSubstitution](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritenumbersubstitution)****

When this method returns, contains an address to a pointer to the number substitution object created by this method.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFactory](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefactory)