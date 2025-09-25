# ALERT_OTHER_INFO macro

## Syntax

```cpp
LPBYTE ALERT_OTHER_INFO(
    LPBYTE x
);
```

## Return value

Type: **LPBYTE**

The return value is a pointer to the fixed-length structure that follows the [STD_ALERT](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-std_alert) structure in the alert message.

## Description

The **ALERT_OTHER_INFO** macro returns a pointer to the alert-specific data in an alert message. The data follows a [STD_ALERT](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-std_alert) structure, and can be an [ADMIN_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-admin_other_info), a [PRINT_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-print_other_info), or a [USER_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-user_other_info) structure.

## Parameters

### `x`

Pointer to a **STD_ALERT** structure that was specified in a call to the [NetAlertRaise](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraise) function.

## Remarks

The
**ALERT_OTHER_INFO** macro is defined as follows:

```cpp
#include <windows.h>

#define ALERT_OTHER_INFO(x)    ((LPBYTE)(x) + sizeof(STD_ALERT))

```

See [NetAlertRaise](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraise) for a code sample that uses the **ALERT_OTHER_INFO** macro to retrieve a pointer to the **ADMIN_OTHER_INFO** structure.

## See also

[ADMIN_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-admin_other_info)

[ALERT_VAR_DATA](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-alert_var_data)

[Alert Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/alert-functions)

[NetAlertRaise](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraise)

[Network
Management Macros](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-macros)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[PRINT_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-print_other_info)

[STD_ALERT](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-std_alert)

[USER_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-user_other_info)