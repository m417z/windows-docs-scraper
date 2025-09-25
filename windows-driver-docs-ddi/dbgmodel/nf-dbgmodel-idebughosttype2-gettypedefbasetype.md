# IDebugHostType2::GetTypedefBaseType

## Description

The GetTypedefBaseType method will return what the immediate definition of the typedef. In this examples:

```cpp
typedef MYSTRUCT *PMYSTRUCT;
typedef PMYSTRUCT PTRMYSTRUCT;
```

this method will return MYSTRUCT * for PMYSTRUCT and PMYSTRUCT for PTRMYSTRUCT. For more information, see [IDebugHostType2::IsTypedef](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nf-dbgmodel-idebughosttype2-istypedef).

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

ComPtr<IDebugHostType2> spType2;
if (SUCCEEDED(spType.As(&spType2)))
{
    ComPtr<IDebugHostType> spBaseType;
    if (SUCCEEDED(spType2->GetTypedefBaseType(&spBaseType)))
    {
        // Returns the immediate base type of the typedef.  This may
        // be another typedef.
    }
}
```

## See also

[IDebugHostType2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype2)