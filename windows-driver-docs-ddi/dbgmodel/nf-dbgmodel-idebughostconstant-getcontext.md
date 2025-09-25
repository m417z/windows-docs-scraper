# IDebugHostConstant::GetContext

## Description

The GetContext method returns the context where the symbol is valid. While this will represent things such as the debug target and process/address space in which the symbol exists, it may not be as specific as a context retrieved from other means (e.g.: from an [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)).

## Parameters

### `context`

The host context in which the symbol is located will be returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Code Sample**

```cpp
ComPtr<IDebugHostSymbol> spSymbol; /* get a symbol */

ComPtr<IDebugHostContext> spContext;
if (SUCCEEDED(spSymbol->GetContext(&spContext)))
{
    // spContext will contain the context that the symbol is within
    // (e.g.: session, process)
}
```

## See also

[IDebugHostConstant interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostconstant)