# IDebugHostConstant::GetValue

## Description

The GetValue method returns the value of the constant packed into a VARIANT.

It is important to note that the GetType method on [IDebugHostSymbol](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostsymbol) may return a specific type symbol for the constant. In such cases, there is no guarantee that the packing of the constant value as defined by the type symbol is the same as the packing as returned by the GetValue method here.

## Parameters

### `value`

The value of the data packed into a VARIANT will be returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHostConstant> spConstant; /* get a constant */

VARIANT vtValue;
if (SUCCEEDED(spConstant->GetValue(&vtValue)))
{
    // vtValue contains the value of the constant.  The variant type of vtValue
    // may not match what the type indicates if you get the type of the symbol.
    VariantClear(&vtValue);
}
```

## See also

[IDebugHostConstant interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostconstant)