# FAX_JOB_OPERATIONS_ENUM enumeration

## Description

The **FAX_JOB_OPERATIONS_ENUM** enumeration defines the operations that can be performed on a fax job. The members of this enumeration are bit values and can be used in combination.

## Constants

### `fjoVIEW:0x1`

The job's TIFF image can be retrieved.

### `fjoPAUSE:0x2`

The job can be paused.

### `fjoRESUME:0x4`

The job can be resumed.

### `fjoRESTART:0x8`

The job can be restarted.

### `fjoDELETE:0x10`

The job can be deleted.

### `fjoRECIPIENT_INFO:0x20`

The job's recipient information can be retrieved.

### `fjoSENDER_INFO:0x40`

The job's sender information can be retrieved.

## See also

[AvailableOperations](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingjob-availableoperations)

[IFaxJobStatus::get_AvailableOperations](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxjobstatus-availableoperations-vb)

[IFaxOutgoingJob::get_AvailableOperations](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingjob-availableoperations-vb)