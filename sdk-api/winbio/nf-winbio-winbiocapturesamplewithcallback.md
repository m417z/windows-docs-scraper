# WinBioCaptureSampleWithCallback function

## Description

Captures a biometric sample asynchronously and returns the raw or processed data in a biometric information record (BIR). The function returns immediately to the caller, captures the sample on a separate thread, and calls into an application-defined callback function to update operation status.

**Important**

We recommend that, beginning with Windows 8, you no longer use this function to start an asynchronous operation. Instead, do the following:

* Implement a [PWINBIO_ASYNC_COMPLETION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winbio/nc-winbio-pwinbio_async_completion_callback) function to receive notice when the operation completes.
* Call the [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession) function. Pass the address of your callback in the *CallbackRoutine* parameter. Pass **WINBIO_ASYNC_NOTIFY_CALLBACK** in the *NotificationMethod* parameter. Retrieve an asynchronous session handle.
* Use the asynchronous session handle to call [WinBioCaptureSample](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiocapturesample). When the operation finishes, the Windows Biometric Framework will allocate and initialize a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure with the results and invoke your callback with a pointer to the results structure.
* Call [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) from your callback implementation to release the [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure after you have finished using it.

## Parameters

### `SessionHandle` [in]

A **WINBIO_SESSION_HANDLE** value that identifies an open biometric session.

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

Sign the sample or protect it by using a message authentication code (MAC).

* **WINBIO_DATA_FLAG_SIGNED**

If this flag and the WINBIO_DATA_FLAG_INTEGRITYflag are set, sign the sample. If this flag is not set but the WINBIO_DATA_FLAG_INTEGRITY flag is set, compute a MAC.

* **WINBIO_DATA_FLAG_RAW**

Return the sample exactly as it was captured by the sensor.

* **WINBIO_DATA_FLAG_INTERMEDIATE**

Return the sample after it has been cleaned and filtered.

* **WINBIO_DATA_FLAG_PROCESSED**

Return the sample after it is ready to be used for the purpose specified by the Purpose parameter.

### `CaptureCallback` [in]

Address of a callback function that will be called by the **WinBioCaptureSampleWithCallback** function when the capture operation succeeds or fails. You must create the callback.

### `CaptureCallbackContext` [in, optional]

Address of an application-defined data structure that is passed to the callback function in its *CaptureCallbackContext* parameter. This structure can contain any data that the custom callback function is designed to handle.

## Return value

If the function succeeds, it returns **S_OK**. If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| ****E_ACCESSDENIED**** | The caller does not have permission to capture raw samples, or the session was not opened by using the **WINBIO_FLAG_RAW** flag. |
| ****E_HANDLE**** | The session handle is not valid. |
| **E_NOTIMPL** | The biometric unit does not support the requested operation. |
| **E_POINTER** | The *UnitId*, *Sample*, *SampleSize*, and *RejectDetail* pointers cannot be **NULL**. |
| **WINBIO_E_ENROLLMENT_IN_PROGRESS** | The operation could not be completed because the biometric unit is currently being used for an enrollment transaction (system pool only). |

## Remarks

The **WinBioCaptureSampleWithCallback** function captures samples asynchronously. To call this function successfully, the session handle must have been opened by specifying **WINBIO_FLAG_RAW**. Only the Administrators and Local System accounts have the necessary privileges.

Valid combinations of the *Purpose* and *Flags* parameters depend on the capabilities of the biometric unit being used. Consult the vendor sensor documentation to determine what combinations are supported and how they affect the captured data.

Callers are responsible for releasing the [WINBIO_BIR](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-bir) structure returned by the *Sample* parameter.

The callback routine must have the following signature:

```cpp
VOID CALLBACK CaptureCallback(
__in_opt PVOID CaptureCallbackContext,
__in HRESULT OperationStatus,
__in WINBIO_UNIT_ID UnitId,
__in_bcount(SampleSize) PWINBIO_BIR Sample,
__in SIZE_T SampleSize,
__in WINBIO_REJECT_DETAIL RejectDetail
);

```

#### Examples

The following code example captures a sample asynchronously by calling **WinBioCaptureSampleWithCallback** and passing a pointer to a custom callback function. The callback function, CaptureSampleCallback, is also shown. Link to the Winbio.lib static library and include the following header files:

* Windows.h
* Stdio.h
* Conio.h
* Winbio.h

```cpp
HRESULT CaptureSampleWithCallback(BOOL bCancel)
{
    HRESULT hr = S_OK;
    WINBIO_SESSION_HANDLE sessionHandle = NULL;

    // Connect to the system pool.
    hr = WinBioOpenSession(
            WINBIO_TYPE_FINGERPRINT,    // Service provider
            WINBIO_POOL_SYSTEM,         // Pool type
            WINBIO_FLAG_RAW,            // Raw access
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

    // Capture a biometric sample asynchronously.
    wprintf_s(L"\n Calling WinBioCaptureSampleWithCallback ");
    hr = WinBioCaptureSampleWithCallback(
            sessionHandle,                  // Open session handle
            WINBIO_NO_PURPOSE_AVAILABLE,    // Intended use of the sample
            WINBIO_DATA_FLAG_RAW,           // Sample format
            CaptureSampleCallback,          // Callback function
            NULL                            // Optional context
            );
    if (FAILED(hr))
    {
        wprintf_s(L"\n WinBioCaptureSampleWithCallback failed. ");
        wprintf_s(L"hr = 0x%x\n", hr);
        goto e_Exit;
    }
    wprintf_s(L"\n Swipe the sensor ...\n");

    // Cancel the capture process if the bCancel flag is set.
    if (bCancel)
    {
        wprintf_s(L"\n Starting CANCEL timer...");
        Sleep( 7000 );

        wprintf_s(L"\n Calling WinBioCancel\n");
        hr = WinBioCancel( sessionHandle );
        if (FAILED(hr))
        {
            wprintf_s(L"\n WinBioCancel failed. hr = 0x%x\n", hr);
            goto e_Exit;
        }
    }

    // Wait for the asynchronous capture process to complete
    // or be canceled.
    hr = WinBioWait( sessionHandle );
    if (FAILED(hr))
    {
        wprintf_s(L"\n WinBioWait failed. hr = 0x%x\n", hr);
    }

e_Exit:

    if (sessionHandle != NULL)
    {
        WinBioCloseSession(sessionHandle);
        sessionHandle = NULL;
    }

    wprintf_s(L"\n Press any key to exit...");
    _getch();

    return hr;
}

//------------------------------------------------------------------------
// The following function is the callback for WinBioCaptureSampleWithCallback.
// The function filters the response from the biometric subsystem and
// writes a result to the console window.
//
VOID CALLBACK CaptureSampleCallback(
    __in_opt PVOID CaptureCallbackContext,
    __in HRESULT OperationStatus,
    __in WINBIO_UNIT_ID UnitId,
    __in_bcount(SampleSize) PWINBIO_BIR Sample,
    __in SIZE_T SampleSize,
    __in WINBIO_REJECT_DETAIL RejectDetail
    )
{
    UNREFERENCED_PARAMETER(CaptureCallbackContext);

    wprintf_s(L"\n CaptureSampleCallback executing");
    wprintf_s(L"\n Swipe processed - Unit ID: %d", UnitId);

    if (FAILED(OperationStatus))
    {
        if (OperationStatus == WINBIO_E_BAD_CAPTURE)
        {
            wprintf_s(L"\n Bad capture; reason: %d\n", RejectDetail);
         }
        else
        {
            wprintf_s(L"\n WinBioCaptureSampleWithCallback failed. ");
            wprintf_s(L" OperationStatus = 0x%x\n", OperationStatus);
        }
        goto e_Exit;
    }

    wprintf_s(L"\n Captured %d bytes.\n", SampleSize);

e_Exit:

    if (Sample != NULL)
    {
        WinBioFree(Sample);
        Sample = NULL;
    }
}

```

## See also

[WinBioCaptureSample](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiocapturesample)