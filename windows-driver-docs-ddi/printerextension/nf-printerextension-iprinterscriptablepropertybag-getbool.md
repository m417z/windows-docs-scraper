## Description

Gets a specified boolean property.

## Parameters

### `bstrName` [in]

The name of the property.

### `pbValue` [out, retval]

The returned property value.

## Return value

This method returns an **HRESULT** value.

## Remarks

A call to **GetBool** will throw an exception, if the specified property is not found. We recommend that you use a try-catch statement around calls to this method, to allow your app to handle any failures gracefully.

## See also

[IPrinterScriptablePropertyBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterscriptablepropertybag)