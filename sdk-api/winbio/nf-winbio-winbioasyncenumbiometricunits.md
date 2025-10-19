# WinBioAsyncEnumBiometricUnits function

## Description

Asynchronously enumerates all attached biometric units that match the input factor type. For a synchronous version of this function, see [WinBioEnumBiometricUnits](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenumbiometricunits). Starting with Windows 10, build 1607, this function is available to use with a mobile image.

## Parameters

### `FrameworkHandle` [in]

Handle to the framework session opened by calling [WinBioAsyncOpenFramework](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopenframework).

### `Factor` [in]

A bitmask of [WINBIO_BIOMETRIC_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/winbio_ioctl/ns-winbio_ioctl-_winbio_sensor_attributes) flags that specifies the biometric unit types to be enumerated. Only **WINBIO_TYPE_FINGERPRINT** is currently supported.

## Return value

The function returns an **HRESULT** indicating success or failure. Note that success indicates only that the arguments were valid. Failures encountered during the execution of the operation will be returned asynchronously to a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure using the notification method specified in the call to [WinBioAsyncOpenFramework](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopenframework).

| Return code | Description |
| --- | --- |
| **E_HANDLE** | You must set the *FrameworkHandle* argument. |
| **E_INVALIDARG** | The bitmask contained in the *Factor* parameter contains one or more an invalid type bits. |
| **E_OUTOFMEMORY** | There was insufficient memory to complete the request. |
| **WINBIO_E_DISABLED** | Current administrative policy prohibits use of the Windows Biometric Framework API. |
| **WINBIO_E_INCORRECT_SESSION_TYPE** | The *FrameworkHandle* argument must represent an asynchronous framework session. |
| **WINBIO_E_SESSION_HANDLE_CLOSED** | The session handle has been marked for closure. |

## Remarks

The **WinBioAsyncEnumBiometricUnits** function uses a handle to the framework session opened by calling [WinBioAsyncOpenFramework](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopenframework). The framework allocates a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure and uses it to return information about operation success or failure. If the enumeration operation is successful, the framework returns an array of schemas that include information about each enumerated biometric unit. If the operation is unsuccessful, the framework uses the **WINBIO_ASYNC_RESULT** structure to return error information. The structure is returned to the application callback or to the application message queue, depending on the value you set in the *NotificationMethod* parameter of the **WinBioAsyncOpenFramework** function.

* If you choose to receive completion notices by using a callback, you must implement a [PWINBIO_ASYNC_COMPLETION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winbio/nc-winbio-pwinbio_async_completion_callback) function and set the *NotificationMethod* parameter to **WINBIO_ASYNC_NOTIFY_CALLBACK**.
* If you choose to receive completion notices by using the application message queue, you must set the *NotificationMethod* parameter to **WINBIO_ASYNC_NOTIFY_MESSAGE**. The framework returns a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) pointer to the **LPARAM** field of the window message.

The array of schemas is returned in an **EnumBiometricUnits** structure nested inside the [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure. You must call [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) to release the **WINBIO_ASYNC_RESULT** structure after you have finished using it.

Calling **WinBioAsyncEnumBiometricUnits** causes a single notification to be sent to the client application.

## See also

[WinBioAsyncOpenFramework](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopenframework)