# IWDTFSimpleIOStressAction2::Pause

## Description

Pauses the I/O.

## Parameters

### `pResult` [out, retval]

True if the I/O operation after the last
[Start](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintschemaasyncoperation-start) or
[Continue](https://learn.microsoft.com/windows-hardware/drivers/ddi/) succeeded;
otherwise, false.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWDTFSimpleIOStressAction2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtfinterfaces/nn-wdtfinterfaces-iwdtfsimpleiostressaction2)