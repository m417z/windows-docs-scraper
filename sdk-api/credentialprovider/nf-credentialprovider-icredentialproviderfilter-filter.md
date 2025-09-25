# ICredentialProviderFilter::Filter

## Description

Evaluates whether a list of credential providers should be allowed to provide credential tiles.

## Parameters

### `cpus` [in]

Type: **[CREDENTIAL_PROVIDER_USAGE_SCENARIO](https://learn.microsoft.com/windows/win32/api/credentialprovider/ne-credentialprovider-credential_provider_usage_scenario)**

A pointer to a [CREDENTIAL_PROVIDER_USAGE_SCENARIO](https://learn.microsoft.com/windows/win32/api/credentialprovider/ne-credentialprovider-credential_provider_usage_scenario) value that declares the scenarios in which a credential provider is supported.

### `dwFlags` [in]

Type: **DWORD**

Usage scenario flags. This parameter is valid only if *cpus* is CPUS_CREDUI. They are defined in Wincred.h.

#### CREDUIWIN_GENERIC

Plain text username/password is being requested.

#### CREDUIWIN_CHECKBOX

Show the **Save Credential** checkbox.

#### CREDUIWIN_AUTHPACKAGE_ONLY

Only credential providers that support the input authentication package should enumerate.

#### CREDUIWIN_IN_CRED_ONLY

Only the incoming credential for the specific authentication package should be enumerated.

#### CREDUIWIN_ENUMERATE_ADMINS

Credential providers should enumerate administrators.

#### CREDUIWIN_ENUMERATE_CURRENT_USER

Only the incoming credential

#### CREDUIWIN_PACK_32_WOW

### `rgclsidProviders` [in]

Type: **GUID***

A pointer to an array of credential provider CLSIDs.

### `rgbAllow` [in, out]

Type: **BOOL***

On entry, a pointer to an array of **BOOL** values, one for each corresponding member of the *rgclsidProviders* array, all initialized to **TRUE**.

On exit, contains **TRUE** if the corresponding credential provider in *rgclsidProviders* is allowed to provide a credential tile; otherwise, **FALSE**.

### `cProviders` [in]

Type: **DWORD**

The number of members in *rgbAllow* or *rgclsidProviders* (they should be the same).

## Return value

Type: **HRESULT**

Always returns S_OK.

## Remarks

On entry, this method receives two parallel arrays; *rgclsidProviders*, which contains the credential provider CLSIDs and *rgbAllow*, which contains **BOOL** values for the corresponding CLSIDs. **ICredentialProviderFilter::Filter** looks at each credential provider in *rgclsidProviders* and decides whether the credential provider should be allowed to enumerate credential tiles for the scenario specified by *dwFlags*. If this is acceptable, the corresponding entry in *rgbAllow* is set to **TRUE**. If this is unacceptable, it is set to **FALSE**.

Never filter out a CLSID for a credential provider that you do not know about.

Do not filter if *cpus* is CPUS_CREDUI and a *dwFlags* value of CREDUIWIN_GENERIC is passed in.

It is legitimate to return success from the method and not modify *rgbAllow*.