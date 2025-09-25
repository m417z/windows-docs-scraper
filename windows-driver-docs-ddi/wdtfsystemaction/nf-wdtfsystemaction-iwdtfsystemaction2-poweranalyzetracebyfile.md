# IWDTFSystemAction2::PowerAnalyzeTraceByFile

## Description

Analyzes a power trace session that has already been collected and stored in the associated trace message (.etl) log file. This method will only
work on Windows 8 and above.

## Parameters

### `EventFilePath` [in]

Specifies the location to store the trace message (.etl)
log file.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWDTFSystemAction2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtfsystemaction/nn-wdtfsystemaction-iwdtfsystemaction2)