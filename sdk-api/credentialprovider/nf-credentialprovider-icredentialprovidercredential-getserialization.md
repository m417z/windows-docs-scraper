# ICredentialProviderCredential::GetSerialization

## Description

Called in response to an attempt to submit this credential to the underlying authentication engine.

## Parameters

### `pcpgsr` [out]

Type: **[CREDENTIAL_PROVIDER_GET_SERIALIZATION_RESPONSE](https://learn.microsoft.com/windows/win32/api/credentialprovider/ne-credentialprovider-credential_provider_get_serialization_response)***

Indicates the success or failure of the attempt to serialize credentials.

### `pcpcs` [out]

Type: **[CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION](https://learn.microsoft.com/windows/win32/api/credentialprovider/ns-credentialprovider-credential_provider_credential_serialization)***

A pointer to the credential. Depending on the result, there may be no valid credential.

### `ppszOptionalStatusText` [out]

Type: **LPWSTR***

A pointer to a Unicode string value that will be displayed by the Logon UI after serialization. May be **NULL**.

### `pcpsiOptionalStatusIcon` [out]

Type: **[CREDENTIAL_PROVIDER_STATUS_ICON](https://learn.microsoft.com/windows/win32/api/credentialprovider/ne-credentialprovider-credential_provider_status_icon)***

A pointer to an icon that will be displayed by the credential after the call to **GetSerialization** returns. This value can be **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is required.

The [CREDENTIAL_PROVIDER_USAGE_SCENARIO](https://learn.microsoft.com/windows/win32/api/credentialprovider/ne-credentialprovider-credential_provider_usage_scenario) indicates what the appropriate response would be when the user attempts to submit credentials. The following table indicates how to respond based on the usage scenario.

|  |  |
| --- | --- |
| **CPUS_CHANGE_PASSWORD** | No credential serialization occurs in this scenario. In this scenario the credential provider should update the user's private information and return **CPGSR_NO_CREDENTIAL_FINISHED** as *pcpgsr.* |
| **CPUS_CREDUI** | The credential information should be serialized and delivered to the calling application. |
| **CPUS_LOGON**, **CPUS_UNLOCK_WORKSTATION** | The credential information should be packed into a binary stream and transmitted to [Winlogon](https://learn.microsoft.com/windows/desktop/SecAuthN/winlogon) and eventually LSA. |

### Credential Provider Best Practices

Credential providers handle extremely sensitive user secrets in order to complete logon and unlock requests. As a best practice, secret information such as passwords and PINs should be handled with the utmost care. Proper techniques for handling secret information within a credential provider are:

* Always securely discard secrets. To do this, call [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) before freeing the memory used to hold any secret.
* Securely discard secrets promptly after they are used.
* Securely discard secrets if they are not used for their intended purpose within an expected amount of time.