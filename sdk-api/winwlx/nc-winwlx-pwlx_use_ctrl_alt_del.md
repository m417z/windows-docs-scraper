# PWLX_USE_CTRL_ALT_DEL callback function

## Description

Called by [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) to tell [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) to use the standard CTRL+ALT+DEL key combination as a [secure attention sequence](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SAS).

**Note** GINA DLLs are ignored in Windows Vista.

This function has been superseded by the
[WlxSetOption](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_set_option) function called with *Option* parameter set to WLX_OPTION_USE_CTRL_ALT_DEL.

## Parameters

### `hWlx` [in]

[in] Winlogon handle provided to GINA in the [WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) call.

## Remarks

If GINA uses this function, it is not required to use the
[WlxSasNotify](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_sas_notify) function. However, if GINA is monitoring for other SASs in addition to CTRL+ALT+DEL, it must use **WlxSasNotify** to deliver the additional SAS event notifications.

## See also

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)

[WlxSasNotify](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_sas_notify)

[WlxSetOption](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_set_option)