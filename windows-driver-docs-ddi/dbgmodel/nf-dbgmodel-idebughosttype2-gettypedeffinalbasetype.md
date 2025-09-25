# IDebugHostType2::GetTypedefFinalBaseType

## Description

The GetTypedefFinalBaseType method will return the final type that the typedef is a definition for. If the typedef is a definition of another typedef, this will continue to follow the definition chain until it reaches a type which is not a typedef and that type will be returned. In this example:

```cpp
typedef MYSTRUCT *PMYSTRUCT;
typedef PMYSTRUCT PTRMYSTRUCT;
```

this method will return MYSTRUCT * when called on either PMYSTRUCT or PTRMYSTRUCT. For more information, see [IDebugHostType2::IsTypedef](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nf-dbgmodel-idebughosttype2-istypedef).

## Parameters

### `finalBaseType`

Returns the final type that the typedef is a definition for. If the typedef is a definition of another typedef, this will continue to follow the definition chain until it reaches a type which is not a typedef. Such type will be returned here.

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
    ComPtr<IDebugHostType> spFinalBaseType;
    if (SUCCEEDED(spType2->GetTypedefFinalBaseType(&spFinalBaseType)))
    {
        // Returns the final base type of the typedef.  This will follow the
        // typedef chain until it reaches a base type that is *NOT* a typedef.
    }
}
```

## See also

[IDebugHostType2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype2)