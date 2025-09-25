# CREDENTIAL_PROVIDER_USAGE_SCENARIO enumeration

## Description

Declares the scenarios in which a credential provider is supported. A credential provider usage scenario (CPUS) enables the credential provider to provide distinct enumeration behavior and UI field setup across scenarios. When an [ICredentialProvider](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovider) is initialized, it calls [ICredentialProvider::SetUsageScenario](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovider-setusagescenario) to set what usage scenario is supported. That scenario is maintained for the entire lifetime of the credential provider.

## Constants

### `CPUS_INVALID:0`

No usage scenario has been set for the credential provider. The scenario is not passed to [ICredentialProvider::SetUsageScenario](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovider-setusagescenario). If a credential provider stores its current usage scenario as a class member, this provides an initialization value before the first call to **ICredentialProvider::SetUsageScenario**.

### `CPUS_LOGON`

Workstation logon or unlock. See the remarks for more details. Credential providers that implement this scenario should be prepared to serialize credentials to the local authority for authentication.

### `CPUS_UNLOCK_WORKSTATION`

Workstation unlock. Credential providers that implement this scenario should be prepared to serialize credentials to the local authority for authentication. These credential providers also need to enumerate the currently logged-in user as the default tile.

### `CPUS_CHANGE_PASSWORD`

Password change. This enables a credential provider to enumerate tiles in response to a user's request to change the password. Do not implement this scenario if you do not require some secret information from the user such as a password or PIN. These credential providers also need to enumerate the currently logged-in user as the default tile.

### `CPUS_CREDUI`

Credential UI. This scenario enables you to use credentials serialized by the credential provider to be used as authentication on remote machines. This is also the scenario used for over-the-shoulder prompting in User Access Control. This scenario uses a different instance of the credential provider than the one used for **CPUS_LOGON**, **CPUS_UNLOCK_WORKSTATION**, and **CPUS_CHANGE_PASSWORD**, so the state of the credential provider cannot be maintained across the different scenarios.

### `CPUS_PLAP`

Pre-Logon-Access Provider. Credential providers responding to this usage scenario must register under:

**HKLM**\**SOFTWARE**\**Microsoft**\**Windows**\**CurrentVersion**\**Authentication**\**PLAP Providers**

## Remarks

Starting in Windows 10, the **CPUS_LOGON** and **CPUS_UNLOCK_WORKSTATION** user scenarios have been combined. This enables the system to support multiple users logging into a machine without creating and switching sessions unnecessarily. Any user on the machine can log into it once it has been locked without needing to back out of a current session and create a new one. Because of this, **CPUS_LOGON** can be used both for logging onto a system or when a workstation is unlocked. However, **CPUS_LOGON** cannot be used in all cases. Because of policy restrictions imposed by various systems, sometimes it is necessary for the user scenario to be **CPUS_UNLOCK_WORKSTATION**. Your credential provider should be robust enough to create the appropriate credential structure based on the scenario given to it. Windows will request the appropriate user scenario based on the situation. Some of the factors that impact whether or not a **CPUS_UNLOCK_WORKSTATION** scenario must be used include the following. Note that this is just a subset of possibilities.

* The operating system of the device.
* Whether this is a console or remote session.
* Group policies such as hiding entry points for fast user switching, or interactive logon that does not display the user's last name.

Credential providers that need to enumerate the currently user logged into the system as the default tile can keep track of the current user or leverage APIs such as [WTSQuerySessionInformation](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsquerysessioninformationa) to obtain that information.

## See also

[Credential Providers in Windows 10](https://learn.microsoft.com/windows/desktop/SecAuthN/credential-providers-in-windows)