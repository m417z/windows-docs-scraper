# FAX_JOB_STATUS_ENUM enumeration

## Description

The **FAX_JOB_STATUS_ENUM** enumeration defines the status values for a fax job.

**Note** The members **fjsPAUSED** and **fjsNOLINE** are modifiers; they can be used in combination with any other member of this enumeration. Other members cannot be used as modifiers.

## Constants

### `fjsPENDING:0x1`

The fax job is in the queue and pending service.

### `fjsINPROGRESS:0x2`

The fax job is in progress.

### `fjsFAILED:0x8`

The fax job failed.

### `fjsPAUSED:0x10`

The fax server paused the fax job. This value can arrive in a bitwise combination with another value.

### `fjsNOLINE:0x20`

There is no line available to send the fax. The fax server will send the transmission when a line is available. This value can arrive in a bitwise combination with another value.

### `fjsRETRYING:0x40`

The fax job failed. The fax server will attempt to retransmit the fax after a specified interval.

### `fjsRETRIES_EXCEEDED:0x80`

The fax server exceeded the maximum number of retransmission attempts allowed. The fax will not be sent.

### `fjsCOMPLETED:0x100`

The fax job is completed.

### `fjsCANCELED:0x200`

The fax job was canceled.

### `fjsCANCELING:0x400`

The fax job is being canceled.

### `fjsROUTING:0x800`

The fax job is being routed.

## See also

[IFaxJobStatus::get_Status](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxjobstatus-status-vb)

[IFaxOutgoingJob::get_Status](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingjob-status-vb)

[Status](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingjob-status)