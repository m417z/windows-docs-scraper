# WinBioUnlockUnit function

## Description

Releases the session lock on the specified biometric unit.

## Parameters

### `SessionHandle` [in]

A **WINBIO_SESSION_HANDLE** value that identifies an open biometric session. Open a synchronous session handle by calling [WinBioOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioopensession). Open an asynchronous session handle by calling [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession).

### `UnitId` [in]

A **WINBIO_UNIT_ID** value that specifies the biometric unit to unlock.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| ****E_HANDLE**** | The session handle is not valid. |
| ****E_INVALIDARG**** | The *UnitId* parameter cannot contain zero. |
| ****WINBIO_E_LOCK_VIOLATION**** | The biometric unit specified by the *UnitId* parameter is not currently locked by the session. |

## Remarks

Calling **WinBioUnlockUnit** automatically releases any locks held by the session. This function will fail if the biometric unit specified by the *UnitId* has not been previously locked by calling the [WinBioLockUnit](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiolockunit) function.

To use **WinBioUnlockUnit** synchronously, call the function with a session handle created by calling [WinBioOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioopensession). The function blocks until the operation completes or an error is encountered.

To use **WinBioUnlockUnit** asynchronously, call the function with a session handle created by calling [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession). The framework allocates a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure and uses it to return information about operation success or failure. The **WINBIO_ASYNC_RESULT** structure is returned to the application callback or to the application message queue, depending on the value you set in the *NotificationMethod* parameter of the **WinBioAsyncOpenSession** function:

* If you choose to receive completion notices by using a callback, you must implement a [PWINBIO_ASYNC_COMPLETION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winbio/nc-winbio-pwinbio_async_completion_callback) function and set the *NotificationMethod* parameter to **WINBIO_ASYNC_NOTIFY_CALLBACK**.
* If you choose to receive completion notices by using the application message queue, you must set the *NotificationMethod* parameter to **WINBIO_ASYNC_NOTIFY_MESSAGE**. The framework returns a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) pointer to the **LPARAM** field of the window message.

To prevent memory leaks, you must call [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) to release the [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure after you have finished using it.

#### Examples

The following function calls [WinBioLockUnit](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiolockunit) to lock the biometric
unit before calling [WinBioIdentify](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioidentify) to identify the user. It calls **WinBioUnlockUnit** to unlock the biometric union before closing the open session. Link to the Winbio.lib static library and include the following header files:

* Windows.h
* Stdio.h
* Conio.h
* Winbio.h

```cpp
HRESULT LockUnlock( )
{
    // Declare variables.
    HRESULT hr = S_OK;
    WINBIO_IDENTITY identity = {0};
    WINBIO_SESSION_HANDLE sessionHandle = NULL;
    WINBIO_UNIT_ID unitId = 0;
    WINBIO_REJECT_DETAIL rejectDetail = 0;
    WINBIO_BIOMETRIC_SUBTYPE subFactor = WINBIO_SUBTYPE_NO_INFORMATION;
    BOOL lockAcquired = FALSE;

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
        wprintf_s(L"\n WinBioEnumBiometricUnits failed. hr = 0x%x\n", hr);
        goto e_Exit;
    }

    // Lock the session. The Biometric unit ID (1) is hard coded in
    // this example.
    hr = WinBioLockUnit( sessionHandle, 1 );
    if (FAILED(hr))
    {
        wprintf_s(L"\n WinBioLockUnit failed. hr = 0x%x\n", hr);
        goto e_Exit;
    }
    wprintf_s(L"\n Biometric unit #1 is locked.\n");
    lockAcquired = TRUE;

    // Locate the biometric sensor and retrieve a WINBIO_IDENTITY object.
    // You must swipe your finger on the sensor.
    wprintf_s(L"\n Calling WinBioIdentify - Swipe finger on sensor...\n");
    hr = WinBioIdentify(
            sessionHandle,
            &unitId,
            &identity,
            &subFactor,
            &rejectDetail
            );
    wprintf_s(L"\n Swipe processed - Unit ID: %d\n", unitId);
    if (FAILED(hr))
    {
        wprintf_s(L"\n WinBioIdentify failed. hr = 0x%x\n", hr);
        goto e_Exit;
    }

e_Exit:

    // Unlock the biometric unit if it is locked.
    if (lockAcquired == TRUE)
    {
        hr = WinBioUnlockUnit( sessionHandle, 1 );
        if (FAILED(hr))
        {
            wprintf_s(L"\n WinBioUnlockUnit failed. hr = 0x%x\n", hr);
        }
        wprintf_s(L"\n Biometric unit #1 is unlocked.\n");
        lockAcquired = FALSE;
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

[WinBioLockUnit](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiolockunit)