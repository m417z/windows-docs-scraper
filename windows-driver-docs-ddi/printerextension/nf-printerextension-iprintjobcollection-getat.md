## Description

Gets a pointer to an [IPrintJob](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintjob) object.

## Parameters

### `ulIndex` [in]

Index of the **IPrintJob** object within the collection.

### `ppJob` [out, retval]

Pointer to an **IPrintJob** object.

## Return value

Returns an **HRESULT** value. If the method call was not successful, it returns the appropriate **HRESULT** error code.

## See also

[IPrintJob](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintjob)

[IPrintJobCollection](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintjobcollection)