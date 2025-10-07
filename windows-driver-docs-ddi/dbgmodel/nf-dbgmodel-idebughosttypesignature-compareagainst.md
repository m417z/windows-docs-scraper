# IDebugHostTypeSignature::CompareAgainst

## Description

The CompareAgainst method compares the type signature to another type signature and returns how the two signatures compare. The comparison result which is returned is a member of the SignatureComparison enumeration which is defined as follows:

**Unrelated** - There is no relationship between the two signatures or types being compared.

**Ambiguous** - One signature or type compares ambiguously against the other. For two type signatures, this means that there are potential type instances which could match either signature equally well. As an example, the two type signatures shown below are ambiguous:

Signature 1:

```
std::pair<*, int>
```

Signature 2:

```
std::pair<int, *>
```

Because the type instance std::pair\<int, int> matches either one equally well (both have one concrete and one wildcard match).

**LessSpecific** - One signature or type is less specific than the other. Often, this means that the less specific signature has a wildcard where the more specific one has a concrete type. As an example, the first signature below is less specific than the second:

Signature 1:

```
std::pair<*, int>
```

Signature 2:

```
std::pair<int, int>
```

Because it has a wildcard (the \*) where the second has a concrete type (int).

**MoreSpecific** - One signature or type is more specific than the other. Often, this means that the more specific signature has a concrete type where the less specific one has a wildcard. As an example, the first signature below is more specific than the second:

Signature 1:

```
std::pair<int, int>
```

Signature 2:

```
std::pair<*, int>
```

Because it has a concrete type (int) where the second has a wildcard (the \*).

**Identical** - The two signatures or types are identical.

## Parameters

### `typeSignature`

The type signature to compare against.

### `result`

An indication of the relationship between the two signatures is returned here -- whether they are unrelated or identical, one is more or less specific than the other, or they are ambiguous. Such relationship is given by a member of the SignatureComparison enumeration.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHostTypeSignature> spSig1; /* get a type signature */
ComPtr<IDebugHostTypeSignature> spSig2; /* get a second type signature */

SignatureComparison compResult;
if (SUCCEEDED(spSig1->ComapreAgainst(spSig2.Get(), &compResult)))
{
    // compResult indicates how the two signatures are related (if at all)
    //     std::pair<int, *> and std::pair<*, int> would be related ambiguously
    //     std::pair<int, *> would be more specific than std::pair<*, *>
    //     std::pair<int, int> and std::pair<float, float> would be unrelated
}
```

## See also

[IDebugHostTypeSignature interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttypesignature)