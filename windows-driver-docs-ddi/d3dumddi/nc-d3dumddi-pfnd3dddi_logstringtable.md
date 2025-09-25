# PFND3DDDI_LOGSTRINGTABLE callback function

## Description

Called by the Microsoft Direct3D runtime to request that the user-mode display driver log a custom Event Tracing for Windows (ETW) marker event. Optionally implemented by Windows Display Driver Model (WDDM) 1.3 and later drivers.

## Parameters

### `hLog`

A handle to the Event Tracing for Windows (ETW) log that is to be written to.

### `pfnLogStringTableEntryCb`

A function pointer to the [LogMarkerStringTableEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddicb_logstringtableentry) function that locates a string table entry.

## Return value

 Returns **S_OK** or an appropriate error result if the function does not complete successfully.

## Remarks

This function is free-threaded.

## See also

[LogMarkerStringTableEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddicb_logstringtableentry)