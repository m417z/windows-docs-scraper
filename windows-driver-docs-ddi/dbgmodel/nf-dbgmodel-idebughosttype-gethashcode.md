# IDebugHostType::GetHashCode

## Description

The GetHashCode method returns a 32-bit hash code for the type. With the exception of a global match (e.g.: a type signature equivalent to * which matches everything if permitted by the host), any type instance which can match a particular type signature must return the same hash code.

This method is used in conjunction with type signatures in order to match type signatures to type instances.

## Parameters

### `hashCode`

A 32-bit hash code for the type instance. Every type which is capable of matching another type via a non-global match type signature will return the same hash code here. The debug host must guarantee such synchronization between its type signature methods and this method.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHostType> spType; /* get a type (see FindTypeByName) */

ULONG typeHash;
if (SUCCEEDED(spType->GetHashCode(&typeHash)))
{
    // typeHash contains a 32-bit hash code.  The hash must be identical for
    // every type which can match a type signature (unless the signature
    // is a total wildcard).
}
```

## See also

[IDebugHostType interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype)