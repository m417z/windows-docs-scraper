# WinBioControlUnit function

## Description

Allows the caller to perform vendor-defined control operations on a biometric unit. Starting with Windows 10, build 1607, this function is available to use with a mobile image. This function is provided for access to extended vendor operations for which elevated privileges are not required. If access rights are required, call the [WinBioControlUnitPrivileged](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiocontrolunitprivileged) function.

## Parameters

### `SessionHandle` [in]

A **WINBIO_SESSION_HANDLE** value that identifies an open biometric session. Open a synchronous session handle by calling [WinBioOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioopensession). Open an asynchronous session handle by calling [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession).

### `UnitId` [in]

A **WINBIO_UNIT_ID** value that identifies the biometric unit. This value must correspond to the unit ID used previously in the [WinBioLockUnit](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiolockunit) function.

### `Component` [in]

A **WINBIO_COMPONENT** value that specifies the component within the biometric unit that should perform the operation. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **WINBIO_COMPONENT_SENSOR** | Send the command to the sensor adapter. |
| **WINBIO_COMPONENT_ENGINE** | Send the command to the engine adapter. |
| **WINBIO_COMPONENT_STORAGE** | Send the command to the storage adapter. |

### `ControlCode` [in]

A vendor-defined code recognized by the biometric unit specified by the *UnitId* parameter and the adapter specified by the *Component* parameter.

### `SendBuffer`

Address of the buffer that contains the control information to be sent to the adapter specified by the *Component* parameter. The format and content of the buffer is vendor-defined.

### `SendBufferSize` [in]

Size, in bytes, of the buffer specified by the *SendBuffer* parameter.

### `ReceiveBuffer`

Address of the buffer that receives information sent by the adapter specified by the *Component* parameter. The format and content of the buffer is vendor-defined.

### `ReceiveBufferSize` [in]

Size, in bytes, of the buffer specified by the *ReceiveBuffer* parameter.

### `ReceiveDataSize`

Pointer to a **SIZE_T** value that contains the size, in bytes, of the data written to the buffer specified by the *ReceiveBuffer* parameter.

### `OperationStatus` [out, optional]

Pointer to an integer that contains a vendor-defined status code that specifies the outcome of the control operation.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| ****E_HANDLE**** | The session handle is not valid. |
| ****E_INVALIDARG**** | The value specified in the *ControlCode* parameter is not recognized. |
| ****E_POINTER**** | The *SendBuffer*, *ReceiveBuffer*, *ReceiveDataSize*, *OperationStatus* parameters cannot be **NULL**. |
| ****WINBIO_E_INVALID_CONTROL_CODE**** | The value specified in the *ControlCode* parameter is not recognized. |
| ****WINBIO_E_LOCK_VIOLATION**** | The biometric unit specified by the *UnitId* parameter must be locked before any control operations can be performed. |

## Remarks

You must call [WinBioLockUnit](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiolockunit) before calling **WinBioControlUnit**. The **WinBioLockUnit** function creates a locked region in which vendor-defined operations can be securely performed.

Vendors who create plug-ins must decide which extended operations are privileged and which are available to all clients. To perform a privileged operation, the client application must call the [WinBioControlUnitPrivileged](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiocontrolunitprivileged) function. The Windows Biometric Framework allows only clients that have the appropriate access rights to call **WinBioControlUnitPrivileged**.

To use **WinBioControlUnit** synchronously, call the function with a session handle created by calling [WinBioOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioopensession). The function blocks until the operation completes or an error is encountered.

To use **WinBioControlUnit** asynchronously, call the function with a session handle created by calling [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession). The framework allocates a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure and uses it to return information about operation success or failure. The **WINBIO_ASYNC_RESULT** structure is returned to the application callback or to the application message queue, depending on the value you set in the *NotificationMethod* parameter of the **WinBioAsyncOpenSession** function.

* If you choose to receive completion notices by using a callback, you must implement a [PWINBIO_ASYNC_COMPLETION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winbio/nc-winbio-pwinbio_async_completion_callback) function and set the *NotificationMethod* parameter to **WINBIO_ASYNC_NOTIFY_CALLBACK**.
* If you choose to receive completion notices by using the application message queue, you must set the *NotificationMethod* parameter to **WINBIO_ASYNC_NOTIFY_MESSAGE**. The framework returns a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) pointer to the **LPARAM** field of the window message.

To prevent memory leaks, you must call [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) to release the [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure after you have finished using it.

## See also

[WinBioControlUnitPrivileged](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiocontrolunitprivileged)

[WinBioLockUnit](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiolockunit)