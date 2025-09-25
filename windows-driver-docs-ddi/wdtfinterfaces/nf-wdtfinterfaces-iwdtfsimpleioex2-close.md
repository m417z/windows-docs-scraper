# IWDTFSimpleIOEx2::Close

## Description

Closes the device.

## Parameters

### `pResult` [out, retval]

True if the operation succeeds; otherwise, false.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You should call the **Close** method only after calling
the [IWDTFSimpleIOEx2::Open](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtfinterfaces/nf-wdtfinterfaces-iwdtfsimpleioex2-open) method.

## See also

[IWDTFSimpleIOEx2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtfinterfaces/nn-wdtfinterfaces-iwdtfsimpleioex2)