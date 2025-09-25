# IWDTFSystemAction2::ConnectedStandby

## Description

Puts the system into Connected Standby state and
exits Connected Standby state after the desired time has passed. This method
only works on a computer that supports Always On Always Connected (AOAC).

## Parameters

### `TimeInMs` [in]

Specifies how much time (in milliseconds) has to pass
before exiting Connected Standby.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWDTFSystemAction2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtfsystemaction/nn-wdtfsystemaction-iwdtfsystemaction2)