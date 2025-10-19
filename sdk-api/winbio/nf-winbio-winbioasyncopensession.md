# WinBioAsyncOpenSession function

## Description

Asynchronously connects to a biometric service provider and one or more biometric units. Starting with Windows 10, build 1607, this function is available to use with a mobile image. If successful, the function returns a biometric session handle. Every operation performed by using this handle will be completed asynchronously, including [WinBioCloseSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioclosesession), and the results will be returned to the client application by using the method specified in the *NotificationMethod* parameter.

For a synchronous version of this function, see [WinBioOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioopensession).

## Parameters

### `Factor` [in]

A bitmask of [WINBIO_BIOMETRIC_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/winbio_ioctl/ns-winbio_ioctl-_winbio_sensor_attributes) flags that specifies the biometric unit types to be enumerated. Only **WINBIO_TYPE_FINGERPRINT** is currently supported.

### `PoolType` [in]

A **ULONG** value that specifies the type of the biometric units that will be used in the session. This can be one of the following values:

| Value | Meaning |
| --- | --- |
| **WINBIO_POOL_SYSTEM** | The session connects to a shared collection of biometric units managed by the service provider. |
| **WINBIO_POOL_PRIVATE** | The session connects to a collection of biometric units that are managed by the caller. |

### `Flags` [in]

A **ULONG** value that specifies biometric unit configuration and access characteristics for the new session. Configuration flags specify the general configuration of units in the session. Access flags specify how the application will use the biometric units. You must specify one configuration flag but you can combine that flag with any access flag.

| Value | Meaning |
| --- | --- |
| **WINBIO_FLAG_DEFAULT** | Group: configuration<br><br>The biometric units operate in the manner specified during installation. You must use this value when the *PoolType* parameter is **WINBIO_POOL_SYSTEM**. |
| **WINBIO_FLAG_BASIC** | Group: configuration<br><br>The biometric units operate only as basic capture devices. All processing, matching, and storage operations is performed by software plug-ins. |
| **WINBIO_FLAG_ADVANCED** | Group: configuration<br><br>The biometric units use internal processing and storage capabilities. |
| **WINBIO_FLAG_RAW** | Group: access<br><br>The client application captures raw biometric data using [WinBioCaptureSample](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiocapturesample). |
| **WINBIO_FLAG_MAINTENANCE** | Group: access<br><br>The client performs vendor-defined control operations on a biometric unit by calling [WinBioControlUnitPrivileged](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiocontrolunitprivileged). |

### `UnitArray` [in, optional]

Pointer to an array of biometric unit identifiers to be included in the session. You can call [WinBioEnumBiometricUnits](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenumbiometricunits) to enumerate the biometric units. Set this value to **NULL** if the *PoolType* parameter is **WINBIO_POOL_SYSTEM**.

### `UnitCount` [in, optional]

A value that specifies the number of elements in the array pointed to by the *UnitArray* parameter. Set this value to zero if the *PoolType* parameter is **WINBIO_POOL_SYSTEM**.

### `DatabaseId` [in, optional]

A value that specifies the database(s) to be used by the session. If the *PoolType* parameter is **WINBIO_POOL_PRIVATE**, you must specify the GUID of an installed database. If the *PoolType* parameter is not **WINBIO_POOL_PRIVATE**, you can specify one of the following common values.

| Value | Meaning |
| --- | --- |
| **WINBIO_DB_DEFAULT** | Each biometric unit in the sensor pool uses the default database specified in the default biometric unit configuration. You must specify this value if the *PoolType* parameter is **WINBIO_POOL_SYSTEM**. You cannot use this value if the *PoolType* parameter is **WINBIO_POOL_PRIVATE** |
| **WINBIO_DB_BOOTSTRAP** | You can specify this value to be used for scenarios prior to starting Windows. Typically, the database is part of the sensor chip or is part of the BIOS and can only be used for template enrollment and deletion. |
| **WINBIO_DB_ONCHIP** | The database is on the sensor chip and is available for enrollment and matching. |

### `NotificationMethod` [in]

Specifies how completion notifications for asynchronous operations in this biometric session are to be delivered to the client application. This must be one of the following values.

| Value | Meaning |
| --- | --- |
| **WINBIO_ASYNC_NOTIFY_CALLBACK** | The session invokes the callback function defined by the application. |
| **WINBIO_ASYNC_NOTIFY_MESSAGE** | The session posts a window message to the application's message queue. |

### `TargetWindow` [in, optional]

Handle of the window that will receive the completion notices. This value is ignored unless the *NotificationMethod* parameter is set to **WINBIO_ASYNC_NOTIFY_MESSAGE**.

### `MessageCode` [in, optional]

Window message code the framework must send to signify completion notices. This value is ignored unless the *NotificationMethod* parameter is set to **WINBIO_ASYNC_NOTIFY_MESSAGE**. The value must be within the range WM_APP(0x8000) to 0xBFFF.

The Windows Biometric Framework sets the **LPARAM** value of the message to the address of the [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure that contains the results of the operation. You must call [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) to release the structure after you have finished using it.

### `CallbackRoutine` [in, optional]

Address of callback routine to be invoked when the operation started by using the session handle completes. This value is ignored unless the *NotificationMethod* parameter is set to **WINBIO_ASYNC_NOTIFY_CALLBACK**.

### `UserData` [in, optional]

Address of a buffer supplied by the caller. The buffer is not modified by the framework or the biometric unit. It is returned in the [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure. Your application can use the data to help it determine what actions to perform upon receipt of the completion notice or to maintain additional information about the requested operation.

### `AsynchronousOpen` [in]

Specifies whether to block until the framework session has been opened. Specifying **FALSE** causes the process to block. Specifying **TRUE** causes the session to be opened asynchronously.

If you specify **FALSE** to open the framework session synchronously, success or failure is returned to the caller directly by this function in the **HRESULT** return value. If the session is opened successfully, the first asynchronous completion event your application receives will be for an asynchronous operation requested after the framework has been open.

If you specify **TRUE** to open the framework session asynchronously, the first asynchronous completion notice received will be for opening the framework. If the *NotificationMethod* parameter is set to **WINBIO_ASYNC_NOTIFY_CALLBACK**, operation results are delivered to the [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure in the callback function specified by the *CallbackRoutine* parameter. If the *NotificationMethod* parameter is set to **WINBIO_ASYNC_NOTIFY_MESSAGE**, operation results are delivered to the **WINBIO_ASYNC_RESULT** structure pointed to by the LPARAM field of the window message.

### `SessionHandle` [out, optional]

If the function does not succeed, this parameter will be **NULL**.

If the session is opened synchronously and successfully, this parameter will contain a pointer to the session handle.

If you specify that the session be opened asynchronously, this method returns immediately, the session handle will be **NULL**, and you must examine the [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure to determine whether the session was successfully opened.

## Return value

If the function succeeds, it returns **S_OK**. If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory available to create the biometric session. |
| **E_INVALIDARG** | If you set the notification method to **WINBIO_ASYNC_NOTIFY_MESSAGE**, the *TargetWindow* parameter cannot be **NULL** or **HWND_BROADCAST** and the *MessageCode* parameter cannot be zero (0). |
| **E_POINTER** | The *SessionHandle* parameter and the *AsynchronousOpen* parameter must be set.<br><br>If you set the notification method to **WINBIO_ASYNC_NOTIFY_CALLBACK**, you must also specify the address of a callback function in the *CallbackRoutine* parameter. |
| **E_ACCESSDENIED** | The *Flags* parameter contains the **WINBIO_FLAG_RAW** or the **WINBIO_FLAG_MAINTENANCE** flag and the caller has not been granted either access permission. |
| **WINBIO_E_INVALID_UNIT** | One or more of the biometric unit numbers specified in the *UnitArray* parameter is not valid. |
| **WINBIO_E_NOT_ACTIVE_CONSOLE** | The client application is running on a remote desktop client and is attempting to open a system pool session. |
| **WINBIO_E_SENSOR_UNAVAILABLE** | The *PoolType* parameter is set to **WINBIO_POOL_PRIVATE** and one or more of the requested sensors in that pool is not available. |
| **WINBIO_E_DISABLED** | Current administrative policy prohibits use of the Windows Biometric Framework API. |

## Remarks

The session handle returned by the **WinBioAsyncOpenSession** function can be used to generate asynchronous completion notifications for any of the following functions:

* [WinBioCancel](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiocancel)
* [WinBioCaptureSample](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiocapturesample)
* [WinBioCloseSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioclosesession)
* [WinBioControlUnit](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiocontrolunit)
* [WinBioControlUnitPrivileged](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiocontrolunitprivileged)
* [WinBioDeleteTemplate](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiodeletetemplate)
* [WinBioEnrollBegin](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollbegin)
* [WinBioEnrollCapture](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollcapture)
* [WinBioEnrollCommit](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollcommit)
* [WinBioEnrollDiscard](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrolldiscard)
* [WinBioEnumEnrollments](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenumenrollments)
* [WinBioGetProperty](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiogetproperty)
* [WinBioIdentify](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioidentify)
* [WinBioLocateSensor](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiolocatesensor)
* [WinBioLockUnit](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiolockunit)
* [WinBioLogonIdentifiedUser](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiologonidentifieduser)
* [WinBioRegisterEventMonitor](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioregistereventmonitor)
* [WinBioUnlockUnit](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiounlockunit)
* [WinBioUnregisterEventMonitor](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiounregistereventmonitor)
* [WinBioVerify](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioverify)
* [WinBioWait](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiowait)

The session handle returned by **WinBioAsyncOpenSession** cannot be used with the following functions:

* [WinBioCaptureSampleWithCallback](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiocapturesamplewithcallback)
* [WinBioEnrollCaptureWithCallback](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollcapturewithcallback)
* [WinBioIdentifyWithCallback](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioidentifywithcallback)
* [WinBioIdentifyWithCallback](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioidentifywithcallback)

These functions, first available in Windows 7, have an incompatible callback signature, and their use in new applications is discouraged. Developers who want asynchronous callbacks should instead use **WinBioAsyncOpenSession** with a *NotificationMethod* of **WINBIO_ASYNC_NOTIFY_CALLBACK**.

The *AsynchronousOpen* parameter determines only whether the open operation will block. This parameter has no effect on the completion behavior of subsequent calls that use the session handle.

If you set the *AsynchronousOpen* parameter to **TRUE**, this function will return **S_OK** as soon as it has performed an initial validation of the arguments. Any errors detected beyond that point will be reported to the caller using the method specified by the *NotificationMethod* parameter. That is, a successful return value indicates only that the **WinBioAsyncOpenSession** parameters were fine and not that the open operation succeeded. To determine whether the open operation succeeded, you must examine the [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure.

## See also

[WinBioAsyncOpenFramework](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopenframework)

[WinBioCloseSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioclosesession)

[WinBioOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioopensession)