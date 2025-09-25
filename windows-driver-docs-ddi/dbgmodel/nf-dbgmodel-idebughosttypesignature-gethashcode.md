# IDebugHostTypeSignature::GetHashCode

## Description

The GetHashCode method returns a 32-bit hash code for the type signature. The debug host guarantees that there is synchronization in implementation between the hash code returned for type instances and the hash code returned for type signatures. With the exception of a global match, if a type instance is capable of matching a type signature, both will have the same 32-bit hash code. This allows an initial rapid comparison and match between a type instance and a plethora of type signatures registered with the data model manager.

## Parameters

### `hashCode`

A 32-bit hash code for the type signature is returned here. With the exception of a global match type signature, this hash code will be identical to the hash code of any type instance capable of matching this type signature.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHostTypeSignature> spSig; /* create a type signature */

ULONG signatureHash;
if (SUCCEEDED(spSig->GetHashCode(&signatureHash)))
{
    // signatureHash contains a 32-bit hash code for the type signature.
    // Unless the type signature is a complete wildcard, any type which CAN
    // match this signature will have the same hash code returned
    // from IDebugHostType::GetHashCode.
}
```

## See also

[IDebugHostTypeSignature interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttypesignature)