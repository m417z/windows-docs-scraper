# IDebugHostType::GetTypeKind

## Description

The GetTypeKind method returns what kind of type (pointer, array, intrinsic, etc...) the symbol refers to. See the [TypeKind enumeration](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/ne-dbgmodel-typekind) for more information.

## Parameters

### `kind`

The kind of type the symbol refers to will be returned here (as a member of the TypeKind enumeration).

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHostType> spType; /* get a type (see FindTypeByName) */

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

[IDebugHostType interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype)