## Description

The GetTypedefBaseType method will return what the immediate definition of the typedef. In this example:

```cpp
typedef MYSTRUCT *PMYSTRUCT;
typedef PMYSTRUCT PTRMYSTRUCT;
```

this method will return MYSTRUCT * for PMYSTRUCT and PMYSTRUCT for PTRMYSTRUCT. For more information, see [IDebugHostType3::IsTypedef](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nf-dbgmodel-idebughosttype3-istypedef).

## Parameters

### `baseType`

Returns the immediate (first level) type that the typedef is a definition for. If the typedef is a definition of another typedef, this will return that typedef and not the final unwind of the definition chain.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHostType> spType; /* get a typedef type (only FindTypeByName since
                                  the compiler usually emits base types for data) */

ComPtr<IDebugHostType3> spType3;
if (SUCCEEDED(spType.As(&spType3)))
{
    ComPtr<IDebugHostType> spBaseType;
    if (SUCCEEDED(spType3->GetTypedefBaseType(&spBaseType)))
    {
        // Returns the immediate base type of the typedef.  This may
        // be another typedef.
    }
}
```

## See also

[IDebugHostType3 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype3)