# STD_ALERT structure

## Description

The
**STD_ALERT** structure contains the time and date when a significant event occurred. The structure also contains an alert class and the name of the application that is raising the alert message. You must specify the
**STD_ALERT** structure when you send an alert message using the
[NetAlertRaise](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraise) function.

## Members

### `alrt_timestamp`

Type: **DWORD**

The time and date of the event. This value is stored as the number of seconds that have elapsed since 00:00:00, January 1, 1970, GMT.

### `alrt_eventname`

Type: **WCHAR[EVLEN + 1]**

A Unicode string indicating the alert class (type of event). This parameter can be one of the following predefined values, or another alert class that you have defined for network applications. (The event name for an alert can be any text string.)

| Name | Meaning |
| --- | --- |
| **ALERT_ADMIN_EVENT** | An administrator's intervention is required. |
| **ALERT_ERRORLOG_EVENT** | An entry was added to the error log. |
| **ALERT_MESSAGE_EVENT** | A user or application received a broadcast message. |
| **ALERT_PRINT_EVENT** | A print job completed or a print error occurred. |
| **ALERT_USER_EVENT** | An application or resource was used. |

### `alrt_servicename`

Type: **WCHAR[SNLEN + 1]**

A Unicode string indicating the service application that is raising the alert message.

## Remarks

The
**STD_ALERT** structure must be followed by one
[ADMIN_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-admin_other_info),
[ERRLOG_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-errlog_other_info),
[PRINT_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-print_other_info), or
[USER_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-user_other_info) structure. These structures can optionally be followed by variable-length data. The calling application must allocate the memory for all structures and variable-length data in an alert message buffer.

See
[NetAlertRaise](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraise) for a code sample that raises an administrative alert using a
**STD_ALERT** structure and an
[ADMIN_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-admin_other_info) structure.

## See also

[ADMIN_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-admin_other_info)

[Alert Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/alert-functions)

[ERRLOG_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-errlog_other_info)

[NetAlertRaise](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraise)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[PRINT_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-print_other_info)

[USER_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-user_other_info)