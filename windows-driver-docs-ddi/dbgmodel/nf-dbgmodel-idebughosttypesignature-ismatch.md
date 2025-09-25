# IDebugHostTypeSignature::IsMatch

## Description

The IsMatch method returns an indication of whether a particular type instance matches the criteria specified in the type signature. If it does, an indication of this is returned as well as an enumerator which will indicate all of the specific portions of the type instance (as symbols) which matched wildcards in the type signature.

## Parameters

### `type`

The type instance to compare against the type signature.

### `isMatch`

An indication of whether the type instance matches the type signature is returned here.

### `wildcardMatches`

If the type instance matches the type signature, an enumerator will be returned here which will enumerate all the specific portions of the type instance (as symbols) which matched wildcards in the type signature.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHostSymbols> spSym; /* get the host's symbols interface */
ComPtr<IDebugHostType> spType;   /* get a type */

ComPtr<IDebugHostTypeSignature> spSig;
if (SUCCEEDED(spSym->CreateTypeSignature(L"MyTemplateType<*>",
                                         nullptr,
                                         &spSig)))
{
    bool isMatch;
    ComPtr<IDebugHostSymbolEnumerator> spWildcardEnum;
    if (SUCCEEDED(spSig->IsMatch(spType.get(), &isMatch, &spWildcardEnum)))
    {
        // isMatch will contain whether the type matches the signature (whether
        // it is a MyTemplateType template with *ANY* template arguments
        if (isMatch)
        {
            // spWildcardEnum will contain what the '*' in 'MyTemplateType<*>'
            // matched against.  This may be one or more template arguments in
            // linear order.  An IDebugHostType would be present for type arguments.
        }
    }
}
```

## See also

[IDebugHostTypeSignature interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttypesignature)