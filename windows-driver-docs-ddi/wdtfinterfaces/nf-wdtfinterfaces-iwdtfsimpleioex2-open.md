# IWDTFSimpleIOEx2::Open

## Description

Opens the device.

## Parameters

### `pResult` [out, retval]

True if the operation succeeds; otherwise, false.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You should call the **Open** method before calling
the [IWDTFSimpleIOEx2::PerformIO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtfinterfaces/nf-wdtfinterfaces-iwdtfsimpleioex2-performio) method.

## See also

[IWDTFSimpleIOEx2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtfinterfaces/nn-wdtfinterfaces-iwdtfsimpleioex2)