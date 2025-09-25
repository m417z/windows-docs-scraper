## Description

Reads a byte array property.

The [IPrinterPropertyBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterpropertybag) interface is used by all the printer property bags, including driver property bag, user property bag, queue property bag, and DEVMODE property bag.

## Parameters

### `bstrName` [in]

The property to read.

### `pcbValue` [out]

The number of bytes read.

### `ppValue`

The returned array. This array must be freed by using CoTaskFree.

## Return value

This method returns an **HRESULT** value.

## See also

[IPrinterPropertyBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterpropertybag)