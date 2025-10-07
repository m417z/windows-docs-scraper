# MPCLEAN\_PRECHECK\_DATA structure

Notification data passed to clean precheck callback function.

## Members

**BlockedResourceInfo**

Type: **PMPRESOURCE\_INFO**

Resource information about the resource being blocked. For example, when progress is **MPNOTIFY\_PRECHECK\_RESOURCE\_BLOCKED**. See [**MPRESOURCE\_INFO**](https://learn.microsoft.com/windows/win32/lwef/mpresource-info).

**PMPRESOURCE\_INFO**

Type: **BlockingResourceInfo**

Resource information about the resource that is blocking. For example, when progress is **MPNOTIFY\_PRECHECK\_RESOURCE\_BLOCKED**. See [**MPRESOURCE\_INFO**](https://learn.microsoft.com/windows/win32/lwef/mpresource-info).

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | MpClient.h |

## See also

[**MPRESOURCE\_INFO**](https://learn.microsoft.com/windows/win32/lwef/mpresource-info)

