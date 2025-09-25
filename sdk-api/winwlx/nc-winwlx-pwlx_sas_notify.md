# PWLX_SAS_NOTIFY callback function

## Description

[The WlxSasNotify function is no longer available for use as of Windows Server 2008 and Windows Vista.]

Called by [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) to notify [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) of a [secure attention sequence](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SAS) event.

**Note** GINA DLLs are ignored in Windows Vista.

## Parameters

### `hWlx` [in]

Specifies the Winlogon handle passed to GINA in the
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) call.

### `dwSasType` [in]

Specifies the type of SAS that occurred.

Values from zero to WLX_SAS_TYPE_MAX_MSFT_VALUE are reserved to define standard Microsoft SAS types. GINA developers can use values greater than WLX_SAS_TYPE_MAX_MSFT_VALUE to define additional SAS types.

The following values are predefined.

This value will be delivered to one of the GINA SAS service routines called by Winlogon ([WlxLoggedOutSAS](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxloggedoutsas),
[WlxLoggedOnSAS](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxloggedonsas), or
[WlxWkstaLockedSAS](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxwkstalockedsas)).

| Value | Meaning |
| --- | --- |
| **WLX_SAS_TYPE_CTRL_ALT_DEL** | Indicates that the user has typed the CTRL+ALT+DEL SAS. |

## See also

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)

[WlxLoggedOnSAS](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxloggedonsas)

[WlxLoggedOutSAS](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxloggedoutsas)

[WlxWkstaLockedSAS](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxwkstalockedsas)