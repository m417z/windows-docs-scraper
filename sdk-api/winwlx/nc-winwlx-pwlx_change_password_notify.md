# PWLX_CHANGE_PASSWORD_NOTIFY callback function

## Description

[The WlxChangePasswordNotify function is no longer available for use as of Windows Server 2008 and Windows Vista.]

Called by [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) to indicate it has changed a password.

**Note** GINA DLLs are ignored in Windows Vista.

This allows [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) to notify other network providers on the computer to update their passwords as well.

This function has been superseded by the
[WlxChangePasswordNotifyEx](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_change_password_notify_ex) function.

## Parameters

### `hWlx` [in]

Specifies the Winlogon handle passed to GINA in the
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) call.

### `pMprInfo` [in]

Points to a
[WLX_MPR_NOTIFY_INFO](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_mpr_notify_info) structure that contains [Multiple Provider Router](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) (MPR) information. Winlogon will call [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) to free all the data pointed to by this structure when it is done with it.

### `dwChangeInfo` [in]

Changes the information flags from
[Network Provider API](https://learn.microsoft.com/windows/desktop/SecAuthN/network-provider-api).

## Return value

The [WlxChangePasswordNotifyEx](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_change_password_notify_ex) function returns zero if the function call succeeds. Any other value indicates an error.

## See also

[WLX_MPR_NOTIFY_INFO](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_mpr_notify_info)

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)