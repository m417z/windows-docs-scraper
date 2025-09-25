# IRichEditOleCallback::ContextSensitiveHelp

## Description

Indicates if the application should transition into or out of context-sensitive help mode. This method should implement the functionality described for [IOleWindow::ContextSensitiveHelp](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolewindow-contextsensitivehelp).

## Parameters

### `fEnterMode`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If **TRUE**, the application should enter context-sensitive help mode. If **FALSE**, the application should leave context-sensitive help mode.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns **S_OK** on success. If the method fails, it can be the following value.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | There was an invalid argument. |

## See also

[IRichEditOleCallback](https://learn.microsoft.com/windows/desktop/api/richole/nn-richole-iricheditolecallback)