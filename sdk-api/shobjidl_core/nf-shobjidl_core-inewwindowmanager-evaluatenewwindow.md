# INewWindowManager::EvaluateNewWindow

## Description

Accepts data about a new window that is attempting to display and determines whether that window should be allowed to open based on the user's preferences.

## Parameters

### `pszUrl` [in]

Type: **LPCWSTR**

A pointer to a buffer that contains the URL of the content that will be displayed in the new window.

### `pszName` [in]

Type: **LPCWSTR**

A pointer to a buffer that contains the name of the new window. This parameter can be **NULL**.

### `pszUrlContext` [in]

Type: **LPCWSTR**

A pointer to a buffer that contains the URL that has issued the command to open the new window.

### `pszFeatures` [in]

Type: **LPCWSTR**

A pointer to a buffer that contains the feature string for the new window. This value can be **NULL**.

### `fReplace` [in]

Type: **BOOL**

A boolean value used when the new content specified in *pszUrl* is loaded into the existing window instead of creating a new one. **TRUE** if the new document should replace the current document in the history list; **FALSE** if the new document should be given a new entry.

### `dwFlags` [in]

Type: **DWORD**

A flag or flags from the [NWMF](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-nwmf) enumeration that provide situational information about the call to open the new window. This value can be 0 if no flags are needed.

### `dwUserActionTime` [in]

Type: **DWORD**

The tick count when the last user action occurred. To find out how long ago the action occurred, call [GetTickCount](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-gettickcount) and compare the result with the value in this parameter.

## Return value

Type: **HRESULT**

Returns standard error codes, including the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Allow display of the window. |
| **S_FALSE** | Block display of the window. |
| **E_FAIL** | When you implement [INewWindowManager](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-inewwindowmanager) for a hosted [WebBrowser](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa752040(v=vs.85)) control, this value instructs the WebBrowser control to use the default implementation. |