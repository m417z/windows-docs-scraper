# ADMIN_OTHER_INFO structure

## Description

The
**ADMIN_OTHER_INFO** structure contains error message information. The
[NetAlertRaise](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraise) and
[NetAlertRaiseEx](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraiseex) functions use the
**ADMIN_OTHER_INFO** structure to specify information when raising an administrator's interrupting message.

## Members

### `alrtad_errcode`

Specifies the error code for the new message written to the message log.

### `alrtad_numstrings`

Specifies the number (0-9) of consecutive Unicode strings written to the message log.

## Remarks

Variable-length data follows the
**ADMIN_OTHER_INFO** structure in the alert message buffer if you specify one or more strings in the **alrtad_numstrings** member. The calling application must allocate and free the memory for all structures and variable-length data in an alert message buffer.

See
[NetAlertRaise](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraise) and
[NetAlertRaiseEx](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraiseex) for code samples that demonstrate how to raise an administrative alert.

## See also

[Alert Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/alert-functions)

[ERRLOG_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-errlog_other_info)

[NetAlertRaise](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraise)

[NetAlertRaiseEx](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraiseex)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[PRINT_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-print_other_info)

[STD_ALERT](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-std_alert)

[USER_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-user_other_info)