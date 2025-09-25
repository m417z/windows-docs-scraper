# WinBioEnrollCaptureWithCallback function

## Description

Asynchronously captures a biometric sample and adds it to a template. The function returns immediately to the caller, performs enrollment on a separate thread, and calls into an application-defined callback function to update operation status.

**Important**

We recommend that, beginning with Windows 8, you no longer use this function to start an asynchronous operation. Instead, do the following:

* Implement a [PWINBIO_ASYNC_COMPLETION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winbio/nc-winbio-pwinbio_async_completion_callback) function to receive notice when the operation completes.
* Call the [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession) function. Pass the address of your callback in the *CallbackRoutine* parameter. Pass **WINBIO_ASYNC_NOTIFY_CALLBACK** in the *NotificationMethod* parameter. Retrieve an asynchronous session handle.
* Use the asynchronous session handle to call [WinBioEnrollCapture](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollcapture). When the operation finishes, the Windows Biometric Framework will allocate and initialize a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure with the results and invoke your callback with a pointer to the results structure.
* Call [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) from your callback implementation to release the [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure after you have finished using it.

## Parameters

### `SessionHandle` [in]

A **WINBIO_SESSION_HANDLE** value that identifies an open biometric session.

### `EnrollCallback` [in]

Address of a callback function that will be called by the **WinBioEnrollCaptureWithCallback** function when the capture operation succeeds or fails. You must create the callback.

### `EnrollCallbackContext` [in, optional]

Pointer to an optional application-defined structure that is passed to the *EnrollCallbackContext* parameter of the callback function. This structure can contain any data that the custom callback function is designed to handle.

## Return value

If the function succeeds, it returns **S_OK**. If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| ****E_ACCESSDENIED**** | The calling account is not allowed to perform enrollment. |
| ****E_HANDLE**** | The session handle is not valid. |
| ****E_POINTER**** | The pointer specified by the *EnrollCallback* parameter cannot be **NULL**. |

## Remarks

If the *SessionHandle* parameter refers to the system sensor pool, the callback function will not be called until the application acquires window focus and the user has provided a biometric sample. The manner in which you acquire focus depends on the type of application you are writing. For example, if you are creating a GUI application you can implement a message handler that captures a [WM_ACTIVATE](https://learn.microsoft.com/windows/desktop/inputdev/wm-activate), [WM_SETFOCUS](https://learn.microsoft.com/windows/desktop/inputdev/wm-setfocus), or other appropriate message. If you are writing a CUI application, call **GetConsoleWindow** to retrieve a handle to the console window and pass that handle to the **SetForegroundWindow** function to force the console window into the foreground and assign it focus. If your application is running in a detached process and has no window or is a Windows service, use [WinBioAcquireFocus](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioacquirefocus) and [WinBioReleaseFocus](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioreleasefocus) to manually control focus.

#### Examples

The following code example enrolls a fingerprint asynchronously by calling **WinBioEnrollCaptureWithCallback** and passing a pointer to a custom callback function. The callback function, EnrollCaptureCallback, is also shown. Link to the Winbio.lib static library.

```cpp
//------------------------------------------------------------------------
// EnrollSystemPoolWithCallback.cpp : console application entry point.
//

#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <winbio.h>

//------------------------------------------------------------------------
// Forward declarations.
//
HRESULT EnrollSysPoolWithCallback(
                      BOOL bCancel,
                      BOOL bDiscard,
                      WINBIO_BIOMETRIC_SUBTYPE subFactor);

VOID CALLBACK EnrollCaptureCallback(
                      __in_opt PVOID EnrollCallbackContext,
                      __in HRESULT OperationStatus,
                      __in WINBIO_REJECT_DETAIL RejectDetail);

typedef struct _ENROLL_CALLBACK_CONTEXT {
    WINBIO_SESSION_HANDLE SessionHandle;
    WINBIO_UNIT_ID UnitId;
    WINBIO_BIOMETRIC_SUBTYPE SubFactor;
} ENROLL_CALLBACK_CONTEXT, *PENROLL_CALLBACK_CONTEXT;

//------------------------------------------------------------------------
int wmain()
{
    HRESULT hr = S_OK;

    hr = EnrollSysPoolWithCallback(
                      FALSE,
                      FALSE,
                      WINBIO_ANSI_381_POS_RH_INDEX_FINGER);

    return 0;
}

//------------------------------------------------------------------------
// The following function enrolls a user's fingerprint in the system pool.
// The function calls WinBioEnrollCaptureWithCallback and waits for the
// asynchronous enrollment process to be completed or canceled.
//
HRESULT EnrollSysPoolWithCallback(
                      BOOL bCancel,
                      BOOL bDiscard,
                      WINBIO_BIOMETRIC_SUBTYPE subFactor)
{
    // Declare variables
    HRESULT hr = S_OK;
    WINBIO_IDENTITY identity = {0};
    WINBIO_SESSION_HANDLE sessionHandle = NULL;
    WINBIO_UNIT_ID unitId = 0;
    BOOLEAN isNewTemplate = TRUE;
    ENROLL_CALLBACK_CONTEXT callbackContext = {0};

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
        wprintf_s(L"\n WinBioEnumBiometricUnits failed. ");
        wprintf_s(L"hr = 0x%x\n", hr);
        goto e_Exit;
    }

    // Locate the sensor.
    wprintf_s(L"\n Swipe your finger to locate the sensor...\n");
    hr = WinBioLocateSensor( sessionHandle, &unitId);
    if (FAILED(hr))
    {
        wprintf_s(L"\n WinBioLocateSensor failed. hr = 0x%x\n", hr);
        goto e_Exit;
    }

    // Begin the enrollment sequence.
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

    // Set up the custom callback context structure.
    callbackContext.SessionHandle = sessionHandle;
    callbackContext.UnitId = unitId;
    callbackContext.SubFactor = subFactor;

    // Call WinBioEnrollCaptureWithCallback. This is an asynchronous
    // method that returns immediately.
    hr = WinBioEnrollCaptureWithCallback(
            sessionHandle,          // Handle to open biometric session
            EnrollCaptureCallback,  // Callback function
            &callbackContext        // Pointer to the custom context
            );
    if (FAILED(hr))
    {
        wprintf_s(L"\n WinBioEnrollCaptureWithCallback failed. ");
        wprintf_s(L"hr = 0x%x\n", hr);
        goto e_Exit;
    }
    wprintf_s(L"\n Swipe the sensor with the appropriate finger...\n");

    // Cancel the enrollment if the bCancel flag is set.
    if (bCancel)
    {
        wprintf_s(L"\n Starting CANCEL timer...\n");
        Sleep( 7000 );

        wprintf_s(L"\n Calling WinBioCancel\n");
        hr = WinBioCancel( sessionHandle );
        if (FAILED(hr))
        {
            wprintf_s(L"\n WinBioCancel failed. hr = 0x%x\n", hr);
            goto e_Exit;
        }
    }

    // Wait for the asynchronous enrollment process to complete
    // or be canceled.
    hr = WinBioWait( sessionHandle );
    if (FAILED(hr))
    {
        wprintf_s(L"\n WinBioWait failed. hr = 0x%x\n", hr);
    }

    // Discard the enrollment if the bDiscard flag is set.
    // Commit the enrollment if the flag is not set.
    if (bDiscard)
    {
        wprintf_s(L"\n Discarding enrollment...\n");
        hr = WinBioEnrollDiscard( sessionHandle );
        if (FAILED(hr))
        {
            wprintf_s(L"\n WinBioLocateSensor failed. ");
            wprintf_s(L"hr = 0x%x\n", hr);
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

    wprintf_s(L"\n Press any key to exit...");
    _getch();

    return hr;
}

//------------------------------------------------------------------------
// The following function is the callback for the Windows Biometric
// Framework WinBioEnrollCaptureWithCallback() function.
//
VOID CALLBACK EnrollCaptureCallback(
    __in_opt PVOID EnrollCallbackContext,
    __in HRESULT OperationStatus,
    __in WINBIO_REJECT_DETAIL RejectDetail
    )
{
    // Declare variables.
    HRESULT hr = S_OK;
    static SIZE_T swipeCount = 1;

    PENROLL_CALLBACK_CONTEXT callbackContext =
        (PENROLL_CALLBACK_CONTEXT)EnrollCallbackContext;

    wprintf_s(L"\n EnrollCaptureCallback executing\n");
    wprintf_s(L"\n Sample %d captured", swipeCount++);

    // The capture was not acceptable or the enrollment operation
    // failed.
    if (FAILED(OperationStatus))
    {
        if (OperationStatus == WINBIO_E_BAD_CAPTURE)
        {
            wprintf_s(L"\n Bad capture; reason: %d\n", RejectDetail);
            wprintf_s(L"\n Swipe your finger to capture another sample.\n");

            // Try again.
            hr = WinBioEnrollCaptureWithCallback(
                    callbackContext->SessionHandle, // Open session handle
                    EnrollCaptureCallback,          // Callback function
                    EnrollCallbackContext           // Callback context
                    );
            if (FAILED(hr))
            {
                wprintf_s(L"WinBioEnrollCaptureWithCallback failed.");
                wprintf_s(L"hr = 0x%x\n", hr);
            }
        }
        else
        {
            wprintf_s(L"EnrollCaptureCallback failed.");
            wprintf_s(L"OperationStatus = 0x%x\n", OperationStatus);
        }
        goto e_Exit;
    }

    // The enrollment operation requires more fingerprint swipes.
    // This is normal and depends on your hardware. Typically, at least
    // three swipes are required.
    if (OperationStatus == WINBIO_I_MORE_DATA)
    {
        wprintf_s(L"\n More data required.");
        wprintf_s(L"\n Swipe your finger on the sensor again.");

        hr = WinBioEnrollCaptureWithCallback(
                callbackContext->SessionHandle,
                EnrollCaptureCallback,
                EnrollCallbackContext
                );
        if (FAILED(hr))
        {
            wprintf_s(L"WinBioEnrollCaptureWithCallback failed. ");
            wprintf_s(L"hr = 0x%x\n", hr);
        }
        goto e_Exit;
    }

    wprintf_s(L"\n Template completed\n");

e_Exit:

    return;
}

```

## See also

[WinBioAcquireFocus](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioacquirefocus)

[WinBioEnrollBegin](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollbegin)

[WinBioEnrollCapture](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollcapture)

[WinBioEnrollCommit](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollcommit)

[WinBioEnrollDiscard](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrolldiscard)

[WinBioReleaseFocus](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioreleasefocus)