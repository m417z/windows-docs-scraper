# IWDTFSystemAction2::get_IsRestarted

## Description

Gets a value that indicates whether the test script restarted as a result of a call to [RebootRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtfsystemaction/nf-wdtfsystemaction-iwdtfsystemaction2-rebootrestart) or [RebootRestartWithContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtfsystemaction/nf-wdtfsystemaction-iwdtfsystemaction2-rebootrestartwithcontext).

This property is read-only.

## Parameters

### `pbIsRestarted`

A value that indicates whether the system is restarted.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWDTFSystemAction2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtfsystemaction/nn-wdtfsystemaction-iwdtfsystemaction2)