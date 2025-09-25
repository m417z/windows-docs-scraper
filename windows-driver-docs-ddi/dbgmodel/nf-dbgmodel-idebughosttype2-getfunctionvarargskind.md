# IDebugHostType2::GetFunctionVarArgsKind

## Description

The GetFunctionVarArgsKind method returns whether a given function utilizes a variable argument list, and if so, what style of variable arguments it utilizes. Such is defined by a member of the [VarArgsKind enumeration](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/ne-dbgmodel-varargskind) defined as follows:

|Enumerant | Meaning|
|---------|---------|
|VarArgsNone | The function does not take any variable arguments.|
|VarArgsCStyle | The function is a C-style varargs function (returnType(arg1, arg2, ...)). The number of arguments reported by the function does not include the ellipsis argument. Any variable argument passing occurs after the number of arguments returned by the [GetFunctionParameterTypeCount method](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nf-dbgmodel-idebughosttype2-getfunctionparametertypecount).|

## Parameters

### `varArgsKind`

A value of the VarArgsKind enumeration indicating whether the function is a varargs function and, if so, what style of variable arguments it utilizes.

## Return value

This method returns HRESULT that indicates success or failure. This method will not fail on a non varargs function.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHostType> spType; /* get a type for a function (see FindTypeByName) */

ComPtr<IDebugHostType2> spType2;
if (SUCCEEDED(spType.As(&spType2)))
{
    VarArgsKind vaKind;
    if (SUCCEEDED(spType->GetFunctionVarArgsKind(&vaKind)))
    {
        // vaKind indicates whether the function is varargs and, if so, what
        // style of varargs the function utilizes.
    }
}
```

## See also

[IDebugHostType2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype2)