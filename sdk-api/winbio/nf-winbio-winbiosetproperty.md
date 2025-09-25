# WinBioSetProperty function

## Description

Sets the value of a standard property associated with a biometric session, unit, template, or account. Starting with Windows 10, build 1607, this function is available to use with a mobile image.

## Parameters

### `SessionHandle` [in]

A **WINBIO_SESSION_HANDLE** value that identifies an open biometric session. Open a synchronous session handle by calling [WinBioOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioopensession). Open an asynchronous session handle by calling [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession).

### `PropertyType` [in]

A **WINBIO_PROPERTY_TYPE** value that specifies the type of the property that you want to set. Currently this must be **WINBIO_PROPERTY_TYPE_ACCOUNT**.

### `PropertyId` [in]

A **WINBIO_PROPERTY_ID** value that specifies the property to set. Currently this must be **WINBIO_PROPERTY_ANTI_SPOOF_POLICY**. All other properties are read-only.

### `UnitId` [in, optional]

A **WINBIO_UNIT_ID** value that identifies the biometric unit. For the **WINBIO_PROPERTY_ANTI_SPOOF_POLICY** property, this value must be 0.

### `Identity` [in, optional]

Address of a [WINBIO_IDENTITY](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-identity) structure that specifies the account for which you want to set the property.

### `SubFactor` [in, optional]

Reserved. This must be **WINBIO_SUBTYPE_NO_INFORMATION**.

### `PropertyBuffer` [in]

A pointer to a structure that specifies the new value for the property. This value cannot be NULL. For setting the **WINBIO_PROPERTY_ANTI_SPOOF_POLICY** property, the structure must be a [WINBIO_ANTI_SPOOF_POLICY](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-anti-spoof-policy) structure.

### `PropertyBufferSize` [in]

The size, in bytes, of the structure to which the *PropertyBuffer* parameter points. This value cannot be 0.

## Return value

If the function succeeds, it returns **S_OK**. If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_HANDLE** | The session handle specified by the *SessionHandle* parameter is not valid. |
| **E_POINTER** | The *Identity* and *PropertyBuffer* parameters cannot be **NULL**. |
| **E_INVALIDARG** | The *PropertyType*, *PropertyId*, or *PropertyBufferSize* parameter cannot be 0. |
| **WINBIO_E_INVALID_PROPERTY_TYPE** | The value of the *PropertyType* argument is incorrect. |
| **WINBIO_E_INVALID_PROPERTY_ID** | The value of the *PropertyId* argument is incorrect. |
| **WINBIO_E_LOCK_VIOLATION** | The caller attempted to set a property that resides inside of a locked region. |
| **WINBIO_E_UNSUPPORTED_PROPERTY** | The object does not support the specified property. |
| **WINBIO_E_ENROLLMENT_IN_PROGRESS** | The operation could not be completed because the specified biometric unit is currently being used for an enrollment transaction (system pool only). |

## Remarks

To use **WinBioSetProperty** synchronously, call the function with a session handle created by calling [WinBioOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioopensession). The function blocks until the operation completes or an error is encountered. To prevent memory leaks, you must call [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) to release the memory pointed to by the *PropertyBuffer* parameter when you are finished using the data contained in the buffer.

To use **WinBioSetProperty** asynchronously, call the function with a session handle created by calling [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession). The framework allocates a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure and uses it to return information about operation success or failure. The **WINBIO_ASYNC_RESULT** structure is returned to the application callback or to the application message queue, depending on the value you set in the *NotificationMethod* parameter of the **WinBioAsyncOpenSession** function:

* If you choose to receive completion notices by using a callback, you must implement a [PWINBIO_ASYNC_COMPLETION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winbio/nc-winbio-pwinbio_async_completion_callback) function and set the *NotificationMethod* parameter to **WINBIO_ASYNC_NOTIFY_CALLBACK**.
* If you choose to receive completion notices by using the application message queue, you must set the *NotificationMethod* parameter to **WINBIO_ASYNC_NOTIFY_MESSAGE**. The framework returns a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) pointer to the **LPARAM** field of the window message.

To prevent memory leaks, you must call [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) to release the [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure after you have finished using it.

## See also

[WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree)

[WinBioGetProperty](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiogetproperty)