# WinBioVerifyWithCallback function

## Description

Asynchronously captures a biometric sample and determines whether the sample corresponds to the specified user identity. The function returns immediately to the caller, performs capture and verification on a separate thread, and calls into an application-defined callback function to update operation status.

**Important**

We recommend that, beginning with Windows 8, you no longer use this function to start an asynchronous operation. Instead, do the following:

* Implement a [PWINBIO_ASYNC_COMPLETION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winbio/nc-winbio-pwinbio_async_completion_callback) function to receive notice when the operation completes.
* Call the [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession) function. Pass the address of your callback in the *CallbackRoutine* parameter. Pass **WINBIO_ASYNC_NOTIFY_CALLBACK** in the *NotificationMethod* parameter. Retrieve an asynchronous session handle.
* Use the asynchronous session handle to call [WinBioVerify](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioverify). When the operation finishes, the Windows Biometric Framework will allocate and initialize a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure with the results and invoke your callback with a pointer to the results structure.
* Call [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) from your callback implementation to release the [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure after you have finished using it.

## Parameters

### `SessionHandle` [in]

A **WINBIO_SESSION_HANDLE** value that identifies an open biometric session.

### `Identity` [in]

Pointer to a [WINBIO_IDENTITY](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-identity) structure that contains the GUID or SID of the user providing the biometric sample.

### `SubFactor` [in]

A **WINBIO_BIOMETRIC_SUBTYPE** value that specifies the sub-factor associated with the biometric sample. See the Remarks section for more details.

### `VerifyCallback` [in]

Address of a callback function that will be called by the **WinBioVerifyWithCallback** function when verification succeeds or fails. You must create the callback.

### `VerifyCallbackContext` [in, optional]

An optional application-defined structure that is returned in the *VerifyCallbackContext* parameter of the callback function. This structure can contain any data that the custom callback function is designed to handle.

## Return value

If the function succeeds, it returns **S_OK**. If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_HANDLE** | The session handle is not valid. |
| **E_INVALIDARG** | The *SubFactor* argument is incorrect. |
| **E_POINTER** | The pointer specified by the *Identity* and *VerifyCallback* parameters cannot be **NULL**. |

## Remarks

The *SubFactor* parameter specifies the sub-factor associated with the biometric sample. The Windows Biometric Framework (WBF) currently supports only fingerprint capture and uses the following constants to represent sub-type information.

* **WINBIO_ANSI_381_POS_RH_THUMB**
* **WINBIO_ANSI_381_POS_RH_INDEX_FINGER**
* **WINBIO_ANSI_381_POS_RH_MIDDLE_FINGER**
* **WINBIO_ANSI_381_POS_RH_RING_FINGER**
* **WINBIO_ANSI_381_POS_RH_LITTLE_FINGER**
* **WINBIO_ANSI_381_POS_LH_THUMB**
* **WINBIO_ANSI_381_POS_LH_INDEX_FINGER**
* **WINBIO_ANSI_381_POS_LH_MIDDLE_FINGER**
* **WINBIO_ANSI_381_POS_LH_RING_FINGER**
* **WINBIO_ANSI_381_POS_LH_LITTLE_FINGER**
* **WINBIO_ANSI_381_POS_RH_FOUR_FINGERS**
* **WINBIO_ANSI_381_POS_LH_FOUR_FINGERS**

The callback routine executes in the context of an arbitrary thread in the calling process. The caller is responsible for synchronizing access to any memory that may be shared between the callback and other parts of the application.

The **WinBioVerifyWithCallback** function returns immediately and passes S_OK to the caller. To determine the status of the capture and verification process, you must examine the *OperationStatus* parameter in your callback function.

You can call the [WinBioCancel](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiocancel) function to cancel a pending callback operation. Closing a session also implicitly cancels callbacks for that session.

The callback routine must have the following signature:

```cpp

VOID CALLBACK VerifyCallback(
__in_opt PVOID VerifyCallbackContext,
__in HRESULT OperationStatus,
__in WINBIO_UNIT_ID UnitId,
__in BOOLEAN Match,
__in WINBIO_REJECT_DETAIL RejectDetail
);
```

#### Examples

The following function calls **WinBioVerifyWithCallback** to asynchronously
determine whether a biometric sample matches the logged on identity of
the current user. The callback routine, VerifyCallback, and a helper function, GetCurrentUserIdentity, are also included. Link to the Winbio.lib static library and include the following header files:

* Windows.h
* Stdio.h
* Conio.h
* Winbio.h

```cpp
HRESULT VerifyWithCallback(BOOL bCancel, WINBIO_BIOMETRIC_SUBTYPE subFactor)
{
    // Declare variables.
    HRESULT hr = S_OK;
    WINBIO_SESSION_HANDLE sessionHandle = NULL;
    WINBIO_UNIT_ID unitId = 0;
    WINBIO_REJECT_DETAIL rejectDetail = 0;
    WINBIO_IDENTITY identity = {0};

    // Find the identity of the user.
    hr = GetCurrentUserIdentity( &identity );
    if (FAILED(hr))
    {
        wprintf_s(L"\n User identity not found. hr = 0x%x\n", hr);
        goto e_Exit;
    }

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

    // Verify a biometric sample asynchronously.
    wprintf_s(L"\n Calling WinBioVerifyWithCallback.\n");
    hr = WinBioVerifyWithCallback(
            sessionHandle,              // Open session handle
            &identity,                  // User SID or GUID
            subFactor,                  // Sample sub-factor
            VerifyCallback,             // Callback function
            NULL                        // Optional context
            );
    if (FAILED(hr))
    {
        wprintf_s(L"\n WinBioVerifyWithCallback failed. hr = 0x%x\n", hr);
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
        WinBioCloseSession(sessionHandle);
        sessionHandle = NULL;
    }

    wprintf_s(L"\n Hit any key to continue...");
    _getch();

    return hr;
}

//------------------------------------------------------------------------
// The following function is the callback for WinBioVerifyWithCallback.
// The function filters the response from the biometric subsystem and
// writes a result to the console window.
//
VOID CALLBACK VerifyCallback(
  __in_opt PVOID VerifyCallbackContext,
  __in HRESULT OperationStatus,
  __in WINBIO_UNIT_ID UnitId,
  __in BOOLEAN Match,
  __in WINBIO_REJECT_DETAIL RejectDetail
  )
{
    UNREFERENCED_PARAMETER(VerifyCallbackContext);
    UNREFERENCED_PARAMETER(Match);

    wprintf_s(L"\n VerifyCallback executing");
    wprintf_s(L"\n Swipe processed for unit ID %d\n", UnitId);

    // The identity could not be verified.
    if (FAILED(OperationStatus))
    {
        wprintf_s(L"\n Verification failed for the following reason:");
        if (OperationStatus == WINBIO_E_NO_MATCH)
        {
            wprintf_s(L"\n No match.\n");
        }
        else if (OperationStatus == WINBIO_E_BAD_CAPTURE)
        {
            wprintf_s(L"\n Bad capture.\n ");
            wprintf_s(L"\n Bad capture; reason: %d\n", RejectDetail);
        }
        else
        {
            wprintf_s(L"VerifyCallback failed.");
            wprintf_s(L"OperationStatus = 0x%x\n", OperationStatus);
        }
        goto e_Exit;
    }

    // The user identity was verified.
    wprintf_s(L"\n Fingerprint verified:\n");

e_Exit:
    return;
}

//------------------------------------------------------------------------
// The following function retrieves the identity of the current user.
// This is a helper function and is not part of the Windows Biometric
// Framework API.
//
HRESULT GetCurrentUserIdentity(__inout PWINBIO_IDENTITY Identity)
{
    // Declare variables.
    HRESULT hr = S_OK;
    HANDLE tokenHandle = NULL;
    DWORD bytesReturned = 0;
    struct{
        TOKEN_USER tokenUser;
        BYTE buffer[SECURITY_MAX_SID_SIZE];
    } tokenInfoBuffer;

    // Zero the input identity and specify the type.
    ZeroMemory( Identity, sizeof(WINBIO_IDENTITY));
    Identity->Type = WINBIO_ID_TYPE_NULL;

    // Open the access token associated with the
    // current process
    if (!OpenProcessToken(
            GetCurrentProcess(),            // Process handle
            TOKEN_READ,                     // Read access only
            &tokenHandle))                  // Access token handle
    {
        DWORD win32Status = GetLastError();
        wprintf_s(L"Cannot open token handle: %d\n", win32Status);
        hr = HRESULT_FROM_WIN32(win32Status);
        goto e_Exit;
    }

    // Zero the tokenInfoBuffer structure.
    ZeroMemory(&tokenInfoBuffer, sizeof(tokenInfoBuffer));

    // Retrieve information about the access token. In this case,
    // retrieve a SID.
    if (!GetTokenInformation(
            tokenHandle,                    // Access token handle
            TokenUser,                      // User for the token
            &tokenInfoBuffer.tokenUser,     // Buffer to fill
            sizeof(tokenInfoBuffer),        // Size of the buffer
            &bytesReturned))                // Size needed
    {
        DWORD win32Status = GetLastError();
        wprintf_s(L"Cannot query token information: %d\n", win32Status);
        hr = HRESULT_FROM_WIN32(win32Status);
        goto e_Exit;
    }

    // Copy the SID from the tokenInfoBuffer structure to the
    // WINBIO_IDENTITY structure.
    CopySid(
        SECURITY_MAX_SID_SIZE,
        Identity->Value.AccountSid.Data,
        tokenInfoBuffer.tokenUser.User.Sid
        );

    // Specify the size of the SID and assign WINBIO_ID_TYPE_SID
    // to the type member of the WINBIO_IDENTITY structure.
    Identity->Value.AccountSid.Size = GetLengthSid(tokenInfoBuffer.tokenUser.User.Sid);
    Identity->Type = WINBIO_ID_TYPE_SID;

e_Exit:

    if (tokenHandle != NULL)
    {
        CloseHandle(tokenHandle);
    }

    return hr;
}

```

## See also

[WinBioCancel](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiocancel)

[WinBioVerify](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioverify)