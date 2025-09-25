## Description

Writes a specified boolean property value.

## Parameters

### `bstrName` [in]

The property to set.

### `bValue` [in]

The value to set.

## Return value

This method returns an **HRESULT** value.

## Remarks

A call to **SetBool** will throw an exception, if the specified property is not found. We recommend that you use a try-catch statement around calls to this method, to allow your app to handle any failures gracefully.

## See also

[IPrinterScriptablePropertyBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterscriptablepropertybag)