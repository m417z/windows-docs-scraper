# IDebugHostSymbol2::GetLanguage

## Description

If the symbol can identify the language for which it applies, this returns an identifier for such. Many symbols will *NOT* be able to make this determination. In such cases, this method will fail.

It is also possible that the host does not understand the language or there is no defined LanguageKind. In such cases, LanguageUnknown will be returned and the method will succeed.

## Parameters

### `pKind`

If it is possible to determine from the symbolic information, the language in which the given symbol was defined is returned here. This may be indeterminate for many symbols.

## Return value

This method returns HRESULT which indicate success or failure.

## Remarks

## See also

[IDebugHostSymbol2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostsymbol2)