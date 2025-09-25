# PFND3DDDICB_LOGSTRINGTABLEENTRY callback function

## Description

Locates a string table entry that is used by the [LogMarkerStringTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_logstringtable) function to log an Event Tracing for Windows (ETW) marker event. Optionally implemented by Windows Display Driver Model (WDDM) 1.3 and later drivers.

## Parameters

### `hLog`

A handle to the ETW log that is to be written to. Must be the same *hLog* handle passed to the [LogMarkerStringTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_logstringtable) function.

### `StringIndex`

The offset, in bytes, of the string table entry pointed to by **Info**. Can be negative if the string is passed along with the marker event.

### `Info`

A custom text string embedded in the ETW packet. Can be **NULL**.

## Return value

 Returns **S_OK** or an appropriate error result if the function does not complete successfully.

## See also

[LogMarkerStringTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_logstringtable)