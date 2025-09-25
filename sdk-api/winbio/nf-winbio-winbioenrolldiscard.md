# WinBioEnrollDiscard function

## Description

Ends the enrollment sequence and discards a pending biometric template. Starting with Windows 10, build 1607, this function is available to use with a mobile image.

## Parameters

### `SessionHandle` [in]

A **WINBIO_SESSION_HANDLE** value that identifies an open biometric session. Open a synchronous session handle by calling [WinBioOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioopensession). Open an asynchronous session handle by calling [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession).

## Return value

If the function succeeds, it returns S_OK. If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The caller does not have permission to enroll. |
| ****E_HANDLE**** | The session handle is not valid. |
| ****WINBIO_E_LOCK_VIOLATION**** | The biometric unit is in use and is locked. |

## Remarks

You can use this function to allow a user to stop an enrollment sequence before saving a biometric template to the template database.

To use **WinBioEnrollDiscard** synchronously, call the function with a session handle created by calling [WinBioOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioopensession). The function blocks until the operation completes or an error is encountered.

To use **WinBioEnrollDiscard** asynchronously, call the function with a session handle created by calling [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession). The framework allocates a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure and uses it to return information about operation success or failure. The **WINBIO_ASYNC_RESULT** structure is returned to the application callback or to the application message queue, depending on the value you set in the *NotificationMethod* parameter of the **WinBioAsyncOpenSession** function:

* If you choose to receive completion notices by using a callback, you must implement a [PWINBIO_ASYNC_COMPLETION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winbio/nc-winbio-pwinbio_async_completion_callback) function and set the *NotificationMethod* parameter to **WINBIO_ASYNC_NOTIFY_CALLBACK**.
* If you choose to receive completion notices by using the application message queue, you must set the *NotificationMethod* parameter to **WINBIO_ASYNC_NOTIFY_MESSAGE**. The framework returns a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) pointer to the **LPARAM** field of the window message.

To prevent memory leaks, you must call [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) to release the [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure after you have finished using it.

#### Examples

The following function enrolls a biometric template in the system pool. You can pass a Boolean value to the function which enables you to discard an enrollment by calling **WinBioEnrollDiscard**. Link to the Winbio.lib static library and include the following header files:

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

[WinBioEnrollBegin](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollbegin)

[WinBioEnrollCapture](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollcapture)

[WinBioEnrollCaptureWithCallback](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollcapturewithcallback)

[WinBioEnrollDiscard](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrolldiscard)