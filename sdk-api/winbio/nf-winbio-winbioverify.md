# WinBioVerify function

## Description

Captures a biometric sample and determines whether the sample corresponds to the specified user identity. Starting with Windows 10, build 1607, this function is available to use with a mobile image.

## Parameters

### `SessionHandle` [in]

A **WINBIO_SESSION_HANDLE** value that identifies an open biometric session. Open a synchronous session handle by calling [WinBioOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioopensession). Open an asynchronous session handle by calling [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession).

### `Identity` [in]

Pointer to a [WINBIO_IDENTITY](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-identity) structure that contains the GUID or SID of the user providing the biometric sample.

### `SubFactor` [in]

A **WINBIO_BIOMETRIC_SUBTYPE** value that specifies the sub-factor associated with the biometric sample. The Windows Biometric Framework (WBF) currently supports only fingerprint capture and can use the following constants to represent sub-type information.

* WINBIO_ANSI_381_POS_RH_THUMB
* WINBIO_ANSI_381_POS_RH_INDEX_FINGER
* WINBIO_ANSI_381_POS_RH_MIDDLE_FINGER
* WINBIO_ANSI_381_POS_RH_RING_FINGER
* WINBIO_ANSI_381_POS_RH_LITTLE_FINGER
* WINBIO_ANSI_381_POS_LH_THUMB
* WINBIO_ANSI_381_POS_LH_INDEX_FINGER
* WINBIO_ANSI_381_POS_LH_MIDDLE_FINGER
* WINBIO_ANSI_381_POS_LH_RING_FINGER
* WINBIO_ANSI_381_POS_LH_LITTLE_FINGER
* WINBIO_ANSI_381_POS_RH_FOUR_FINGERS
* WINBIO_ANSI_381_POS_LH_FOUR_FINGERS
* WINBIO_SUBTYPE_ANY

### `UnitId` [out, optional]

A pointer to a **WINBIO_UNIT_ID** value that specifies the biometric unit that performed the verification.

### `Match` [out, optional]

Pointer to a Boolean value that specifies whether the captured sample matched the user identity specified by the *Identity* parameter.

### `RejectDetail` [out, optional]

A pointer to a **ULONG** value that contains additional information about the failure to capture a biometric sample. If the capture succeeded, this parameter is set to zero. The following values are defined for fingerprint capture:

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
| **E_HANDLE** | The session handle is not valid. |
| **E_INVALIDARG** | The *SubFactor* argument is incorrect. |
| **E_POINTER** | The pointer specified by the *UnitId*, *Identity*, *SubFactor*, or *RejectDetail* parameters cannot be **NULL**. |
| **WINBIO_E_BAD_CAPTURE** | The biometric sample could not be captured. Use the *RejectDetail* value for more information. |
| **WINBIO_E_ENROLLMENT_IN_PROGRESS** | The operation could not be completed because the specified biometric unit is currently being used for an enrollment transaction (system pool only). |
| **WINBIO_E_NO_MATCH** | The biometric sample does not correspond to the specified *Identity* and *SubFactor* combination. |

## Remarks

If capture of the biometric sample fails, the *UnitId* parameter will contain the unit number of the sensor that attempted to perform the capture.

Calls to this function using the system pool will block until the application acquires window focus and the user has provided a biometric sample. We recommend, therefore, that your application not call **WinBioVerify** until it has acquired focus. The manner in which you acquire focus depends on the type of application you are writing. For example, if you are creating a GUI application you can implement a message handler that captures a WM_ACTIVATE, WM_SETFOCUS, or other appropriate message. If you are writing a CUI application, call **GetConsoleWindow** to retrieve a handle to the console window and pass that handle to the **SetForegroundWindow** function to force the console window into the foreground and assign it focus. If your application is running in a detached process and has no window or is a Windows service, use [WinBioAcquireFocus](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioacquirefocus) and [WinBioReleaseFocus](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioreleasefocus) to manually control focus.

To use **WinBioVerify** synchronously, call the function with a session handle created by calling [WinBioOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioopensession). The function blocks until the operation completes or an error is encountered.

To use **WinBioVerify** asynchronously, call the function with a session handle created by calling [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession). The framework allocates a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure and uses it to return information about operation success or failure. If the operation is successful, the framework returns a **BOOLEAN** match value in a nested **Verify** structure. If the operation is unsuccessful, the framework returns **WINBIO_REJECT_DETAIL** information in the **Verify** structure. The **WINBIO_ASYNC_RESULT** structure is returned to the application callback or to the application message queue, depending on the value you set in the *NotificationMethod* parameter of the **WinBioAsyncOpenSession** function:

* If you choose to receive completion notices by using a callback, you must implement a [PWINBIO_ASYNC_COMPLETION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winbio/nc-winbio-pwinbio_async_completion_callback) function and set the *NotificationMethod* parameter to **WINBIO_ASYNC_NOTIFY_CALLBACK**.
* If you choose to receive completion notices by using the application message queue, you must set the *NotificationMethod* parameter to **WINBIO_ASYNC_NOTIFY_MESSAGE**. The framework returns a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) pointer to the **LPARAM** field of the window message.

To prevent memory leaks, you must call [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) to release the [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure after you have finished using it.

**Windows 7:** You can perform this operation asynchronously by using the [WinBioVerifyWithCallback](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioverifywithcallback) function. The function verifies the input arguments and returns immediately. If the input arguments are not valid, the function returns an error code. Otherwise, the framework starts the operation on another thread. When the asynchronous operation completes or encounters an error, the framework sends the results to the [PWINBIO_VERIFY_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winbio/nc-winbio-pwinbio_verify_callback) function implemented by your application.

#### Examples

The following function calls **WinBioVerify** to determine whether a biometric sample matches
the logged on identity of the current user. The helper function GetCurrentUserIdentity is also included. Link to the Winbio.lib static library and include the following header files:

* Windows.h
* Stdio.h
* Conio.h
* Winbio.h

```cpp
HRESULT Verify(WINBIO_BIOMETRIC_SUBTYPE subFactor)
{
    HRESULT hr = S_OK;
    WINBIO_SESSION_HANDLE sessionHandle = NULL;
    WINBIO_UNIT_ID unitId = 0;
    WINBIO_REJECT_DETAIL rejectDetail = 0;
    WINBIO_IDENTITY identity = {0};
    BOOLEAN match = FALSE;

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

    // Verify a biometric sample.
    wprintf_s(L"\n Calling WinBioVerify - Swipe finger on sensor...\n");
    hr = WinBioVerify(
            sessionHandle,
            &identity,
            subFactor,
            &unitId,
            &match,
            &rejectDetail
            );
    wprintf_s(L"\n Swipe processed - Unit ID: %d\n", unitId);
    if (FAILED(hr))
    {
        if (hr == WINBIO_E_NO_MATCH)
        {
            wprintf_s(L"\n- NO MATCH - identity verification failed.\n");
        }
        else if (hr == WINBIO_E_BAD_CAPTURE)
        {
            wprintf_s(L"\n- Bad capture; reason: %d\n", rejectDetail);
        }
        else
        {
        wprintf_s(L"\n WinBioVerify failed. hr = 0x%x\n", hr);
        }
        goto e_Exit;
    }
    wprintf_s(L"\n Fingerprint verified:\n", unitId);

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

[WinBioVerifyWithCallback](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioverifywithcallback)