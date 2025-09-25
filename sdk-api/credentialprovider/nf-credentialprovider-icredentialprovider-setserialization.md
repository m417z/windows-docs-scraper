# ICredentialProvider::SetSerialization

## Description

Sets the serialization characteristics of the credential provider.

## Parameters

### `pcpcs` [in]

Type: **const [CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION](https://learn.microsoft.com/windows/win32/api/credentialprovider/ns-credentialprovider-credential_provider_credential_serialization)***

A pointer to a [CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION](https://learn.microsoft.com/windows/win32/api/credentialprovider/ns-credentialprovider-credential_provider_credential_serialization) structure that stores the serialization characteristics of the credential provider.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is required. It accepts a credential and determines if *pcpcs* was a partial or a full credential. If it is a partial credential, it is either incomplete or was passed for the purpose of displaying some information to the user. If it is a full credential, it should be serialized and submitted. Use the members of the [CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION](https://learn.microsoft.com/windows/win32/api/credentialprovider/ns-credentialprovider-credential_provider_credential_serialization) and the flags passed in [SetUsageScenario](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovider-setusagescenario) to determine how to handle the input. The responsibility is on the credential provider to verify the integrity of the input. The Credential UI and Logon UI do not perform any checks on the structure before passing it to the credential provider.

**SetSerialization** is always called after [SetUsageScenario](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovider-setusagescenario). The Logon UI also calls **SetSerialization** when a filter returns a credential through [UpdateRemoteCredential](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialproviderfilter-updateremotecredential). It does not use this method when re-enumerating tiles because of a call to [CredentialsChanged](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialproviderevents-credentialschanged). The Credential UI calls **SetSerialization** when an input credential has been supplied by an application.

The Credential UI enforces the following rules based on the *dwFlags* for this content provider instance defined when [SetUsageScenario](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovider-setusagescenario) was called.

* If the flags include **CREDUIWIN_IN_CRED_ONLY**, all credential providers returning **S_OK** are enabled.
* If the flags include **CREDUIWIN_AUTHPACKAGE_ONLY**, all credential providers returning a success status are enabled.
* If neither of those flags are included, then the Credential UI follows the same logic as the Logon UI and all credential providers that implement the [CREDENTIAL_PROVIDER_USAGE_SCENARIO](https://learn.microsoft.com/windows/win32/api/credentialprovider/ne-credentialprovider-credential_provider_usage_scenario)**CPUS_REDUI** will be enabled regardless of the returned status value.

Credential providers that implement a [CREDENTIAL_PROVIDER_USAGE_SCENARIO](https://learn.microsoft.com/windows/win32/api/credentialprovider/ne-credentialprovider-credential_provider_usage_scenario) of **CPUS_LOGON** and return a failure from this method will still be enabled.