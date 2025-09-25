# PRINT_OTHER_INFO structure

## Description

The
**PRINT_OTHER_INFO** structure contains information about a print job. The
[NetAlertRaise](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraise) and
[NetAlertRaiseEx](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraiseex) functions use the
**PRINT_OTHER_INFO** structure to specify information when a job has finished printing, or when a printer needs intervention.

## Members

### `alrtpr_jobid`

Type: **DWORD**

The identification number of the print job.

### `alrtpr_status`

Type: **DWORD**

A bitmask describing the status of the print job.

You can obtain the overall status of the job by checking PRJOB_QSTATUS (bits 0 and 1).

Possible values for the print job status are listed in the *Lmalert.h* header file.

| Value | Meaning |
| --- | --- |
| **PRJOB_QS_QUEUED**<br><br>0 | The print job is in the queue waiting to be scheduled. |
| **PRJOB_QS_PAUSED**<br><br>1 | The print job is in the queue, but it has been paused. (When a job is paused, it cannot be scheduled.) |
| **PRJOB_QS_SPOOLING**<br><br>2 | The print job is in the process of being spooled. |
| **PRJOB_QS_PRINTING**<br><br>3 | The job is currently printing. |

If the print job is in the PRJOB_QS_PRINTING state, you can check bits 2 through 8 for the device's status (PRJOB_DEVSTATUS). Bit 15 is also meaningful.

Possible values for the device's status are listed in the *Lmalert.h* header file.

| Value | Meaning |
| --- | --- |
| **PRJOB_COMPLETE**<br><br>0x4 | The job has completed printing. |
| **PRJOB_INTERV**<br><br>0x8 | The destination printer requires an operator's intervention. |
| **PRJOB_ERROR**<br><br>0x10 | There is an error at the destination printer. |
| **PRJOB_DESTOFFLINE**<br><br>0x20 | The destination printer is offline. |
| **PRJOB_DESTPAUSED**<br><br>0x40 | The destination printer is paused. |
| **PRJOB_NOTIFY**<br><br>0x80 | A printing alert should be raised. |
| **PRJOB_DESTNOPAPER**<br><br>0x100 | The destination printer is out of paper. |
| **PRJOB_DELETED**<br><br>0x8000 | The printing job is being deleted. |

### `alrtpr_submitted`

Type: **DWORD**

The time at which the print job was submitted. This value is stored as the number of seconds that have elapsed since 00:00:00, January 1, 1970, GMT.

### `alrtpr_size`

Type: **DWORD**

The size, in bytes, of the print job.

## Remarks

Additional variable-length data follows the
**PRINT_OTHER_INFO** structure in the alert message buffer. The information is in the form of contiguous null-terminated character strings, as follows.

| String | Meaning |
| --- | --- |
| computername | The computer that submitted the print job. |
| username | The user who submitted the print job. |
| queuename | The print queue to which the job was submitted. |
| destination | The printer destination (device) to which the print job was routed. |
| status | The status of the print job. |

The calling application must allocate and free the memory for all structures and variable-length data in an alert message buffer.

See
[NetAlertRaiseEx](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraiseex) for a code sample that demonstrates how to raise a print alert.

## See also

[ADMIN_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-admin_other_info)

[Alert Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/alert-functions)

[ERRLOG_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-errlog_other_info)

[NetAlertRaise](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraise)

[NetAlertRaiseEx](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraiseex)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[STD_ALERT](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-std_alert)

[USER_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-user_other_info)