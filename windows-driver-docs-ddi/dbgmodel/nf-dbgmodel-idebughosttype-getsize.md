# IDebugHostType::GetSize

## Description

The GetSize method returns the size of the type (as if one had done sizeof(type) in C++).

## Parameters

### `size`

The size of the type will be returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHostType> spType; /* get a type (see FindTypeByName) */

ULONG64 size;
if (SUCCEEDED(spType->GetSize(&size)))
{
    // size is equivalent to sizeof( <type> )
}
```

## See also

[IDebugHostType interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype)