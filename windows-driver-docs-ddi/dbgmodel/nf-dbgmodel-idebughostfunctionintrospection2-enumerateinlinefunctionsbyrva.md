## Description

The EnumerateInlineFunctionsByRVA method enumerates the functions that are inlined at a specific Relative Virtual Address (RVA). The functions are enumerated from the innermost containing inline function to the outermost.

## Parameters

### `rva`

A ULONG64 value that specifies the Relative Virtual Address.

### `inlinesEnum`

A pointer to a pointer variable that receives the IDebugHostSymbolEnumerator interface of the enumerated inlined functions.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

This method is used when you need to inspect the inlined functions at a specific address in a program. It lists the functions from innermost to outermost.

**Sample Code**

```cpp
void Function1() {...};
void Function2()
{
    ...
    Function1();  // inlined
    ...
}
void Function3()
{
    ...
    Function2();  // inlined
    ...
}
```
This method will enumerate Function1, followed by Function2, when called on an RVA inlined for Function1, and will enumerate only Function2 when called on an RVA inlined for Function2.

## See also

[IDebugHostFunctionIntrospection2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostfunctionintrospection2)