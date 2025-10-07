# ExpertIndicateStatus function

The **ExpertIndicateStatus** function indicates the percentage of completion of the expert's analysis of the capture file.

## Parameters

*hExpertKey* \[in\]

Unique expert identifier. Network Monitor passes *hExpertKey* to the expert when it calls the [Run](https://learn.microsoft.com/windows/win32/netmon2/run) function.

*Status* \[in\]

Current status of the analysis. Specify one of the following [EXPERTSTATUSENUMERATION](https://learn.microsoft.com/windows/win32/netmon2/expertstatusenumeration) values.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------|
| **EXPERTSTATUS\_INACTIVE** | The expert never started. <br> |
| **EXPERTSTATUS\_STARTING** | The expert is starting. <br> |
| **EXPERTSTATUS\_RUNNING** | The expert is running normally. <br> |
| **EXPERTSTATUS\_PROBLEM** | A problem specified in the SubStatus parameter stopped the expert. <br> |
| **EXPERTSTATUS\_ABORTED** | Network Monitor stopped the expert. <br> |
| **EXPERTSTATUS\_DONE** | The expert finished the analysis successfully. <br> |

*SubStatus* \[in\]

Extension or clarification of information provided by the *Status* parameter.

*sztext* \[in\]

Optional text status indicator.

This parameter value may be **NULL**.

*PercentDone* \[out\]

Percentage of the capture data that the expert has processed.

When the expert successfully completes analysis of a capture file, the system sets the percentage to 100. Any number greater than 99 will be ignored.

## Return value

If the function is successful, the return value is NMERR\_SUCCESS.

If the function is unsuccessful, the return value is NMERR\_EXPERT\_TERMINATE; the expert must immediately clean up and return without completing the capture.

## Remarks

The **ExpertIndicateStatus** function can only be called by experts that implement the [Run](https://learn.microsoft.com/windows/win32/netmon2/run) or [Configure](https://learn.microsoft.com/windows/win32/netmon2/configure) export function.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |