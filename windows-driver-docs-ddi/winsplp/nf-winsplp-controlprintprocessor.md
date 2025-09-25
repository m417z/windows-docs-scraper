## Description

A print processor's **ControlPrintProcessor** function allows the spooler to control a print job.

## Parameters

### `hPrintProcessor` [in]

Caller-supplied print processor handle. This is the handle returned by a previous call to [OpenPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-openprintprocessor).

### `Command` [in]

Caller-supplied command indicating the type of operation to perform. The following commands are valid:

| Command | Definition |
|---|---|
| JOB_CONTROL_CANCEL | The function should cancel the current print job. |
| JOB_CONTROL_PAUSE | The function should pause the current print job. |
| JOB_CONTROL_RESUME | The function should resume the current print job. |

## Return value

If the operation succeeds, the function should return **TRUE**. If the operation fails, the function should call SetLastError to set an error code, and then return **FALSE**.

## Remarks

Print processors are required to export a **ControlPrintProcessor** function. The spooler calls the function when an application calls the SetJob function, described in the Microsoft Windows SDK documentation.

Based on the value received for *Command*, the function should either pause, resume, or cancel the current job. The **ControlPrintProcessor** function can be called asynchronously while the print processor's [PrintDocumentOnPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-printdocumentonprintprocessor) function is executing. Thus some sort of synchronization technique must be employed, such as setting an internally-defined event object to pause a job and resetting the event object when the job is resumed. The **ControlPrintProcessor** function can quickly return after setting or resetting the event object, and PrintDocumentOnPrintProcessor can wait for the event to be in the proper state.

## See also

[OpenPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-openprintprocessor)

[PrintDocumentOnPrintProcessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-printdocumentonprintprocessor)