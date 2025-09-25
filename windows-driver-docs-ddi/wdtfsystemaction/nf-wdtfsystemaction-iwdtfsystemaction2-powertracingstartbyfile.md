# IWDTFSystemAction2::PowerTracingStartByFile

## Description

Starts a trace session for power state transitions and saves the trace message file (.etl) using the specified path. This method is available starting with Windows 8.

## Parameters

### `EventFilePath` [in]

Specifies the location to store the trace message (.etl) log file.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWDTFSystemAction2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtfsystemaction/nn-wdtfsystemaction-iwdtfsystemaction2)