# PWLX_CHANGE_PASSWORD_NOTIFY_EX callback function

## Description

[The WlxChangePasswordNotifyEx function is no longer available for use as of Windows Server 2008 and Windows Vista.]

Called by [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) to tell a specific network provider (or all network providers) that a password has changed.

**Note** GINA DLLs are ignored in Windows Vista.

In this way, GINA can pass a change password request through to a specific network provider.

This function supersedes the
[WlxChangePasswordNotify](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_change_password_notify) function.

## Parameters

### `hWlx` [in]

Specifies the [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) handle passed to GINA in the
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) call.

### `pMprInfo` [in]

Points to a
[WLX_MPR_NOTIFY_INFO](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_mpr_notify_info) structure that contains [Multiple Provider Router](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) (MPR) information. Winlogon will call
[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) to free all the data pointed to by this structure when it is done with it.

### `dwChangeInfo` [in]

Changes the information flags from Network Provider API.

### `ProviderName` [in]

Specifies the name of a network provider, or **NULL** to allow the system to notify all network providers.

### `Reserved` [in]

Reserved. Must be set to zero.

## Return value

The **WlxChangePasswordNotifyEx** function returns zero if the function call succeeds. Any other value indicates an error.

## Remarks

This function supersedes the
[WlxChangePasswordNotify](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_change_password_notify) function.

## See also

[WLX_MPR_NOTIFY_INFO](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_mpr_notify_info)

[WlxChangePasswordNotify](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_change_password_notify)

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)