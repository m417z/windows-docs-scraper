# InternetErrorDlg function

## Description

Displays a dialog box for the error that is passed to
**InternetErrorDlg**, if an appropriate dialog box exists. If the
**FLAGS_ERROR_UI_FILTER_FOR_ERRORS** flag is used, the function also checks the headers for any hidden errors and displays a dialog box if needed.

## Parameters

### `hWnd` [in]

Handle to the parent window for any needed dialog box. If no dialog box is needed and **FLAGS_ERROR_UI_FLAGS_NO_UI** is passed to *dwFlags*, then this parameter can be **NULL**.

### `hRequest` [in, out]

Handle to the Internet connection used in the call to
[HttpSendRequest](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpsendrequesta).

### `dwError` [in]

Error value for which to display a dialog box. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| ERROR_HTTP_REDIRECT_NEEDS_CONFIRMATION | Allows the user to confirm the redirect. |
| ERROR_INTERNET_BAD_AUTO_PROXY_SCRIPT | Displays a dialog indicating that the auto proxy script is invalid. |
| ERROR_INTERNET_CHG_POST_IS_NON_SECURE | Displays a dialog asking the user whether to post the given data on a non-secure channel. |
| ERROR_INTERNET_CLIENT_AUTH_CERT_NEEDED | The server is requesting a client certificate.<br><br>The return value for this error is always ERROR_SUCCESS, regardless of whether or not the user has selected a certificate. If the user has not selected a certificate then anonymous client authentication will be attempted on the subsequent request. |
| ERROR_INTERNET_HTTP_TO_HTTPS_ON_REDIR | Notifies the user of the zone crossing to a secure site. |
| ERROR_INTERNET_HTTPS_TO_HTTP_ON_REDIR | Notifies the user of the zone crossing from a secure site. |
| ERROR_INTERNET_HTTPS_HTTP_SUBMIT_REDIR | Notifies the user that the data being posted is now being redirected to a non-secure site. |
| ERROR_INTERNET_INCORRECT_PASSWORD | Displays a dialog box requesting the user's name and password. |
| ERROR_INTERNET_INVALID_CA | Indicates that the SSL certificate Common Name (host name field) is incorrect. Displays an Invalid SSL Common Name dialog box and lets the user view the incorrect certificate. |
| ERROR_INTERNET_MIXED_SECURITY | Displays a warning to the user concerning mixed secure and non-secure content. |
| ERROR_INTERNET_POST_IS_NON_SECURE | Displays a dialog asking the user whether to post the given data on a non-secure channel. |
| ERROR_INTERNET_SEC_CERT_CN_INVALID | Indicates that the SSL certificate Common Name (host name field) is incorrect. Displays an Invalid SSL Common Name dialog box and lets the user view the incorrect certificate. Also allows the user to select a certificate in response to a server request. |
| ERROR_INTERNET_SEC_CERT_ERRORS | Displays a warning to the user showing the issues with the server certificate. |
| ERROR_INTERNET_SEC_CERT_DATE_INVALID | Tells the user that the SSL certificate has expired. |
| ERROR_INTERNET_SEC_CERT_REV_FAILED | Displays a warning to the user showing that the server certificate’s revocation check failed. |
| ERROR_INTERNET_SEC_CERT_REVOKED | Displays a dialog indicating that the server certificate is revoked. |
| ERROR_INTERNET_UNABLE_TO_DOWNLOAD_SCRIPT | Displays a dialog indicating that the auto proxy script could not be downloaded. |

### `dwFlags` [in]

Actions. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| FLAGS_ERROR_UI_FILTER_FOR_ERRORS | Scans the returned headers for errors. Call **InternetErrorDlg** with this flag set following a call to [HttpSendRequest](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpsendrequesta) so as to detect hidden errors. Authentication errors, for example, are normally hidden because the call to [HttpSendRequest](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpsendrequesta) completes successfully, but by scanning the status codes, **InternetErrorDlg** can determine that the proxy or server requires authentication. |
| FLAGS_ERROR_UI_FLAGS_CHANGE_OPTIONS | If the function succeeds, stores the results of the dialog box in the Internet handle. |
| FLAGS_ERROR_UI_FLAGS_GENERATE_DATA | Queries the Internet handle for needed information. The function constructs the appropriate data structure for the error. (For example, for Cert CN failures, the function grabs the certificate.) |
| FLAGS_ERROR_UI_SERIALIZE_DIALOGS | Serializes authentication dialog boxes for concurrent requests on a password cache entry. The *lppvData* parameter should contain the address of a pointer to an [INTERNET_AUTH_NOTIFY_DATA](https://learn.microsoft.com/windows/win32/api/wininet/ns-wininet-internet_per_conn_optionw) structure, and the client should implement a thread-safe, non-blocking callback function. |
| FLAGS_ERROR_UI_FLAGS_NO_UI | Allows the caller to pass **NULL** to the *hWnd* parameter without error. To be used in circumstances in which no user interface is required. |

### `lppvData` [in, out]

Pointer to the address of a data structure. The structure can be different for each error that needs to be handled.

## Return value

Returns one of the following values, or an error value otherwise.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function completed successfully.<br><br>For more information, see **ERROR_INTERNET_CLIENT_AUTH_CERT_NEEDED** in the *dwError* parameter. |
| **ERROR_CANCELLED** | The function was canceled by the user. |
| **ERROR_INTERNET_FORCE_RETRY** | This indicates that the function needs to redo its request. In the case of authentication this indicates that the user clicked the **OK** button. |
| **ERROR_INVALID_HANDLE** | The handle to the parent window is invalid. |

## Remarks

Always inform the user when any of the following events occur:

* ERROR_INTERNET_HTTP_TO_HTTPS_ON_REDIR
* ERROR_INTERNET_INVALID_CA
* ERROR_INTERNET_POST_IS_NON_SECURE
* ERROR_INTERNET_SEC_CERT_CN_INVALID
* ERROR_INTERNET_SEC_CERT_DATE_INVALID

Unless the user has explicitly chosen not to be informed of these events, failure to do so exposes the user involuntarily to a significant security risk.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[Enabling Internet Functionality](https://learn.microsoft.com/windows/desktop/WinInet/enabling-internet-functionality)

 [WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)