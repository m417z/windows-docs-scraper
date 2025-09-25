# IWPCProviderConfig::RequestOverride

## Description

Called for the current provider to enable configuration override.

## Parameters

### `hWnd` [in]

A handle to the parent window.

### `bstrPath` [in]

Pointer to a string that contains the path.

### `dwFlags` [in]

Flags that specify the restriction. This can be one of more of the following values.

| Value | Meaning |
| --- | --- |
| **WPCFLAG_NO_RESTRICTION**<br><br>0 | There are no restrictions. |
| **WPCFLAG_LOGGING_REQUIRED**<br><br>0x1 | Activity logging is on. |
| **WPCFLAG_WEB_FILTERED**<br><br>0x2 | A Web Content Filter is active. |
| **WPCFLAG_HOURS_RESTRICTED**<br><br>0x4 | Hours are restricted. |
| **WPCFLAG_GAMES_BLOCKED**<br><br>0x8 | Games are blocked. |
| **WPCFLAG_APPS_RESTRICTED**<br><br>0x10 | Applications are restricted. |

## Return value

If the method succeeds, the method returns **S_OK**.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IWPCProviderConfig](https://learn.microsoft.com/windows/desktop/api/wpcapi/nn-wpcapi-iwpcproviderconfig)