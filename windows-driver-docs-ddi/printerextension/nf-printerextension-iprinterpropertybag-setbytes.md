## Description

Writes a byte array property.

## Parameters

### `bstrName` [in]

The array to write to.

### `cbValue` [in]

The number of bytes to write.

### `pValue`

The values to write.

## Return value

This method returns an **HRESULT** value.

## Remarks

In Windows 8.1 a new flag, PRINTER_ACCESS_MANAGE_LIMITED, has been introduced to grant print queue permissions that are more limited than PRINTER_ACCESS_ADMINISTER, but more powerful than
PRINTER_ACCESS_USE.

The permissions are a subset of those associated with PRINTER_ACCESS_ADMINISTER. This means that if the currently logged-on user has PRINTER_ACCESS_ADMINISTER permission, the user can gain
PRINTER_ACCESS_MANAGE_LIMITED access to the queue.

A call to set a property on a queue property bag will fail with ERROR_ACCESS_DENIED, if the user does not have the appropriate permission. This behavior was true before PRINTER_ACCESS_MANAGE_LIMITED was introduced, and it's still the current behavior.

## See also

[IPrinterPropertyBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterpropertybag)