# ITraceRelogger::SetOutputFilename

## Description

The **SetOutputFilename** method indicates the file to which ETW should write the new, relogged trace.

## Parameters

### `LogfileName` [in]

Type: **BSTR**

The new filename.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the indicated file already exists, it will be overwritten with the new trace.

## See also

[ITraceRelogger](https://learn.microsoft.com/windows/desktop/api/relogger/nn-relogger-itracerelogger)