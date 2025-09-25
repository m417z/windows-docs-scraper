## Description

This enumeration is a one-to-one mapping to the spooler flags supplied in the JOB_INFO_X structures.

For example, [JOB_INFO_1](https://learn.microsoft.com/windows/win32/printdocs/job-info-1) has the same set of status flags as shown in the following list.

## Constants

### `PrintJobStatus_Paused`

The job is paused.

### `PrintJobStatus_Error`

There is an error associated with the job.

### `PrintJobStatus_Deleting`

The job is being deleted.

### `PrintJobStatus_Spooling`

The job is spooling.

### `PrintJobStatus_Printing`

The job is printing.

### `PrintJobStatus_Offline`

The printer is offline.

### `PrintJobStatus_PaperOut`

The printer is out of paper.

### `PrintJobStatus_Printed`

The job printing is completed.

### `PrintJobStatus_Deleted`

The job has been deleted.

### `PrintJobStatus_BlockedDeviceQueue`

The driver cannot print the job.

### `PrintJobStatus_UserIntervention`

The printer has an error that requires intervention from the user.

### `PrintJobStatus_Restarted`

The job has been restarted.

### `PrintJobStatus_Complete`

The job data transfer to the printer is complete. Note that the printing of the job may not yet be complete.

### `PrintJobStatus_Retained`

The job has been retained in the print queue and cannot be deleted.

## Remarks

A **PrintJobStatus_Retained** flag can be raised for several reasons. For example, jobs could be kept in the queue if the administrator of the queue used the desktop print queue UI to set the "Keep Printed Jobs" feature to be on.

It is possible for a job to have multiple flag values specified simultaneously.

## See also

[IPrintJob::Status](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintjob-get_status)

[JOB_INFO_1](https://learn.microsoft.com/windows/win32/printdocs/job-info-1)