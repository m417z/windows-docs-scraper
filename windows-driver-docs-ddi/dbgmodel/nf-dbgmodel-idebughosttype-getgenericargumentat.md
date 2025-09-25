# IDebugHostType::GetGenericArgumentAt

## Description

For the "i"-th generic argument to the generic/template, this returns a new [IDebugHostSymbol](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostsymbol) which represents that argument. For templates, this is most often an [IDebugHostType](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype); however -- it may be an [IDebugHostConstant](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostconstant) for non-template type arguments.

Note that it is possible for some compiler generated generics and templates that this method will fail.

## Parameters

### `i`

The zero based index of the generic argument to returned.

### `argument`

The i’th generic argument of the type will be returned here

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDebugHostType interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype)