# IDebugHostBaseClass::GetOffset

## Description

The GetOffset method returns the offset of the base class from the base address of the derived class. Such offset may be zero or may be a positive unsigned 64-bit value.

## Parameters

### `offset`

The offset of the base class from the base address of the derived class is returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Code Sample**

```cpp
ComPtr<IDebugHostBaseClass> spBaseClass; /* get a base class symbol (see
                                            EnumerateChildren) */

ULONG64 offset;
if (SUCCEEDED(spBaseClass->GetOffset(&offset)))
{
    // offset indicates the position of the base class relative to the
    // start of its parent class.
}
```

## See also

[IDebugHostBaseClass interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostbaseclass)