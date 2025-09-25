# WinBioAsyncOpenFramework function

## Description

Opens a handle to the biometric framework. Starting with Windows 10, build 1607, this function is available to use with a mobile image. You can use this handle to asynchronously enumerate biometric units, databases, and service providers and to receive asynchronous notification when biometric units are attached to the computer or removed.

## Parameters

### `NotificationMethod` [in]

Specifies how completion notifications for asynchronous operations in this framework session are to be delivered to the client application. This must be one of the following values.

| Value | Meaning |
| --- | --- |
| **WINBIO_ASYNC_NOTIFY_CALLBACK** | The framework invokes the callback function defined by the application. |
| **WINBIO_ASYNC_NOTIFY_MESSAGE** | The framework posts a window message to the application's message queue. |

### `TargetWindow` [in, optional]

Handle of the window that will receive the completion notices. This value is ignored unless the *NotificationMethod* parameter is set to **WINBIO_ASYNC_NOTIFY_MESSAGE**.

### `MessageCode` [in, optional]

Window message code the framework must send to signify completion notices. This value is ignored unless the *NotificationMethod* parameter is set to **WINBIO_ASYNC_NOTIFY_MESSAGE**. The value must be within the range [WM_APP](https://learn.microsoft.com/windows/desktop/winmsg/wm-app) (0x8000) to 0xBFFF.

The Windows Biometric Framework sets the **LPARAM** value of the message to the address of the [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure that contains the results of the operation. You must call [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) to release the structure after you have finished using it.

### `CallbackRoutine` [in, optional]

Address of the callback routine to be invoked for completion notices. This value is ignored unless the *NotificationMethod* parameter is set to **WINBIO_ASYNC_NOTIFY_CALLBACK**.

### `UserData` [in, optional]

Address of a buffer supplied by the caller. The buffer is not modified by the framework or the biometric unit. It is returned in the [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure. Your application can use the data to help it determine what actions to perform upon receipt of the completion notice or to maintain additional information about the requested operation.

### `AsynchronousOpen` [in]

Specifies whether to block until the framework session has been opened. Specifying **FALSE** causes the process to block. Specifying **TRUE** causes the session to be opened asynchronously.

If you specify **FALSE** to open the framework session synchronously, success or failure is returned to the caller directly by this function in the **HRESULT** return value. If the session is opened successfully, the first asynchronous completion event your application receives will be for an asynchronous operation requested after the framework has been open.

If you specify **TRUE** to open the framework session asynchronously, the first asynchronous completion notice received will be for opening the framework. If the *NotificationMethod* parameter is set to **WINBIO_ASYNC_NOTIFY_CALLBACK**, operation results are delivered to the [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure in the callback function specified by the *CallbackRoutine* parameter. If the *NotificationMethod* parameter is set to **WINBIO_ASYNC_NOTIFY_MESSAGE**, operation results are delivered to the **WINBIO_ASYNC_RESULT** structure pointed to by the **LPARAM** field of the window message.

### `FrameworkHandle` [out]

If the function does not succeed, this parameter will be **NULL**.

If the session is opened synchronously and successfully, this parameter will contain a pointer to the session handle.

If you specify that the session be opened asynchronously, this method returns immediately, the session handle will be **NULL**, and you must examine the [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure to determine whether the session was successfully opened.

## Return value

If the function succeeds, it returns **S_OK**. If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| ****E_OUTOFMEMORY**** | There is not enough memory available to create the framework session. |
| ****E_INVALIDARG**** | If you set the notification method to **WINBIO_ASYNC_NOTIFY_MESSAGE**, the *TargetWindow* parameter cannot be **NULL** or **HWND_BROADCAST** and the *MessageCode* parameter cannot be zero (0). |
| ****E_POINTER**** | The *FrameworkHandle* parameter and the *AsynchronousOpen* parameter must be set.<br><br>If you set the notification method to **WINBIO_ASYNC_NOTIFY_CALLBACK**, you must also specify the address of a callback function in the *CallbackRoutine* parameter. |

## Remarks

The framework handle returned by the **WinBioAsyncOpenFramework** function can be used to generate asynchronous completion notifications for the following functions:

* [WinBioAsyncEnumBiometricUnits](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncenumbiometricunits)
* [WinBioAsyncEnumDatabases](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncenumdatabases)
* [WinBioAsyncEnumServiceProviders](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncenumserviceproviders)
* [WinBioAsyncMonitorFrameworkChanges](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncmonitorframeworkchanges)

The *AsynchronousOpen* parameter determines only whether the open operation will block. This parameter has no effect on the completion behavior of subsequent calls that use the session handle.

If you set the *AsynchronousOpen* parameter to **TRUE**, this function will return **S_OK** as soon as it has performed an initial validation of the arguments. Any errors detected beyond that point will be reported to the caller using the method specified by the *NotificationMethod* parameter. That is, a successful return value indicates only that the **WinBioAsyncOpenFramework** parameters were fine and not that the open operation succeeded. To determine whether the open operation succeeded, you must examine the [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure.

## See also

[WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession)