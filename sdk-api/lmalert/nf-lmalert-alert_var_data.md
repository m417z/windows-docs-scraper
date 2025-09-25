# ALERT_VAR_DATA macro

## Syntax

```cpp
LPBYTE ALERT_VAR_DATA(
    LPBYTE p
);
```

## Return value

Type: **LPBYTE**

The return value is a pointer to the variable-length data that follows the fixed-length structure in the alert message.

## Description

The **ALERT_VAR_DATA** macro returns a pointer to the variable-length portion of an alert message. Variable-length data can follow an [ADMIN_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-admin_other_info), a [PRINT_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-print_other_info), or a [USER_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-user_other_info) structure.

## Parameters

### `p`

Pointer to an **ADMIN_OTHER_INFO**, a **PRINT_OTHER_INFO**, or a **USER_OTHER_INFO** structure that was specified in a call to the [NetAlertRaise](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraise) function or the [NetAlertRaiseEx](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraiseex) function.

## Remarks

The
**ALERT_VAR_DATA** macro is defined as follows:

```cpp
#include <windows.h>

#define ALERT_VAR_DATA(p)      ((LPBYTE)(p) + sizeof(*p))

```

See [NetAlertRaise](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraise) and [NetAlertRaiseEx](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraiseex) for code samples that use the **ALERT_VAR_DATA** macro to retrieve a pointer to the variable-length data in an alert message.

## See also

[ADMIN_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-admin_other_info)

[ALERT_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-alert_other_info)

[Alert Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/alert-functions)

[NetAlertRaise](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraise)

[NetAlertRaiseEx](https://learn.microsoft.com/windows/desktop/api/lmalert/nf-lmalert-netalertraiseex)

[Network
Management Macros](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-macros)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[PRINT_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-print_other_info)

[USER_OTHER_INFO](https://learn.microsoft.com/windows/desktop/api/lmalert/ns-lmalert-user_other_info)