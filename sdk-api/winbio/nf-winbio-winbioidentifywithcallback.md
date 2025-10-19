# WinBioIdentifyWithCallback function

## Description

Asynchronously captures a biometric sample and determines whether it matches an existing biometric template. The function returns immediately to the caller, performs capture and identification on a separate thread, and calls into an application-defined callback function to update operation status.

**Important**

We recommend that, beginning with Windows 8, you no longer use this function to start an asynchronous operation. Instead, do the following:

* Implement a [PWINBIO_ASYNC_COMPLETION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winbio/nc-winbio-pwinbio_async_completion_callback) function to receive notice when the operation completes.
* Call the [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession) function. Pass the address of your callback in the *CallbackRoutine* parameter. Pass **WINBIO_ASYNC_NOTIFY_CALLBACK** in the *NotificationMethod* parameter. Retrieve an asynchronous session handle.
* Use the asynchronous session handle to call [WinBioIdentify](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioidentify). When the operation finishes, the Windows Biometric Framework will allocate and initialize a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure with the results and invoke your callback with a pointer to the results structure.
* Call [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) from your callback implementation to release the [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure after you have finished using it.

## Parameters

### `SessionHandle` [in]

A **WINBIO_SESSION_HANDLE** value that identifies an open biometric session.

### `IdentifyCallback` [in]

Address of a callback function that will be called by the **WinBioIdentifyWithCallback** function when identification succeeds or fails. You must create the callback.

### `IdentifyCallbackContext` [in, optional]

Pointer to an application-defined data structure that is passed to the callback function in its *IdentifyCallbackContext* parameter. This structure can contain any data that the custom callback function is designed to handle.

## Return value

If the function succeeds, it returns **S_OK**. If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_HANDLE** | The session handle is not valid. |
| **E_POINTER** | The *SessionHandle* and *IdentifyCallback* parameters cannot be **NULL**. |

## Remarks

The callback routine must have the following signature:

```cpp
VOID CALLBACK IdentifyCallback(
__in_opt PVOID IdentifyCallbackContext,
__in HRESULT OperationStatus,
__in WINBIO_UNIT_ID UnitId,
__in WINBIO_IDENTITY *Identity,
__in WINBIO_BIOMETRIC_SUBTYPE SubFactor,
__in WINBIO_REJECT_DETAIL RejectDetail
);

```

#### Examples

The following code example calls **WinBioIdentifyWithCallback** to identify
a user from a biometric scan. **WinBioIdentifyWithCallback** is an
asynchronous function that configures the biometric subsystem to
process biometric input on another thread. Output from the biometric
subsystem is then sent to a custom callback function named IdentifyCallback. Link to the Winbio.lib static library and include the following header files:

* Windows.h
* Stdio.h
* Conio.h
* Winbio.h

```cpp
HRESULT IdentifyWithCallback(BOOL bCancel)
{
    // Declare variables.
    HRESULT hr = S_OK;
    WINBIO_SESSION_HANDLE sessionHandle = NULL;

    // Connect to the system pool.
    hr = WinBioOpenSession(
            WINBIO_TYPE_FINGERPRINT,    // Service provider
            WINBIO_POOL_SYSTEM,         // Pool type
            WINBIO_FLAG_DEFAULT,        // Configuration and access
            NULL,                       // Array of biometric unit IDs
            0,                          // Count of biometric unit IDs
            WINBIO_DB_DEFAULT,          // Database ID
            &sessionHandle              // [out] Session handle
            );
    if (FAILED(hr))
    {
        wprintf_s(L"\n WinBioOpenSession failed. hr = 0x%x\n", hr);
        goto e_Exit;
    }

    // Call WinBioIdentifyWithCallback. The method is asynchronous
    // and returns immediately.
    wprintf_s(L"\n Calling WinBioIdentifyWithCallback");
    wprintf_s(L"\n Swipe the sensor ...\n");
    hr = WinBioIdentifyWithCallback(
            sessionHandle,              // Open biometric session
            IdentifyCallback,           // Callback function
            NULL                        // Optional context
            );
    if (FAILED(hr))
    {
        wprintf_s(L"\n WinBioIdentifyWithCallback failed. hr = 0x%x\n", hr);
        goto e_Exit;
    }

    // Cancel user identification if the bCancel flag is set.
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
// The following function is the callback for WinBioIdentifyWithCallback.
// The function filters the response from the biometric subsystem and
// writes a result to the console window.
//
VOID CALLBACK IdentifyCallback(
    __in_opt PVOID IdentifyCallbackContext,
    __in HRESULT OperationStatus,
    __in WINBIO_UNIT_ID UnitId,
    __in WINBIO_IDENTITY *Identity,
    __in WINBIO_BIOMETRIC_SUBTYPE SubFactor,
    __in WINBIO_REJECT_DETAIL RejectDetail
    )
{
    UNREFERENCED_PARAMETER(IdentifyCallbackContext);
    UNREFERENCED_PARAMETER(Identity);

    wprintf_s(L"\n IdentifyCallback executing");
    wprintf_s(L"\n Swipe processed for unit ID %d\n", UnitId);

    // The attempt to process the fingerprint failed.
    if (FAILED(OperationStatus))
    {
        if (OperationStatus == WINBIO_E_UNKNOWN_ID)
        {
            wprintf_s(L"\n Unknown identity.\n");
        }
        else if (OperationStatus == WINBIO_E_BAD_CAPTURE)
        {
            wprintf_s(L"\n Bad capture; reason: %d\n", RejectDetail);
        }
        else
        {
            wprintf_s(L"IdentifyCallback failed.");
            wprintf_s(L"OperationStatus = 0x%x\n", OperationStatus);
        }
    }
    // Processing succeeded and the finger swiped is written
    // to the console window.
    else
    {
        wprintf_s(L"\n The following finger was used:");
        switch (SubFactor)
        {
            case WINBIO_SUBTYPE_NO_INFORMATION:
                wprintf_s(L"\n No information\n");
                break;
            case WINBIO_ANSI_381_POS_RH_THUMB:
                wprintf_s(L"\n RH thumb\n");
                break;
            case WINBIO_ANSI_381_POS_RH_INDEX_FINGER:
                wprintf_s(L"\n RH index finger\n");
                break;
            case WINBIO_ANSI_381_POS_RH_MIDDLE_FINGER:
                wprintf_s(L"\n RH middle finger\n");
                break;
            case WINBIO_ANSI_381_POS_RH_RING_FINGER:
                wprintf_s(L"\n RH ring finger\n");
                break;
            case WINBIO_ANSI_381_POS_RH_LITTLE_FINGER:
                wprintf_s(L"\n RH little finger\n");
                break;
            case WINBIO_ANSI_381_POS_LH_THUMB:
                wprintf_s(L"\n LH thumb\n");
                break;
            case WINBIO_ANSI_381_POS_LH_INDEX_FINGER:
                wprintf_s(L"\n LH index finger\n");
                break;
            case WINBIO_ANSI_381_POS_LH_MIDDLE_FINGER:
                wprintf_s(L"\n LH middle finger\n");
                break;
            case WINBIO_ANSI_381_POS_LH_RING_FINGER:
                wprintf_s(L"\n LH ring finger\n");
                break;
            case WINBIO_ANSI_381_POS_LH_LITTLE_FINGER:
                wprintf_s(L"\n LH little finger\n");
                break;
            case WINBIO_SUBTYPE_ANY:
                wprintf_s(L"\n Any finger\n");
                break;
            default:
                break;
        }
    }
}

```

## See also

[WinBioIdentify](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioidentify)