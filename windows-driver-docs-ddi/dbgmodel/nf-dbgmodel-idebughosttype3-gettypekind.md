## Description

The GetTypeKind method returns what kind of type (pointer, array, intrinsic, etc...) the symbol refers to.

## Parameters

### `kind`

The kind of type the symbol refers to will be returned here (as a member of the [TypeKind enumeration](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/ne-dbgmodel-typekind)).

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHostType2> spType; /* get a type (see FindTypeByName) */

TypeKind tk;
if (SUCCEEDED(spType->GetTypeKind(&tk)))
{
    // tk is the kind of type
    //    TypePointer: it's a pointer
    //    TypeArray:   it's an array
    //    etc...
}

```

## See also

[IDebugHostType3 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype3)