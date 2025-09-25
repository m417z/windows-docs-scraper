## Description

The **WinHttpCloseHandle** function closes a single **HINTERNET** handle (see [HINTERNET Handles in WinHTTP](https://learn.microsoft.com/windows/win32/winhttp/hinternet-handles-in-winhttp)).

## Parameters

### `hInternet` [in]

A valid **HINTERNET** handle (see [HINTERNET Handles in WinHTTP](https://learn.microsoft.com/windows/win32/winhttp/hinternet-handles-in-winhttp)) to be closed.

## Return value

**TRUE** if the handle is successfully closed, otherwise **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Among the error codes returned are the following.

| Error Codes | Description |
| --- | --- |
| **ERROR_WINHTTP_SHUTDOWN** | The WinHTTP function support is being shut down or unloaded. |
| **ERROR_WINHTTP_INTERNAL_ERROR** | An internal error has occurred. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory was available to complete the requested operation. (Windows error code) |

## Remarks

Even when WinHTTP is used in asynchronous mode (that is, when **WINHTTP_FLAG_ASYNC** has been set in [WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen)), this function operates synchronously. The return value indicates success or failure. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If there is a status callback registered for the handle being closed and the handle was created with a non-**NULL** context value, a **WINHTTP_CALLBACK_STATUS_HANDLE_CLOSING** callback is made. This is the last callback made from the handle and indicates that the handle is being destroyed.

An application can terminate an in-progress asynchronous request by closing the [HINTERNET](https://learn.microsoft.com/windows/desktop/WinHttp/hinternet-handles-in-winhttp) request handle using **WinHttpCloseHandle**. Keep the following points in mind:

* After an application calls **WinHttpCloseHandle** on a WinHTTP handle, it cannot call any other WinHTTP API functions using that handle from any thread.
* Even after a call to **WinHttpCloseHandle** returns, the application must still be prepared to receive callbacks for the closed handle, because WinHTTP can tear down the handle asynchronously. If the asynchronous request was not able to complete successfully, the callback receives a WINHTTP_CALLBACK_STATUS_REQUEST_ERROR notification.
* If an application associates a context data structure or object with the handle, it should maintain that binding until the callback function receives a **WINHTTP_CALLBACK_STATUS_HANDLE_CLOSING** notification. This is the last callback notification WinHTTP sends prior to deleting a handle object from memory. In order to receive the **WINHTTP_CALLBACK_STATUS_HANDLE_CLOSING** callback notification, the application must enable the **WINHTTP_CALLBACK_FLAG_HANDLES** flag in the [WinHttpSetStatusCallback](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsetstatuscallback) call.
* Before calling **WinHttpCloseHandle**, an application can call [WinHttpSetStatusCallback](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsetstatuscallback) to indicate that no more callbacks should be made:

  `WinHttpSetStatusCallback( hRequest, NULL, 0, 0 );`

  It might seem that the context data structure could then be freed immediately rather than having to wait for a **WINHTTP_CALLBACK_STATUS_HANDLE_CLOSING** notification, but this is not the case: WinHTTP does not synchronize [WinHttpSetStatusCallback](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsetstatuscallback) with callbacks originating in worker threads. As a result, a callback could already be in progress from another thread, and the application could receive a callback notification even after having **NULL** ed-out the callback function pointer and deleted the handle's context data structure. Because of this potential race condition, be conservative in freeing the context structure until after having received the **WINHTTP_CALLBACK_STATUS_HANDLE_CLOSING** notification.

An application should never call **WinHttpCloseHandle** on a synchronous request. This can create a race condition. See [HINTERNET Handles in WinHTTP](https://learn.microsoft.com/windows/desktop/WinHttp/hinternet-handles-in-winhttp) for more information.

**Note** For Windows XP and Windows 2000, see the [Run-Time Requirements](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page) section of the WinHttp start page.

## --examples

The following example shows you how to retrieve the connection
time-out value:

```cpp
    DWORD data;
    DWORD dwSize = sizeof(DWORD);

    // Use WinHttpOpen to obtain an HINTERNET handle.
    HINTERNET hSession = WinHttpOpen(L"A WinHTTP Example Program/1.0",
                                    WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
                                    WINHTTP_NO_PROXY_NAME,
                                    WINHTTP_NO_PROXY_BYPASS, 0);
    if (hSession)
    {

        // Use WinHttpQueryOption to retrieve internet options.
        if (WinHttpQueryOption( hSession,
                                WINHTTP_OPTION_CONNECT_TIMEOUT,
                                &data, &dwSize))
        {
            printf("Connection timeout: %u ms\n\n",data);
        }
        else
        {
            printf("Error %u in WinHttpQueryOption.\n",
                   GetLastError());
        }

        // When finished, release the HINTERNET handle.
        WinHttpCloseHandle(hSession);
    }
    else
    {
        printf("Error %u in WinHttpOpen.\n", GetLastError());
    }

```

## See also

[About Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/about-winhttp)

[WinHTTP Versions](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-versions)

[WinHttpConnect](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpconnect)

[WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen)

[WinHttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopenrequest)