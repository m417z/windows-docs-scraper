# USER_OTHER_INFO structure

## Description

The
**USER_OTHER_INFO** structure contains user error code information. The
[NetAlertRaise](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraise) and
[NetAlertRaiseEx](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraiseex) functions use the
**USER_OTHER_INFO** structure to specify information about an event or condition of interest to a user.

## Members

### `alrtus_errcode`

Specifies the error code for the new message in the message log.

### `alrtus_numstrings`

Specifies the number (0-9) of consecutive Unicode strings in the message log.

## Remarks

Additional variable-length data follows the
**USER_OTHER_INFO** structure in the alert message buffer. The information is in the form of contiguous null-terminated character strings, as follows.

| String | Meaning |
| --- | --- |
| username | The user who created the session. |
| computername | The computer that created the session. |

The calling application must allocate and free the memory for all structures and variable-length data in an alert message buffer.

See
[NetAlertRaiseEx](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraiseex) for a code sample that demonstrates how to raise a user alert.

## See also

[ADMIN_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-admin_other_info)

[Alert Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/alert-functions)

[ERRLOG_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-errlog_other_info)

[NetAlertRaise](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraise)

[NetAlertRaiseEx](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraiseex)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[PRINT_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-print_other_info)

[STD_ALERT](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-std_alert)