# IWebApplicationScriptEvents::ScriptError

## Description

Fired when an unhandled script error occurs.

## Parameters

### `htmlWindow` [in]

Type: **[IHTMLWindow2](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa741505(v=vs.85))***

The window or frame in which the script error occurred.

### `scriptError` [in]

Type: **[IActiveScriptError](https://learn.microsoft.com/scripting/winscript/reference/iactivescripterror)***

The object that contains info about the script error that occurred.

### `url` [in]

Type: **LPCWSTR**

The URL on which the script error occurred.

### `errorHandled` [in]

Type: **BOOL**

**TRUE** if the app handled the error; otherwise **FALSE**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWebApplicationScriptEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/webapplication/nn-webapplication-iwebapplicationscriptevents)