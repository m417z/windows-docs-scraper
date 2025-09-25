# WinBioCaptureSample function

## Description

Captures a biometric sample and fills a biometric information record (BIR) with the raw or processed data.

## Parameters

### `SessionHandle` [in]

A **WINBIO_SESSION_HANDLE** value that identifies an open biometric session. Open a synchronous session handle by calling [WinBioOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioopensession). Open an asynchronous session handle by calling [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession).

### `Purpose` [in]

A **WINBIO_BIR_PURPOSE** bitmask that specifies the intended use of the sample. This can be a bitwise **OR** of the following values:

* **WINBIO_PURPOSE_VERIFY**
* **WINBIO_PURPOSE_IDENTIFY**
* **WINBIO_PURPOSE_ENROLL**
* **WINBIO_PURPOSE_ENROLL_FOR_VERIFICATION**
* **WINBIO_PURPOSE_ENROLL_FOR_IDENTIFICATION**

### `Flags` [in]

A value that specifies the type of processing to be applied to the captured sample. This can be a bitwise **OR** of the following security and processing level flags:

* **WINBIO_DATA_FLAG_PRIVACY**

Encrypt the sample.
* **WINBIO_DATA_FLAG_INTEGRITY**

Sign the sample or protect it by using a message authentication code (MAC)
* **WINBIO_DATA_FLAG_SIGNED**
If this flag and the WINBIO_DATA_FLAG_INTEGRITY flag are set, sign the sample. If this flag is not set but the WINBIO_DATA_FLAG_INTEGRITY flag is set, compute a MAC.
* **WINBIO_DATA_FLAG_RAW**

Return the sample exactly as it was captured by the sensor.
* **WINBIO_DATA_FLAG_INTERMEDIATE**

Return the sample after it has been cleaned and filtered.
* **WINBIO_DATA_FLAG_PROCESSED**
Return the sample after it is ready to be used for the purpose specified by the Purpose parameter.

### `UnitId` [out, optional]

A pointer to a **WINBIO_UNIT_ID** value that contains the ID of the biometric unit that generated the sample.

### `Sample`

Address of a variable that receives a pointer to a [WINBIO_BIR](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-bir) structure that contains the sample. When you have finished using the structure, you must pass the pointer to [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) to release the memory allocated for the sample.

### `SampleSize` [out, optional]

A pointer to a **SIZE_T** value that contains the size, in bytes, of the [WINBIO_BIR](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-bir) structure returned in the *Sample* parameter.

### `RejectDetail` [out, optional]

A pointer to a **WINBIO_REJECT_DETAIL** value that contains additional information about the failure to capture a biometric sample. If the capture succeeded, this parameter is set to zero. The following values are defined for fingerprint capture:

* **WINBIO_FP_TOO_HIGH**
* **WINBIO_FP_TOO_LOW**
* **WINBIO_FP_TOO_LEFT**
* **WINBIO_FP_TOO_RIGHT**
* **WINBIO_FP_TOO_FAST**
* **WINBIO_FP_TOO_SLOW**
* **WINBIO_FP_POOR_QUALITY**
* **WINBIO_FP_TOO_SKEWED**
* **WINBIO_FP_TOO_SHORT**
* **WINBIO_FP_MERGE_FAILURE**

## Return value

If the function succeeds, it returns **S_OK**. If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| ****E_ACCESSDENIED**** | The caller does not have permission to capture raw samples, or the session was not opened by using the **WINBIO_FLAG_RAW** flag. |
| ****E_HANDLE**** | The session handle is not valid. |
| **E_NOTIMPL** | The biometric unit does not support the requested operation. |
| **E_POINTER** | The *UnitId*, *Sample*, *SampleSize*, and *RejectDetail* pointers cannot be **NULL**. |
| **WINBIO_E_ENROLLMENT_IN_PROGRESS** | The operation could not be completed because the biometric unit is currently being used for an enrollment transaction (system pool only). |
| **WINBIO_E_INVALID_OPERATION** | The operation could not be completed because a secure sensor is present in the sensor pool. |

## Remarks

To call this function successfully, you must open the session handle by specifying **WINBIO_FLAG_RAW** in the *Flags* parameter of the [WinBioOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioopensession) or [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession) functions. Currently, only applications running under the Administrators and Local System accounts have the necessary privileges.

Valid combinations of the *Purpose* and *Flags* parameters depend on the capabilities of the biometric unit being used. Consult the vendor's sensor documentation to determine which combinations of valid *Purpose* and *Flags* values are supported and how they affect the captured data.
After you are finished using the sample, your application must call [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) to release the memory allocated for it by the **WinBioCaptureSample** function.

To use **WinBioCaptureSample** synchronously, call the function with a session handle created by calling [WinBioOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioopensession). The function blocks until a sample has been captured or an error is encountered. Calls to **WinBioCaptureSample** using the system pool will block until the calling application has window focus and the user provides a sample to one of the sensors in the pool. If the sensor chosen by the user is already being used for an enrollment transaction, the function fails and returns **WINBIO_E_ENROLLMENT_IN_PROGRESS**.

To use **WinBioCaptureSample** asynchronously, call the function with a session handle created by calling [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession). The framework allocates a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure and uses it to return information about operation success or failure. If the capture operation is successful, the framework returns information about the sample in a nested **CaptureSample** structure. If the operation is unsuccessful, the framework returns error information. The **WINBIO_ASYNC_RESULT** structure is returned to the application callback or to the application message queue, depending on the value you set in the *NotificationMethod* parameter of the **WinBioAsyncOpenSession** function:

* If you choose to receive completion notices by using a callback, you must implement a [PWINBIO_ASYNC_COMPLETION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winbio/nc-winbio-pwinbio_async_completion_callback) function and set the *NotificationMethod* parameter to **WINBIO_ASYNC_NOTIFY_CALLBACK**.
* If you choose to receive completion notices by using the application message queue, you must set the *NotificationMethod* parameter to **WINBIO_ASYNC_NOTIFY_MESSAGE**. The framework returns a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) pointer to the **LPARAM** field of the window message.

To prevent memory leaks, you must call [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) to release the [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure after you have finished using it.

**Windows 7:** You can perform this operation asynchronously by using the [WinBioCaptureSampleWithCallback](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiocapturesamplewithcallback) function. The function verifies the input arguments and returns immediately. If the input arguments are not valid, the function returns an error code. Otherwise, the framework starts the operation on another thread. When the asynchronous operation completes or encounters an error, the framework sends the results to the [PWINBIO_CAPTURE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winbio/nc-winbio-pwinbio_capture_callback) function implemented by your application.

#### Examples

The following function calls **WinBioCaptureSample** to capture a biometric sample from a user. Link to the Winbio.lib static library and include the following header files:

* Windows.h
* Stdio.h
* Conio.h
* Winbio.h

```cpp
HRESULT CaptureSample()
{
    HRESULT hr = S_OK;
    WINBIO_SESSION_HANDLE sessionHandle = NULL;
    WINBIO_UNIT_ID unitId = 0;
    WINBIO_REJECT_DETAIL rejectDetail = 0;
    PWINBIO_BIR sample = NULL;
    SIZE_T sampleSize = 0;

    // Connect to the system pool.
    hr = WinBioOpenSession(
            WINBIO_TYPE_FINGERPRINT,    // Service provider
            WINBIO_POOL_SYSTEM,         // Pool type
            WINBIO_FLAG_RAW,            // Access: Capture raw data
            NULL,                       // Array of biometric unit IDs
            0,                          // Count of biometric unit IDs
            WINBIO_DB_DEFAULT,          // Default database
            &sessionHandle              // [out] Session handle
            );
    if (FAILED(hr))
    {
        wprintf_s(L"\n WinBioOpenSession failed. hr = 0x%x\n", hr);
        goto e_Exit;
    }

    // Capture a biometric sample.
    wprintf_s(L"\n Calling WinBioCaptureSample - Swipe sensor...\n");
    hr = WinBioCaptureSample(
            sessionHandle,
            WINBIO_NO_PURPOSE_AVAILABLE,
            WINBIO_DATA_FLAG_RAW,
            &unitId,
            &sample,
            &sampleSize,
            &rejectDetail
            );
    if (FAILED(hr))
    {
        if (hr == WINBIO_E_BAD_CAPTURE)
        {
            wprintf_s(L"\n Bad capture; reason: %d\n", rejectDetail);
        }
        else
        {
            wprintf_s(L"\n WinBioCaptureSample failed. hr = 0x%x\n", hr);
        }
        goto e_Exit;
    }

    wprintf_s(L"\n Swipe processed - Unit ID: %d\n", unitId);
    wprintf_s(L"\n Captured %d bytes.\n", sampleSize);

e_Exit:
    if (sample != NULL)
    {
        WinBioFree(sample);
        sample = NULL;
    }

    if (sessionHandle != NULL)
    {
        WinBioCloseSession(sessionHandle);
        sessionHandle = NULL;
    }

    wprintf_s(L"\n Press any key to exit...");
    _getch();

    return hr;
}

```

## See also

[WinBioCaptureSampleWithCallback](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiocapturesamplewithcallback)