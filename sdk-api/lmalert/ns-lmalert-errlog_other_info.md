# ERRLOG_OTHER_INFO structure

## Description

The
**ERRLOG_OTHER_INFO** structure contains error log information. The
[NetAlertRaise](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraise) and
[NetAlertRaiseEx](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraiseex) functions use the
**ERRLOG_OTHER_INFO** structure to specify information when adding a new entry to the error log.

## Members

### `alrter_errcode`

Specifies the error code that was written to the error log.

### `alrter_offset`

Specifies the offset for the new entry in the error log.

## Remarks

The calling application must allocate and free the memory for all structures and variable-length data in an alert message buffer.

## See also

[ADMIN_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-admin_other_info)

[Alert Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/alert-functions)

[NetAlertRaise](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraise)

[NetAlertRaiseEx](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraiseex)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[PRINT_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-print_other_info)

[STD_ALERT](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-std_alert)

[USER_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-user_other_info)