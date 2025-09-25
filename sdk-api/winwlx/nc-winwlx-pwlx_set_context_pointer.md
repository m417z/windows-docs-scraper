# PWLX_SET_CONTEXT_POINTER callback function

## Description

[The WlxSetContextPointer function is no longer available for use as of Windows Server 2008 and Windows Vista.]

Called by [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) to specify the [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) pointer passed by [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) as the first parameter to all future calls to GINA functions.

**Note** GINA DLLs are ignored in Windows Vista.

This allows GINA to specify a new context pointer that replaces the one returned by the
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) function.

This function has been superseded by the
[WlxSetOption](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_set_option) function called with the *Option* parameter set to WLX_OPTION_CONTEXT_POINTER.

## Parameters

### `hWlx` [in]

Specifies the Winlogon handle passed to GINA in the
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) call.

### `pWlxContext` [in]

Pointer to the new context that Winlogon will use in future calls to GINA.

## Remarks

If the GINA must call
[WlxSasNotify](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_sas_notify) from the [WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) function, it should first call **WlxSetContextPointer** to let Winlogon associate a context with the GINA.

## See also

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)

[WlxSasNotify](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_sas_notify)

[WlxSetOption](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_set_option)