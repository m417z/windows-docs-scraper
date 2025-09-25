# FAX_JOB_TYPE_ENUM enumeration

## Description

The **FAX_JOB_TYPE_ENUM** enumeration defines the fax job type.

## Constants

### `fjtSEND:0`

The job is an outbound job.

### `fjtRECEIVE`

The job is an incoming job (being received through a modem).

### `fjtROUTING`

The incoming job has been received, and is now in routing mode (modem is not used).

## See also

[IFaxJobStatus::get_JobType](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxjobstatus-jobtype-vb)