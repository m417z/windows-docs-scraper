# WinBioEnrollCapture function

## Description

Captures a biometric sample and adds it to a template. Starting with Windows 10, build 1607, this function is available to use with a mobile image.

## Parameters

### `SessionHandle` [in]

A **WINBIO_SESSION_HANDLE** value that identifies an open biometric session. Open a synchronous session handle by calling [WinBioOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioopensession). Open an asynchronous session handle by calling [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession).

### `RejectDetail` [out, optional]

A pointer to a **ULONG** value that contains additional information the failure to capture a biometric sample. If the capture succeeded, this parameter is set to zero. The following values are defined for fingerprint capture:

* WINBIO_FP_TOO_HIGH
* WINBIO_FP_TOO_LOW
* WINBIO_FP_TOO_LEFT
* WINBIO_FP_TOO_RIGHT
* WINBIO_FP_TOO_FAST
* WINBIO_FP_TOO_SLOW
* WINBIO_FP_POOR_QUALITY
* WINBIO_FP_TOO_SKEWED
* WINBIO_FP_TOO_SHORT
* WINBIO_FP_MERGE_FAILURE

## Return value

If the function succeeds, it returns S_OK. If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The calling account is not allowed to perform enrollment. |
| **E_HANDLE** | The session handle is not valid. |
| **E_POINTER** | The pointer specified by the *RejectDetail* parameter cannot be **NULL**. |
| **WINBIO_E_BAD_CAPTURE** | The sample could not be captured. Use the *RejectDetail* value for more information. |
| **WINBIO_E_LOCK_VIOLATION** | The biometric unit is in use and is locked. |
| **WINBIO_I_MORE_DATA** | The matching engine requires one or more additional samples to generate a reliable template. You should update instructions to the user to submit more samples and call [WinBioEnrollCapture](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollcapture) again. |

## Remarks

Any application that enrolls by using a biometric unit in the system pool must have window focus when it calls [WinBioEnrollBegin](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollbegin). If it does not, the call blocks until the application acquires window focus and the user has provided a biometric sample. We recommend, therefore, that your application not call **WinBioEnrollBegin** until it has acquired focus. The manner in which you acquire focus depends on the type of application you are writing. For example, if you are creating a GUI application you can implement a message handler that captures a WM_ACTIVATE, WM_SETFOCUS, or other appropriate message. If you are writing a CUI application, call **GetConsoleWindow** to retrieve a handle to the console window and pass that handle to the **SetForegroundWindow** function to force the console window into the foreground and assign it focus. If your application is running in a detached process and has no window or is a Windows service, use [WinBioAcquireFocus](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioacquirefocus) and [WinBioReleaseFocus](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioreleasefocus) to manually control focus.

To use **WinBioEnrollCapture** synchronously, call the function with a session handle created by calling [WinBioOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioopensession). The function blocks until the operation completes or an error is encountered.

To use **WinBioEnrollCapture** asynchronously, call the function with a session handle created by calling [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession). The framework allocates a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure and uses it to return information about operation success or failure. If the operation is unsuccessful, the framework returns **WINBIO_REJECT_DETAIL** information in a nested **EnrollCapture** structure. The **WINBIO_ASYNC_RESULT** structure is returned to the application callback or to the application message queue, depending on the value you set in the *NotificationMethod* parameter of the **WinBioAsyncOpenSession** function:

* If you choose to receive completion notices by using a callback, you must implement a [PWINBIO_ASYNC_COMPLETION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winbio/nc-winbio-pwinbio_async_completion_callback) function and set the *NotificationMethod* parameter to **WINBIO_ASYNC_NOTIFY_CALLBACK**.
* If you choose to receive completion notices by using the application message queue, you must set the *NotificationMethod* parameter to **WINBIO_ASYNC_NOTIFY_MESSAGE**. The framework returns a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) pointer to the **LPARAM** field of the window message.

To prevent memory leaks, you must call [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) from your callback implementation to release the [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure after you have finished using it.

**Windows 7:** You can perform this operation asynchronously by using the [WinBioEnrollCaptureWithCallback](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollcapturewithcallback) function. The function verifies the input arguments and returns immediately. If the input arguments are not valid, the function returns an error code. Otherwise, the framework starts the operation on another thread. When the asynchronous operation completes or encounters an error, the framework sends the results to the [PWINBIO_ENROLL_CAPTURE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winbio/nc-winbio-pwinbio_enroll_capture_callback) function implemented by your application.

#### Examples

The following function enrolls a biometric template in the system pool by calling **WinBioEnrollCapture**. Link to the Winbio.lib static library and include the following header files:

* Windows.h
* Stdio.h
* Conio.h
* Winbio.h

```cpp
HRESULT EnrollSysPool(
                      BOOL discardEnrollment,
                      WINBIO_BIOMETRIC_SUBTYPE subFactor)
{
    HRESULT hr = S_OK;
    WINBIO_IDENTITY identity = {0};
    WINBIO_SESSION_HANDLE sessionHandle = NULL;
    WINBIO_UNIT_ID unitId = 0;
    WINBIO_REJECT_DETAIL rejectDetail = 0;
    BOOLEAN isNewTemplate = TRUE;

    // Connect to the system pool.
    hr = WinBioOpenSession(
            WINBIO_TYPE_FINGERPRINT,    // Service provider
            WINBIO_POOL_SYSTEM,         // Pool type
            WINBIO_FLAG_DEFAULT,        // Configuration and access
            NULL,                       // Array of biometric unit IDs
            0,                          // Count of biometric unit IDs
            NULL,                       // Database ID
            &sessionHandle              // [out] Session handle
            );
    if (FAILED(hr))
    {
        wprintf_s(L"\n WinBioOpenSession failed. ");
        wprintf_s(L"hr = 0x%x\n", hr);
        goto e_Exit;
    }

    // Locate a sensor.
    wprintf_s(L"\n Swipe your finger on the sensor...\n");
    hr = WinBioLocateSensor( sessionHandle, &unitId);
    if (FAILED(hr))
    {
        wprintf_s(L"\n WinBioLocateSensor failed. hr = 0x%x\n", hr);
        goto e_Exit;
    }

    // Begin the enrollment sequence.
    wprintf_s(L"\n Starting enrollment sequence...\n");
    hr = WinBioEnrollBegin(
            sessionHandle,      // Handle to open biometric session
            subFactor,          // Finger to create template for
            unitId              // Biometric unit ID
            );
    if (FAILED(hr))
    {
        wprintf_s(L"\n WinBioEnrollBegin failed. hr = 0x%x\n", hr);
        goto e_Exit;
    }

    // Capture enrollment information by swiping the sensor with
    // the finger identified by the subFactor argument in the
    // WinBioEnrollBegin function.
    for (int swipeCount = 1;; ++swipeCount)
    {
        wprintf_s(L"\n Swipe the sensor to capture %s sample.",
                 (swipeCount == 1)?L"the first":L"another");

        hr = WinBioEnrollCapture(
                sessionHandle,  // Handle to open biometric session
                &rejectDetail   // [out] Failure information
                );

        wprintf_s(L"\n Sample %d captured from unit number %d.",
                  swipeCount,
                  unitId);

        if (hr == WINBIO_I_MORE_DATA)
        {
            wprintf_s(L"\n    More data required.\n");
            continue;
        }
        if (FAILED(hr))
        {
            if (hr == WINBIO_E_BAD_CAPTURE)
            {
                wprintf_s(L"\n  Error: Bad capture; reason: %d",
                          rejectDetail);
                continue;
            }
            else
            {
                wprintf_s(L"\n WinBioEnrollCapture failed. hr = 0x%x", hr);
                goto e_Exit;
            }
        }
        else
        {
            wprintf_s(L"\n    Template completed.\n");
            break;
        }
    }

    // Discard the enrollment if the appropriate flag is set.
    // Commit the enrollment if it is not discarded.
    if (discardEnrollment == TRUE)
    {
        wprintf_s(L"\n Discarding enrollment...\n\n");
        hr = WinBioEnrollDiscard( sessionHandle );
        if (FAILED(hr))
        {
            wprintf_s(L"\n WinBioLocateSensor failed. hr = 0x%x\n", hr);
        }
        goto e_Exit;
    }
    else
    {
        wprintf_s(L"\n Committing enrollment...\n");
        hr = WinBioEnrollCommit(
                sessionHandle,      // Handle to open biometric session
                &identity,          // WINBIO_IDENTITY object for the user
                &isNewTemplate);    // Is this a new template

        if (FAILED(hr))
        {
            wprintf_s(L"\n WinBioEnrollCommit failed. hr = 0x%x\n", hr);
            goto e_Exit;
        }
    }

e_Exit:
    if (sessionHandle != NULL)
    {
        WinBioCloseSession(sessionHandle);
        sessionHandle = NULL;
    }

    wprintf_s(L" Press any key to continue...");
    _getch();

    return hr;
}

```

## See also

[WinBioAcquireFocus](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioacquirefocus)

[WinBioEnrollBegin](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollbegin)

[WinBioEnrollCaptureWithCallback](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollcapturewithcallback)

[WinBioEnrollCommit](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollcommit)

[WinBioEnrollDiscard](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrolldiscard)

[WinBioReleaseFocus](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioreleasefocus)