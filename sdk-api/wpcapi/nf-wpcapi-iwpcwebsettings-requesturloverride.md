# IWPCWebSettings::RequestURLOverride

## Description

Requests that the Parental Controls web restrictions subsystem set the specified primary and sub URLs to the allowed state.

## Parameters

### `hWnd` [in]

A handle to the parent window. This is needed for proper User Account Control (UAC) dialog box behavior.

### `pcszURL` [in]

A pointer to primary URL for override.

### `cURLs` [in]

The number of entries in *ppcszSubURLs*.

### `ppcszSubURLs` [in]

Pointers to URLs that include pages with the primary URL.

### `pfChanged` [out]

Pointer to flag notifying completion of override changed status. This parameter is 1 if the status is changed, and 0 otherwise.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, it is E_FAIL.

## See also

[IWPCWebSettings](https://learn.microsoft.com/windows/desktop/api/wpcapi/nn-wpcapi-iwpcwebsettings)