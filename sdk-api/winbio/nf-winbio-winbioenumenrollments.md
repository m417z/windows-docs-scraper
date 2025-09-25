# WinBioEnumEnrollments function

## Description

Retrieves the biometric sub-factors enrolled for a specified identity and biometric unit. Starting with Windows 10, build 1607, this function is available to use with a mobile image.

## Parameters

### `SessionHandle` [in]

A **WINBIO_SESSION_HANDLE** value that identifies an open biometric session. Open a synchronous session handle by calling [WinBioOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioopensession). Open an asynchronous session handle by calling [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession).

### `UnitId` [in]

A **WINBIO_UNIT_ID** value that specifies the biometric unit.

### `Identity` [in]

Pointer to a [WINBIO_IDENTITY](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-identity) structure that contains the GUID or SID of the template from which the sub-factors are to be retrieved.

### `SubFactorArray`

Address of a variable that receives a pointer to an array of sub-factors. If the function does not succeed, the pointer is set to **NULL**. If the function succeeds, you must pass the pointer to [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) to release memory allocated internally for the array.

### `SubFactorCount` [out, optional]

Pointer to a value that specifies the number of elements in the array pointed to by the *SubFactorArray* parameter. If the function does not succeed, this value is set to zero.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| ****E_HANDLE**** | The session handle is not valid. |
| ****E_INVALIDARG**** | The *UnitId* parameter cannot be zero. |
| ****E_POINTER**** | The *Identity*, *SubFactorArray*, and *SubFactorCount* parameters cannot be **NULL**. |
| ****WINBIO_E_ENROLLMENT_IN_PROGRESS**** | The operation could not be completed because the biometric unit specified by the *UnitId* parameter is currently being used for an enrollment transaction. |
| ****WINBIO_E_UNKNOWN_ID**** | The GUID or SID specified by the *Identity* parameter cannot be found. |

## Remarks

The **WinBioEnumEnrollments** function is supplied primarily so that the applications can provide user feedback. For example, your application can call this function to tell the user which fingerprints are already enrolled on a specific fingerprint reader.

After you are finished using the structures returned to the *SubFactorArray* parameter, you must call [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) to release the memory allocated internally for the array.

To use **WinBioEnumEnrollments** synchronously, call the function with a session handle created by calling [WinBioOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioopensession). The function blocks until the operation completes or an error is encountered.

To use **WinBioEnumEnrollments** asynchronously, call the function with a session handle created by calling [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession). The framework allocates a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure and uses it to return information about operation success or failure. If the operation is successful, the framework returns **WINBIO_IDENTITY** and **WINBIO_BIOMETRIC_SUBTYPE** information in a nested **EnumEnrollments** structure. If the operation is unsuccessful, the framework returns error information. The **WINBIO_ASYNC_RESULT** structure is returned to the application callback or to the application message queue, depending on the value you set in the *NotificationMethod* parameter of the **WinBioAsyncOpenSession** function:

* If you choose to receive completion notices by using a callback, you must implement a [PWINBIO_ASYNC_COMPLETION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winbio/nc-winbio-pwinbio_async_completion_callback) function and set the *NotificationMethod* parameter to **WINBIO_ASYNC_NOTIFY_CALLBACK**.
* If you choose to receive completion notices by using the application message queue, you must set the *NotificationMethod* parameter to **WINBIO_ASYNC_NOTIFY_MESSAGE**. The framework returns a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) pointer to the **LPARAM** field of the window message.

To prevent memory leaks, you must call [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) to release the [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure after you have finished using it.

#### Examples

The following function calls **WinBioEnumEnrollments** to enumerate the
biometric sub-factors enrolled for a template. Link to the Winbio.lib static library and include the following header files:

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

[WinBioEnumBiometricUnits](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenumbiometricunits)

[WinBioEnumDatabases](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenumdatabases)

[WinBioEnumServiceProviders](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenumserviceproviders)