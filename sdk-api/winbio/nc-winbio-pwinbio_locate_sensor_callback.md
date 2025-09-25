# PWINBIO_LOCATE_SENSOR_CALLBACK callback function

## Description

Called by the Windows Biometric Framework to return results from the asynchronous [WinBioLocateSensorWithCallback](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiolocatesensorwithcallback) function. The client application must implement this function.

**Important** We recommend that, beginning with Windows 8, you no longer use the **PWINBIO_LOCATE_SENSOR_CALLBACK**/**WinBioLocateSensorWithCallback** combination. Instead, do the following:

* Implement a [PWINBIO_ASYNC_COMPLETION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winbio/nc-winbio-pwinbio_async_completion_callback) function to receive notice when the operation completes.
* Call the [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession) function. Pass the address of your callback in the *CallbackRoutine* parameter. Pass **WINBIO_ASYNC_NOTIFY_CALLBACK** in the *NotificationMethod* parameter. Retrieve an asynchronous session handle.
* Use the asynchronous session handle to call [WinBioLocateSensor](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiolocatesensor). When the operation finishes, the Windows Biometric Framework will allocate and initialize a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure with the results and invoke your callback with a pointer to the results structure.
* Call [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) from your callback implementation to release the [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure after you have finished using it.

## Parameters

### `LocateCallbackContext` [in, optional]

Pointer to a buffer defined by the application and passed to the *LocateCallbackContext* parameter of the [WinBioLocateSensorWithCallback](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiolocatesensorwithcallback) function. The buffer is not modified by the framework or the biometric unit. Your application can use the data to help it determine what actions to perform or to maintain additional information about the biometric capture.

### `OperationStatus` [in]

Error code returned by the capture operation.

### `UnitId`

Biometric unit ID number.