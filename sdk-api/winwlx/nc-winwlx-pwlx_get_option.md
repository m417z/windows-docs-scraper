# PWLX_GET_OPTION callback function

## Description

[The WlxGetOption function is no longer available for use as of Windows Server 2008 and Windows Vista.]

Called by [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) to retrieve the current value of an option.

**Note** GINA DLLs are ignored in Windows Vista.

## Parameters

### `hWlx` [in]

Specifies the Winlogon handle passed to GINA in the
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) call.

### `Option` [in]

Specifies one of the following options:

### `Value` [out]

Returns the current value of the option.

## Return value

The **WlxGetOption** function returns one of the following values.

| Return code | Description |
| --- | --- |
| **TRUE** | The value of the option was returned in the *Value* parameter. |
| **FALSE** | Winlogon did not return the value. |

## Remarks

In order to access this function, the GINA DLL must use the
[WLX_DISPATCH_VERSION_1_3](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_dispatch_version_1_3) structure and set the Winlogon version to at least WLX_VERSION_1_3 in its
[WlxNegotiate](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxnegotiate) call.

## See also

[WLX_DISPATCH_VERSION_1_3](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_dispatch_version_1_3)

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)

[WlxNegotiate](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxnegotiate)

[WlxSetOption](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_set_option)