# WinBioGetProperty function

## Description

Retrieves a session, unit, or template property. Starting with Windows 10, build 1607, this function is available to use with a mobile image.

## Parameters

### `SessionHandle` [in]

A **WINBIO_SESSION_HANDLE** value that identifies an open biometric session. Open a synchronous session handle by calling [WinBioOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioopensession). Open an asynchronous session handle by calling [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession).

### `PropertyType` [in]

A **WINBIO_PROPERTY_TYPE** value that specifies the source of the property information. Currently this must be **WINBIO_PROPERTY_TYPE_UNIT** or **WINBIO_PROPERTY_TYPE_ACCOUNT**. For more information about property types, see [WINBIO_PROPERTY_TYPE Constants](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-property-type-constants).

The **WINBIO_PROPERTY_TYPE_ACCOUNT** value is supported starting in Windows 10.

### `PropertyId` [in]

A **WINBIO_PROPERTY_ID** value that specifies the property that you want to query. The following values are possible.

| Value | Meaning |
| --- | --- |
| **WINBIO_PROPERTY_SAMPLE_HINT** | Estimates the maximum number of good biometric samples that are required to complete an enrollment template. The result of the property query is returned in the buffer to which to the *PropertyBuffer* parameter points as a **ULONG** value that contains the hint. |
| **WINBIO_PROPERTY_EXTENDED_SENSOR_INFO** | Contains extended information about the capabilities and attributes of the sensor component that is connected to a specific biometric unit. The result of the property query is returned in the buffer to which to the *PropertyBuffer* parameter points as a [WINBIO_EXTENDED_SENSOR_INFO](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-extended-sensor-info) structure. This value is supported starting in Windows 10. |
| **WINBIO_PROPERTY_EXTENDED_ENGINE_INFO** | Contains extended information about the capabilities and attributes of the engine component that is connected to a specific biometric unit. The result of the property query is returned in the buffer to which to the *PropertyBuffer* parameter points as a [WINBIO_EXTENDED_ENGINE_INFO](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-extended-engine-info) structure. This value is supported starting in Windows 10. |
| **WINBIO_PROPERTY_EXTENDED_STORAGE_INFO** | Contains extended information about the capabilities and attributes of the storage component that is connected to a specific biometric unit. The result of the property query is returned in the buffer to which to the *PropertyBuffer* parameter points as a [WINBIO_EXTENDED_STORAGE_INFO](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-extended-storage-info) structure. This value is supported starting in Windows 10. |
| **WINBIO_PROPERTY_EXTENDED_ENROLLMENT_STATUS** | Contains extended information about the status of an enrollment that is in progress on a specific biometric unit. The result of the property query is returned in the buffer to which to the *PropertyBuffer* parameter points as a [WINBIO_EXTENDED_ENROLLMENT_STATUS](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-extended-enrollment-status) structure. If no enrollment is in progress on the biometric unit, the **TemplateStatus** member of the returned structure has a value of **WINBIO_E_INVALID_OPERATION**. This value is supported starting in Windows 10. |
| **WINBIO_PROPERTY_ANTI_SPOOF_POLICY** | Contains the values of the antispoofing policy for a specific user account. The property operation is returned in the buffer to which to the *PropertyBuffer* parameter points as a [WINBIO_ANTI_SPOOF_POLICY](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-anti-spoof-policy) structure. This value is supported starting in Windows 10. |

For more information about these properties, see [WINBIO_PROPERTY Constants](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-property-constants).

### `UnitId` [in, optional]

A **WINBIO_UNIT_ID** value that identifies the biometric unit. You can find a unit identifier by calling the [WinBioEnumBiometricUnits](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenumbiometricunits) or [WinBioLocateSensor](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiolocatesensor) functions.

If you specify **WINBIO_PROPERTY_ANTI_SPOOF_POLICY** as the value for the *PropertyId* parameter, specify 0 for the *UnitId* parameter. If you specify any other property with the *PropertyId* parameter, you cannot specify 0 for the *UnitId* parameter.

### `Identity` [in, optional]

A [WINBIO_IDENTITY](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-identity) structure that provides the SID of the account for which you want to get the antispoofing policy, if you specify **WINBIO_PROPERTY_ANTI_SPOOF_POLICY** as the value of the *PropertyId* parameter.

If you specify any other value for the *PropertyId* parameter, the *Identity* parameter must be **NULL**.

### `SubFactor` [in, optional]

Reserved. This must be **WINBIO_SUBTYPE_NO_INFORMATION**.

### `PropertyBuffer`

Address of a pointer to a buffer that receives the property value. For information about the contents of this buffer for different properties, see the descriptions of the property values for the *PropertyId* parameter.

### `PropertyBufferSize` [out, optional]

Pointer to a variable that receives the size, in bytes, of the buffer pointed to by the *PropertyBuffer* parameter.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_HANDLE** | The session handle specified by the *SessionHandle* parameter is not valid. |
| **E_POINTER** | The *Identity*, *PropertyBuffer*, or *PropertyBufferSize* arguments cannot be **NULL**. |
| **E_INVALIDARG** | The *UnitId*, *Identity*, or *SubFactor* arguments are incorrect. |
| **WINBIO_E_INVALID_PROPERTY_TYPE** | The value of the *PropertyType* argument is incorrect. |
| **WINBIO_E_INVALID_PROPERTY_ID** | The value of the *PropertyId* argument is incorrect. |
| **WINBIO_E_LOCK_VIOLATION** | The caller attempted to query a property that resides inside of a locked region. |
| **WINBIO_E_UNSUPPORTED_PROPERTY** | The object being queried does not support the specified property. |
| **WINBIO_E_ENROLLMENT_IN_PROGRESS** | The operation could not be completed because the specified biometric unit is currently being used for an enrollment transaction (system pool only). |

## Remarks

To use **WinBioGetProperty** synchronously, call the function with a session handle created by calling [WinBioOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioopensession). The function blocks until the operation completes or an error is encountered. To prevent memory leaks when you use **WinBioGetProperty** synchronously, you must call [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) to release the memory pointed to by the *PropertyBuffer* parameter when you are finished using the data contained in the buffer.

To use **WinBioGetProperty** asynchronously, call the function with a session handle created by calling [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession). The framework allocates a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure and uses it to return information about operation success or failure. If the operation is successful, the framework returns information in a nested **GetProperty** structure. The **WINBIO_ASYNC_RESULT** structure is returned to the application callback or to the application message queue, depending on the value you set in the *NotificationMethod* parameter of the **WinBioAsyncOpenSession** function:

* If you choose to receive completion notices by using a callback, you must implement a [PWINBIO_ASYNC_COMPLETION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winbio/nc-winbio-pwinbio_async_completion_callback) function and set the *NotificationMethod* parameter to **WINBIO_ASYNC_NOTIFY_CALLBACK**.
* If you choose to receive completion notices by using the application message queue, you must set the *NotificationMethod* parameter to **WINBIO_ASYNC_NOTIFY_MESSAGE**. The framework returns a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) pointer to the **LPARAM** field of the window message.

To prevent memory leaks when you use **WinBioGetProperty** asynchronously, you must call [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) to release the [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure after you have finished using it. The **WINBIO_ASYNC_RESULT** structure and the property buffer occupy a single block of memory, so your application only needs to pass the address of the **WINBIO_ASYNC_RESULT** structure to **WinBioFree**. When you call **WinBioFree** this way, **WinBioFree** automatically releases both the **WINBIO_ASYNC_RESULT** structure and the property buffer. If you try to release the property buffer separately in this case, the application stops responding.

## See also

[WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree)

[WinBioSetProperty](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiosetproperty)