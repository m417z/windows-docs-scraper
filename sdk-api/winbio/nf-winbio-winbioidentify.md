# WinBioIdentify function

## Description

Captures a biometric sample and determines whether it matches an existing biometric template. Starting with Windows 10, build 1607, this function is available to use with a mobile image.

## Parameters

### `SessionHandle` [in]

A **WINBIO_SESSION_HANDLE** value that identifies an open biometric session. Open a synchronous session handle by calling [WinBioOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioopensession). Open an asynchronous session handle by calling [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession).

### `UnitId` [out, optional]

A pointer to a **ULONG** value that specifies the biometric unit used to perform the identification.

### `Identity` [out, optional]

Pointer to a [WINBIO_IDENTITY](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-identity) structure that receives the GUID or SID of the user providing the biometric sample.

### `SubFactor` [out, optional]

Pointer to a **WINBIO_BIOMETRIC_SUBTYPE** value that receives the sub-factor associated with the biometric sample. See the Remarks section for more details.

### `RejectDetail` [out, optional]

A pointer to a **ULONG** value that contains additional information about the failure, if any, to capture a biometric sample. If the capture succeeded, this parameter is set to zero. The following values are defined for fingerprint capture:

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
| **E_POINTER** | The pointer specified by the *UnitId*, *Identity*, *SubFactor*, or *RejectDetail* parameters cannot be **NULL**. |
| **WINBIO_E_BAD_CAPTURE** | The sample could not be captured. Use the *RejectDetail* value for more information. |
| **WINBIO_E_ENROLLMENT_IN_PROGRESS** | The operation could not be completed because the biometric unit is currently being used for an enrollment transaction (system pool only). |
| **WINBIO_E_UNKNOWN_ID** | The biometric sample does not match any saved in the database. |

## Remarks

The value returned in the *SubFactor* parameter specifies the sub-factor associated with the biometric sample. The Windows Biometric Framework (WBF) currently supports only fingerprint capture and uses the following constants to represent sub-type information.

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

To use **WinBioIdentify** synchronously, call the function with a session handle created by calling [WinBioOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioopensession). The function blocks until the operation completes or an error is encountered.

To use **WinBioIdentify** asynchronously, call the function with a session handle created by calling [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession). The framework allocates a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure and uses it to return information about operation success or failure. If the operation is successful, the framework returns **WINBIO_IDENTITY** and **WINBIO_BIOMETRIC_SUBTYPE** information in a nested **Identify** structure. If the operation is unsuccessful, the framework returns **WINBIO_REJECT_DETAIL** information in the **Identify** structure. The **WINBIO_ASYNC_RESULT** structure is returned to the application callback or to the application message queue, depending on the value you set in the *NotificationMethod* parameter of the **WinBioAsyncOpenSession** function:

* If you choose to receive completion notices by using a callback, you must implement a [PWINBIO_ASYNC_COMPLETION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winbio/nc-winbio-pwinbio_async_completion_callback) function and set the *NotificationMethod* parameter to **WINBIO_ASYNC_NOTIFY_CALLBACK**.
* If you choose to receive completion notices by using the application message queue, you must set the *NotificationMethod* parameter to **WINBIO_ASYNC_NOTIFY_MESSAGE**. The framework returns a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) pointer to the **LPARAM** field of the window message.

To prevent memory leaks, you must call [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) to release the [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure after you have finished using it.

**Windows 7:** You can perform this operation asynchronously by using the [WinBioIdentifyWithCallback](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioidentifywithcallback) function. The function verifies the input arguments and returns immediately. If the input arguments are not valid, the function returns an error code. Otherwise, the framework starts the operation on another thread. When the asynchronous operation completes or encounters an error, the framework sends the results to the [PWINBIO_IDENTIFY_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winbio/nc-winbio-pwinbio_identify_callback) function implemented by your application.

#### Examples

The following function calls [WinBioEnumEnrollments](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenumenrollments) to enumerate the
biometric sub-factors enrolled for a template, and it calls **WinBioIdentify** to retrieve a [WINBIO_IDENTITY](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-identity) object that identifies the user. Link to the Winbio.lib static library and include the following header files:

* Windows.h
* Stdio.h
* Conio.h
* Winbio.h

```cpp
HRESULT EnumEnrollments( )
{
    // Declare variables.
    HRESULT hr = S_OK;
    WINBIO_IDENTITY identity = {0};
    WINBIO_SESSION_HANDLE sessionHandle = NULL;
    WINBIO_UNIT_ID unitId = 0;
    PWINBIO_BIOMETRIC_SUBTYPE subFactorArray = NULL;
    WINBIO_BIOMETRIC_SUBTYPE SubFactor = 0;
    SIZE_T subFactorCount = 0;
    WINBIO_REJECT_DETAIL rejectDetail = 0;
    WINBIO_BIOMETRIC_SUBTYPE subFactor = WINBIO_SUBTYPE_NO_INFORMATION;

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

    // Locate the biometric sensor and retrieve a WINBIO_IDENTITY object.
    wprintf_s(L"\n Calling WinBioIdentify - Swipe finger on sensor...\n");
    hr = WinBioIdentify(
            sessionHandle,              // Session handle
            &unitId,                    // Biometric unit ID
            &identity,                  // User SID
            &subFactor,                 // Finger sub factor
            &rejectDetail               // Rejection information
            );
    wprintf_s(L"\n Swipe processed - Unit ID: %d\n", unitId);
    if (FAILED(hr))
    {
        if (hr == WINBIO_E_UNKNOWN_ID)
        {
            wprintf_s(L"\n Unknown identity.\n");
        }
        else if (hr == WINBIO_E_BAD_CAPTURE)
        {
            wprintf_s(L"\n Bad capture; reason: %d\n", rejectDetail);
        }
        else
        {
            wprintf_s(L"\n WinBioEnumBiometricUnits failed. hr = 0x%x\n", hr);
        }
        goto e_Exit;
    }

    // Retrieve the biometric sub-factors for the template.
    hr = WinBioEnumEnrollments(
            sessionHandle,              // Session handle
            unitId,                     // Biometric unit ID
            &identity,                  // Template ID
            &subFactorArray,            // Subfactors
            &subFactorCount             // Count of subfactors
            );
    if (FAILED(hr))
    {
        wprintf_s(L"\n WinBioEnumEnrollments failed. hr = 0x%x\n", hr);
        goto e_Exit;
    }

    // Print the sub-factor(s) to the console.
    wprintf_s(L"\n Enrollments for this user on Unit ID %d:", unitId);
    for (SIZE_T index = 0; index < subFactorCount; ++index)
    {
        SubFactor = subFactorArray[index];
        switch (SubFactor)
        {
            case WINBIO_ANSI_381_POS_RH_THUMB:
                wprintf_s(L"\n   RH thumb\n");
                break;
            case WINBIO_ANSI_381_POS_RH_INDEX_FINGER:
                wprintf_s(L"\n   RH index finger\n");
                break;
            case WINBIO_ANSI_381_POS_RH_MIDDLE_FINGER:
                wprintf_s(L"\n   RH middle finger\n");
                break;
            case WINBIO_ANSI_381_POS_RH_RING_FINGER:
                wprintf_s(L"\n   RH ring finger\n");
                break;
            case WINBIO_ANSI_381_POS_RH_LITTLE_FINGER:
                wprintf_s(L"\n   RH little finger\n");
                break;
            case WINBIO_ANSI_381_POS_LH_THUMB:
                wprintf_s(L"\n   LH thumb\n");
                break;
            case WINBIO_ANSI_381_POS_LH_INDEX_FINGER:
                wprintf_s(L"\n   LH index finger\n");
                break;
            case WINBIO_ANSI_381_POS_LH_MIDDLE_FINGER:
                wprintf_s(L"\n   LH middle finger\n");
                break;
            case WINBIO_ANSI_381_POS_LH_RING_FINGER:
                wprintf_s(L"\n   LH ring finger\n");
                break;
            case WINBIO_ANSI_381_POS_LH_LITTLE_FINGER:
                wprintf_s(L"\n   LH little finger\n");
                break;
            default:
                wprintf_s(L"\n   The sub-factor is not correct\n");
                break;
        }

    }

e_Exit:
    if (subFactorArray!= NULL)
    {
        WinBioFree(subFactorArray);
        subFactorArray = NULL;
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

[WinBioIdentifyWithCallback](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioidentifywithcallback)