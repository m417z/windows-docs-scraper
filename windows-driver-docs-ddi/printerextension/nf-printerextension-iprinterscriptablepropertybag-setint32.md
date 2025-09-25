## Description

Writes an integer property.

## Parameters

### `bstrName` [in]

The property to set.

### `nValue` [in]

The new value to set.

## Return value

This method returns an **HRESULT** value.

## Remarks

A call to **SetInt32** will throw an exception, if the specified property is not found. We recommend that you use a try-catch statement around calls to this method, to allow your app to handle any failures gracefully.

## See also

[IPrinterScriptablePropertyBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterscriptablepropertybag)