# WinBioLocateSensorWithCallback function

## Description

Asynchronously retrieves the ID number of the biometric unit selected interactively by a user. The function returns immediately to the caller, processes on a separate thread, and reports the selected biometric unit by calling an application-defined callback function.

**Important**

We recommend that, beginning with Windows 8, you no longer use this function to start an asynchronous operation. Instead, do the following:

* Implement a [PWINBIO_ASYNC_COMPLETION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winbio/nc-winbio-pwinbio_async_completion_callback) function to receive notice when the operation completes.
* Call the [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession) function. Pass the address of your callback in the *CallbackRoutine* parameter. Pass **WINBIO_ASYNC_NOTIFY_CALLBACK** in the *NotificationMethod* parameter. Retrieve an asynchronous session handle.
* Use the asynchronous session handle to call [WinBioLocateSensor](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiolocatesensor). When the operation finishes, the Windows Biometric Framework will allocate and initialize a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure with the results and invoke your callback with a pointer to the results structure.
* Call [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) from your callback implementation to release the [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure after you have finished using it.

## Parameters

### `SessionHandle` [in]

A **WINBIO_SESSION_HANDLE** value that identifies an open biometric session.

### `LocateCallback` [in]

Address of a callback function that will be called by the **WinBioLocateSensorWithCallback** function when sensor location succeeds or fails. You must create the callback.

### `LocateCallbackContext` [in, optional]

Address of an application-defined data structure that is passed to the callback function in its *LocateCallbackContext* parameter. This structure can contain any data that the custom callback function is designed to handle.

## Return value

If the function succeeds, it returns **S_OK**. If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_HANDLE** | The session handle is not valid. |
| **E_POINTER** | The address specified by the *LocateCallback* parameter cannot be **NULL**. |

## Remarks

You can use this function on systems with multiple sensors to determine which sensor is preferred for enrollment by the user. No identification information is returned by this function. It is provided only to indicate user sensor selection.

If the *SessionHandle* parameter refers to the system sensor pool, the callback function will not be called until the application acquires window focus and the user has provided a biometric sample. The manner in which you acquire focus depends on the type of application you are writing. For example, if you are creating a GUI application you can implement a message handler that captures a WM_ACTIVATE, WM_SETFOCUS, or other appropriate message. If you are writing a CUI application, call **GetConsoleWindow** to retrieve a handle to the console window and pass that handle to the **SetForegroundWindow** function to force the console window into the foreground and assign it focus. If your application is running in a detached process and has no window or is a Windows service, use [WinBioAcquireFocus](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioacquirefocus) and [WinBioReleaseFocus](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioreleasefocus) to manually control focus.

The callback routine must have the following signature:

```cpp

VOID CALLBACK LocateCallback(
__in_opt PVOID LocateCallbackContext,
__in HRESULT OperationStatus,
__in WINBIO_UNIT_ID UnitId
);
```

#### Examples

The following function calls **WinBioLocateSensorWithCallback** to locate
biometric sensor. The **WinBioLocateSensorWithCallback** is an
asynchronous function that configures the biometric subsystem to
locate the sensor on another thread. Output from the biometric
subsystem is sent to a custom callback function named LocateSensorCallback. Link to the Winbio.lib static library and include the following header files:

* Windows.h
* Stdio.h
* Conio.h
* Winbio.h

```cpp
HRESULT LocateSensorWithCallback(BOOL bCancel)
{
    HRESULT hr = S_OK;
    WINBIO_SESSION_HANDLE sessionHandle = NULL;
    WINBIO_UNIT_ID unitId = 0;

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
        wprintf_s(L"\n WinBioOpenSession failed. hr = 0x%x\n", hr);
        goto e_Exit;
    }

    wprintf_s(L"\n Calling WinBioLocateSensorWithCallback.");
    hr = WinBioLocateSensorWithCallback(
                sessionHandle,          // Open biometric session
                LocateSensorCallback,   // Callback function
                NULL                    // Optional context
                );
    if (FAILED(hr))
    {
        wprintf_s(L"\n WinBioLocateSensorWithCallback failed.");
        wprintf_s(L"hr = 0x%x\n", hr);
        goto e_Exit;
    }
    wprintf_s(L"\n Swipe the sensor ...\n");

    // Cancel the identification if the bCancel flag is set.
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

    // Wait for the asynchronous identification process to complete
    // or be canceled.
    hr = WinBioWait( sessionHandle );
    if (FAILED(hr))
    {
        wprintf_s(L"\n WinBioWait failed. hr = 0x%x\n", hr);
    }

e_Exit:

    if (sessionHandle != NULL)
    {
       wprintf_s(L"\n Closing the session.\n");

        hr = WinBioCloseSession(sessionHandle);
        if (FAILED(hr))
        {
            wprintf_s(L"\n WinBioCloseSession failed. hr = 0x%x\n", hr);
        }
        sessionHandle = NULL;
    }

    wprintf_s(L"\n Hit any key to exit...");
    _getch();

    return hr;
}

//------------------------------------------------------------------------
// The following function is the callback for
// WinBioLocateSensorWithCallback. The function filters the response
// from the biometric subsystem and writes a result to the console window.
//
VOID CALLBACK LocateSensorCallback(
    __in_opt PVOID LocateCallbackContext,
    __in HRESULT OperationStatus,
    __in WINBIO_UNIT_ID UnitId
    )
{
    UNREFERENCED_PARAMETER(LocateCallbackContext);

    wprintf_s(L"\n LocateSensorCallback executing.");

    // A sensor could not be located.
    if (FAILED(OperationStatus))
    {
        wprintf_s(L"\n LocateSensorCallback failed.");
        wprintf_s(L"OperationStatus = 0x%x\n", OperationStatus);
    }
    // A sensor was located.
    else
    {
        wprintf_s(L"\n Selected unit ID: %d\n", UnitId);
    }
}

```

## See also

[WinBioLocateSensor](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiolocatesensor)