# OnUserNameChanged function

Occurs when the name information for a [**DIDiskQuotaUser**](https://learn.microsoft.com/windows/win32/shell/didiskquotauser-object) object has been resolved.

## Parameters

*oUser*

The **Object** that evaluates to the [**DIDiskQuotaUser**](https://learn.microsoft.com/windows/win32/shell/didiskquotauser-object) object associated with the user whose name has been resolved.

## Return value

This function does not return a value.

## Remarks

When a client [**enumerates users**](https://learn.microsoft.com/windows/win32/shell/didiskquotauser-object), or calls the [**AddUser**](https://learn.microsoft.com/windows/win32/shell/diskquotacontrol-adduser) or [**FindUser**](https://learn.microsoft.com/windows/win32/shell/diskquotacontrol-finduser) method, the user name must be resolved to the associated security ID (SID). Because this procedure can be time-consuming, a client can have name resolution done asynchronously on a background thread. When a user's name is resolved, the [**DiskQuotaControl**](https://learn.microsoft.com/windows/win32/shell/diskquotacontrol-object) object notifies its client by firing the **OnUserNameChanged** event. A **DIDiskQuotaUser** object associated with the user is passed as a parameter. This object allows the client to modify the user's quota settings.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Dskquota.h |
| DLL<br> | Shell32.dll (version 5.0 or later) |

## See also

[**DiskQuotaControl Object**](https://learn.microsoft.com/windows/win32/shell/diskquotacontrol-object)

