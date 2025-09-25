## Description

Gets a read stream and uses it to read from a property.

## Parameters

### `bstrName` [in]

The property to read.

### `ppStream` [out, retval]

The returned stream.

## Return value

This method returns an **HRESULT** value.

## Remarks

**GetReadStream** does not work with non-stream properties.

A call to **GetReadStream** will throw an exception, if the specified property is not found. We recommend that you use a try-catch statement around calls to this method, to allow your app to handle any failures gracefully.

## See also

[IPrinterScriptablePropertyBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterscriptablepropertybag)

[IPrinterScriptableStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterscriptablestream)