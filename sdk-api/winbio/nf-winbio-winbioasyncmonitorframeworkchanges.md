# WinBioAsyncMonitorFrameworkChanges function

## Description

Starts an asynchronous monitor of changes to the biometric framework. Currently, the only monitored changes that are supported occur when a biometric unit is attached to or detached from the computer.

## Parameters

### `FrameworkHandle` [in]

Handle to the framework session opened by calling [WinBioAsyncOpenFramework](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopenframework).

### `ChangeTypes` [in]

A bitmask of type **WINBIO_FRAMEWORK_CHANGE_TYPE** flags that indicates the types of events that should generate asynchronous notifications. Beginning with Windows 8, the following flag is available:

| Value | Meaning |
| --- | --- |
| **WINBIO_FRAMEWORK_CHANGE_UNIT** | A biometric unit has been attached to or detached from the computer. |

## Return value

The function returns an **HRESULT** indicating success or failure. Note that success indicates only that the function arguments were valid. Failures encountered during the execution of the operation will be returned asynchronously to a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure using the notification method specified in [WinBioAsyncOpenFramework](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopenframework).

| Return code | Description |
| --- | --- |
| **E_HANDLE** | You must set the *FrameworkHandle* argument. |
| **E_INVALIDARG** | The bitmask contained in the *ChangeTypes* parameter contains one or more an invalid type bits. Currently, the only available value is **WINBIO_FRAMEWORK_CHANGE_UNIT**. |
| **WINBIO_E_INCORRECT_SESSION_TYPE** | The *FrameworkHandle* argument must represent an asynchronous framework session. |

## Remarks

Once started, this monitor will continue generating events until the client application calls [WinBioCancel](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiocancel) or [WinBioCloseFramework](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiocloseframework). Creating a monitor for **WINBIO_FRAMEWORK_CHANGE_UNIT** events will generate two types of asynchronous notifications:

| Value | Meaning |
| --- | --- |
| **WINBIO_OPERATION_UNIT_ARRIVAL** | A biometric unit is attached. |
| **WINBIO_OPERATION_UNIT_REMOVAL** | A biometric unit is detached. |

The **WinBioAsyncMonitorFrameworkChanges** function uses a handle to the framework session opened by calling [WinBioAsyncOpenFramework](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopenframework). The framework allocates a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure and uses it to return information about operation success or failure. If a biometric unit is attached to or detached from the computer, the framework sets the **Operation** member of the structure. If a problem is encountered during the operation, the framework uses the **WINBIO_ASYNC_RESULT** structure to return error information. The structure is returned to the application callback or to the application message queue, depending on the value you set in the *NotificationMethod* parameter of the **WinBioAsyncOpenFramework** function.

* If you choose to receive completion notices by using a callback, you must implement a [PWINBIO_ASYNC_COMPLETION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winbio/nc-winbio-pwinbio_async_completion_callback) function and set the *NotificationMethod* parameter to **WINBIO_ASYNC_NOTIFY_CALLBACK**.
* If you choose to receive completion notices by using the application message queue, you must set the *NotificationMethod* parameter to **WINBIO_ASYNC_NOTIFY_MESSAGE**. The framework returns a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) pointer to the **LPARAM** field of the window message.

Notifications are returned in an **EnumServiceProviders** structure nested inside the [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure. You must call [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) to release the **WINBIO_ASYNC_RESULT** structure after you have finished using it.

## See also

[WinBioAsyncOpenFramework](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopenframework)