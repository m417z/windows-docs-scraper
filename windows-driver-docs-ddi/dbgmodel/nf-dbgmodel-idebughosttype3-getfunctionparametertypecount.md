## Description

The GetFunctionParameterTypeCount method returns the number of arguments that the function takes.

Note that the C/C++ ellipsis based variable argument marker is not considered in this count. The presence of such must be detected via the [GetFunctionVarArgsKind method](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nf-dbgmodel-idebughosttype3-getfunctionvarargskind). This will only include arguments before the ellipsis.

## Parameters

### `count`

The number of arguments to the function (ignoring the variable argument ellipsis) will be returned here. The types of each individual argument may be acquired via the [GetFunctionParameterTypeAt method](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nf-dbgmodel-idebughosttype3-getfunctionparametertypeat).

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHostType> spType; /* get a type for a function (see FindTypeByName) */

ULONG64 count;
if (SUCCEEDED(spType->GetFunctionParameterTypeCount(&count)))
{
    // count is the number of parameters the function takes.  This does not
    // include any ellipsis for variable arguments.
}
```

## See also

[IDebugHostType3 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype3)