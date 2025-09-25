## Description

Provides access to the user property bag, if the property bag is present.

This property is read-only.

## Parameters

### `ppPropertyBag`

Defines the **IPrinterScriptablePropertyBag** parameter *ppPropertyBag*.

## Return value

Returns an **HRESULT** value. If the property call was not successful, it returns the appropriate **HRESULT** error code.

## Remarks

The user property bag is not available in (constraint) JavaScript functions when the functions are called during de-spooling. Therefore JavaScript functions should be designed to handle the situation when there is a failure to retrieve the user property bag.

Although the **UserProperties** property is read-only, the user property bag is a read/write property bag.

## See also

[IPrinterScriptContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterscriptcontext)

[IPrinterScriptablePropertyBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterscriptablepropertybag)