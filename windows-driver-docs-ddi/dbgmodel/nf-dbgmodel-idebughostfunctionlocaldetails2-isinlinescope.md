## Description

The IsInlineScope method determines if the local variable is scoped within an inlined function. This will always return false unless the [EnumerateLocalsDetailsEx method](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nf-dbgmodel-idebughostfunctionintrospection3-enumeratelocalsdetailsex) is called with 'enumerateInlinedLocals' set to true.

## Return value

Returns a boolean value. If the local variable is scoped within an inlined function, it returns true. Otherwise, it returns false.

## Remarks

## See also

[IDebugHostFunctionLocalDetails2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostfunctionlocaldetails2)