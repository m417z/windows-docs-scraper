# WinBioLogonIdentifiedUser function

## Description

The **WinBioLogonIdentifiedUser** function causes a fast user switch to the account associated with the last successful identification operation performed by the biometric session.

## Parameters

### `SessionHandle` [in]

A **WINBIO_SESSION_HANDLE** value that identifies the biometric session that has recently performed a successful identification operation. Open the session handle by calling [WinBioOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioopensession).

## Return value

If the function succeeds, it returns **S_OK**. If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| ****E_ACCESSDENIED**** | The caller does not have permission to switch users or the biometric session is out of date. |
| ****E_HANDLE**** | The session handle is not valid. |
| ****S_FALSE**** | The user identified by the *SessionHandle* parameter is the same as the current user. |
| **SEC_E_LOGON_DENIED** | The user could not be logged on. |
| ****WINBIO_E_CRED_PROV_DISABLED**** | Current administrative policy prohibits use of the credential provider. |
| ****WINBIO_E_FAST_USER_SWITCH_DISABLED**** | Fast user switching is not enabled. |
| ****WINBIO_E_SAS_ENABLED**** | Fast user switching cannot be performed because secure logon (CTRL+ALT+DELETE) is currently enabled. |

## Remarks

The **WinBioLogonIdentifiedUser** function is typically called by applications that support fast user switching when they identify a user other than the one who is currently logged on.

The fast user switch attempt can leave a logon event in the security log, but the identity is not automatically stored when the credential manager terminates.

The biometric session specified by the *SessionHandle* parameter controls the target account for the fast user switch event. If that handle has been used recently to perform an identification operation, the resulting identity will be logged in after the fast user switch.

For security reasons, the Windows Biometric Framework requires that the identification operation and the call to **WinBioLogonIdentifiedUser** happen within a short period of time. After that period, the identification is considered to be out of date and the call to **WinBioLogonIdentifiedUser** will fail. The default timeout interval is five seconds, but an administrator can make it as large as 60 seconds.

Calling this function when the target user is the same as the current user returns **S_FALSE** and the fast user switch attempt is ignored.

#### Examples

The following function calls WinBioLogonIdentifiedUser to log on a
previously identified user. For this function to work correctly, secure logon must not be enabled. Link to the Winbio.lib static library and include the following header files:

* Windows.h
* Stdio.h
* Conio.h
* Winbio.h

```cpp
HRESULT LogonIdentifiedUser()
{
    // Declare variables.
    HRESULT hr;
    WINBIO_SESSION_HANDLE sessionHandle = NULL;
    WINBIO_UNIT_ID  UnitId;
    WINBIO_IDENTITY Identity;
    WINBIO_BIOMETRIC_SUBTYPE SubFactor;
    WINBIO_REJECT_DETAIL RejectDetail;
    BOOL    bContinue = TRUE;

    // Connect to the system pool.
    hr = WinBioOpenSession(
            WINBIO_TYPE_FINGERPRINT,    // Service provider
            WINBIO_POOL_SYSTEM,         // Pool type
            WINBIO_FLAG_DEFAULT,        // Configuration and access
            NULL,                       // Array of biometric unit IDs
            0,                          // Count of biometric unit IDs
            WINBIO_DB_DEFAULT,                       // Database ID
            &sessionHandle              // [out] Session handle
            );
    if (FAILED(hr))
    {
        wprintf_s(L"\n WinBioOpenSession failed. hr = 0x%x\n", hr);
        goto e_Exit;
    }

    // Locate the biometric sensor and retrieve a WINBIO_IDENTITY object.
    // You must swipe your finger on the sensor.
    wprintf_s(L"\n Calling WinBioIdentify - Swipe finger on sensor...\n");
    while(bContinue)
    {
        hr = WinBioIdentify(
                sessionHandle,          // Session handle
                &UnitId,                // Biometric unit ID
                &Identity,              // User SID or GUID
                &SubFactor,             // Finger sub factor
                &RejectDetail           // rejection information
                );

        switch(hr)
        {
        case S_OK:
            bContinue = FALSE;
            break;
        default:
            wprintf_s(L"\n WinBioIdentify failed. hr = 0x%x\n", hr);
            break;
        }
    }

    if (SUCCEEDED(hr))
    {
        // Switch to the target after receiving a good identity.
        hr = WinBioLogonIdentifiedUser(sessionHandle);

        switch(hr)
        {
        case S_FALSE:
            printf("\n Target is the logged on user. No action taken.\n");
            break;
        case S_OK:
            printf("\n Fast user switch initiated.\n");
            break;
        default:
            wprintf_s(L"\n WinBioLogonIdentifiedUser failed. hr = 0x%x\n", hr);
            break;
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

```

## See also

[WinBioIdentify](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioidentify)

[WinBioIdentifyWithCallback](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioidentifywithcallback)