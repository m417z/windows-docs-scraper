## Description

The GetInlinedFunction method retrieves a symbol for the inlined function that the local variable is contained within, if [IsInlineScope()](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nf-dbgmodel-idebughostfunctionlocaldetails2-isinlinescope) returns true.

## Parameters

### `inlineFunction`

A pointer to a pointer variable that receives the [IDebugHostSymbol interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostsymbol) of the inlined function.

## Return value

If the method succeeds and the local is within an inlined scope, it returns S_OK and a pointer to the inlined function symbol. If the local is not within an inlined scope, it returns an E_FAIL. Otherwise, it returns an HRESULT error code.

## Remarks

## See also

[IDebugHostFunctionLocalDetails2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostfunctionlocaldetails2)