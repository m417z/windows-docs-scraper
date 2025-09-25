## Description

The IsTypedef method is the only method capable of seeing whether a type is a typedef. The [GetTypeKind method](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nf-dbgmodel-idebughosttype3-gettypekind) will behave as if called on the underlying type.

## Parameters

### `isTypedef`

Will return true if the type symbol is a typedef and false if it is not.

## Return value

This method returns HRESULT.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHostType> spType; /* get a type for a typedef (only FindTypeByName
                                  since the compiler usually only emits base types
                                  in the symbols for data) */

ComPtr<IDebugHostType3> spType3;
if (SUCCEEDED(spType.As(&spType3)))
{
    bool isTypeDef;
    if (SUCCEEDED(spType3->IsTypedef(&isTypeDef)))
    {
        // isTypeDef indicates whether the type is a typedef.
    }
}
```

Any type which is a typedef will behave as if the type is the final type underlying the typedef. This means that methods such as GetTypeKind will not indicate that the type is a typedef. Likewise, the [GetBaseType method](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nf-dbgmodel-idebughosttype3-getbasetype) will not return the type the definition refers to. They will instead indicate behave as if they were called on the final definition underlying the typedef. As an example:

```cpp
typedef MYSTRUCT *PMYSTRUCT;
typedef PMYSTRUCT PTRMYSTRUCT;
```

An [IDebugHostType](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype) for 'either PMYSTRUCT or PTRMYSTRUCT will report the following information:

- The GetTypeKind method will return TypePointer. The final underlying type MYSTRUCT * is indeed a pointer.

- The GetBaseType method will return a type for MYSTRUCT. The underlying type of MYSTRUCT * is MYSTRUCT.

The only difference here is how the typedef specific methods on [IDebugHostType3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype3) behave. Those methods are:

```cpp
STDMETHOD(IsTypedef)(_Out_ bool* isTypedef) PURE;

STDMETHOD(GetTypedefBaseType)(_Out_ IDebugHostType3** baseType) PURE;

STDMETHOD(GetTypedefFinalBaseType)(_Out_ IDebugHostType3** finalBaseType) PURE;
```

In this example:

- The IsTypedef method will return true for both PMYSTRUCT and PTRMYSTRUCT
- The GetTypedefBaseType method will return MYSTRUCT * for PMYSTRUCT and PMYSTRUCT for PTRMYSTRUCT
- The GetTypedefFinalBaseType method will return MYSTRUCT * for both types

## See also

[IDebugHostType3 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype3)