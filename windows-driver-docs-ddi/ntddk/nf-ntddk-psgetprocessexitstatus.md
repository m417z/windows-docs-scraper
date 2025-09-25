## Description

This routine retrieves the exit status of a process.

## Parameters

### `Process` [in]

A pointer to the EPROCESS structure that represents the process. Drivers can use the [**PsGetCurrentProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetcurrentprocess) and [**ObReferenceObjectByHandle**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle) routines to obtain a pointer to the EPROCESS structure for a process.

## Return value

Returns the exit status of the supplied EPROCESS.

## Remarks

A driver might call PsGetProcessExitStatus in the following scenarios: monitoring process termination to obtain information about whether a process terminated normally or due to an error, resource cleanup to determine when and how to clean up resources allocated on behalf of a process, and error reporting and logging to provide more detailed information about process terminations.

## See also