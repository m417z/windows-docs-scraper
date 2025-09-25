# PWLX_SET_OPTION callback function

## Description

[The WlxSetOption function is no longer available for use as of Windows Server 2008 and Windows Vista.]

Called by [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) to set the value of an option.

**Note** GINA DLLs are ignored in Windows Vista.

## Parameters

### `hWlx` [in]

Specifies the Winlogon handle passed to GINA in the
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) call.

### `Option` [in]

Specifies one of the following options:

### `Value` [in]

Specifies a new value for the option.

### `OldValue` [out]

On return, pointer to the old value the option was set to.

## Return value

The **WlxSetOption** function returns one of the following values.

| Return code | Description |
| --- | --- |
| **TRUE** | The option was set to the value specified in the *Value* parameter. |
| **FALSE** | Winlogon did not set *Option* to *Value*. |

## Remarks

In order to access this function, the GINA DLL must use the
[WLX_DISPATCH_VERSION_1_3](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_dispatch_version_1_3) structure and set the Winlogon version to at least WLX_VERSION_1_3 in its
[WlxNegotiate](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxnegotiate) call.

Use
[WlxGetOption](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_get_option) to retrieve the current value of an option.

## See also

[WLX_DISPATCH_VERSION_1_3](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_dispatch_version_1_3)

[WlxGetOption](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_get_option)

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)

[WlxNegotiate](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxnegotiate)