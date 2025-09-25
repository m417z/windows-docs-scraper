# NdfGetTraceFile function

## Description

The **NdfGetTraceFile** function is used to retrieve the path containing an Event Trace Log (ETL) file that contains Event Tracing for Windows (ETW) events from a diagnostic session.

## Parameters

### `Handle` [in]

Type: **NDFHANDLE**

Handle to a Network Diagnostics Framework incident. This handle should match the handle of an existing incident.

### `TraceFileLocation` [out]

Type: **LPCWSTR***

The location of the trace file.

## Return value

Type: **HRESULT**

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |

 Any result other than S_OK should be interpreted as an error.

## Remarks

This function cannot be called on an incident which has already been closed.

ETL files contain information such as which components were diagnosed, component configuration information, and diagnosis results. For more information about ETL files, see [Network Tracing in Windows 7](https://learn.microsoft.com/windows/desktop/NDF/network-tracing-in-windows-7).