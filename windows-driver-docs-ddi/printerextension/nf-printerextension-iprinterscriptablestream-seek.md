## Description

Sets the seek pointer.

## Parameters

### `lOffset` [in]

The displacement to be added to the location indicated by the *streamSeek* parameter.

### `streamSeek` [in]

The origin for the displacement specified *lOffset*.

### `plPosition` [out, retval]

The new pointer position.

## Return value

This method returns an **HRESULT** value.

## See also

[IPrinterScriptableStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterscriptablestream)