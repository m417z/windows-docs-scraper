# ResumeSuspendedDownload function

## Description

The **ResumeSuspendedDownload** function resumes a request that is suspended by a user interface dialog box.

## Parameters

### `hRequest` [in]

Handle of the request that is suspended by a user interface dialog box.

### `dwResultCode` [in]

The error result returned from [InternetErrorDlg](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-interneterrordlg), or zero if a different dialog is invoked.

## Return value

Returns **TRUE** if successful; otherwise **FALSE**. Call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) for extended error information.

## Remarks

Applications that use WinINet functions asynchronously can call **ResumeSuspendedDownload** to resume a request that is suspended by a user interface dialog box.

For example, call **ResumeSuspendedDownload** after a call to [InternetErrorDlg](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-interneterrordlg), or in an [InternetStatusCallback](https://learn.microsoft.com/windows/desktop/api/wininet/nc-wininet-internet_status_callback) function when the *lpvStatusInformation* parameter equals **INTERNET_STATUS_USER_INPUT_REQUIRED**. The following code example shows you how to use the **ResumeSuspendedDownload** function in a callback.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

#### Examples

``` syntax
void CALLBACK YourInternetStatusCallbackFunction(
    HINTERNET hInternet,
    DWORD_PTR dwContext,
    DWORD dwInternetStatus,
    LPVOID lpvStatusInformation
    DWORD dwStatusInformationLength )
{
//  [...other callback code here]

  switch (dwInternetStatus)
  {
//  [...handle other INTERNET_STATUS cases]

    case INTERNET_STATUS_USER_INPUT_REQUIRED:
      ResumeSuspendedDownload( hInternet, 0 );
      break;

//  [...handle other INTERNET_STATUS cases]

    default:
//    [...default code]
      break;
  }

  return;
}
```

## See also

[InternetErrorDlg](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-interneterrordlg)

[InternetStatusCallback](https://learn.microsoft.com/windows/desktop/api/wininet/nc-wininet-internet_status_callback)