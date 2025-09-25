# PWINBIO_EVENT_CALLBACK callback function

## Description

Called by the Windows Biometric Framework to return results from the asynchronous [WinBioRegisterEventMonitor](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioregistereventmonitor) function. The client application must implement this function.

## Parameters

### `EventCallbackContext` [in, optional]

Pointer to a buffer defined by the application and passed to the *EventCallbackContext* parameter of the [WinBioRegisterEventMonitor](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioregistereventmonitor) function. The buffer is not modified by the framework or the biometric unit. Your application can use the data to help it determine what actions to perform or to maintain additional information about the biometric capture.

### `OperationStatus` [in]

Error code returned by the capture operation.

### `Event` [in]

Pointer to a WINBIO_EVENT value. For more information, see [WINBIO_EVENT Constants](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-event-constants).