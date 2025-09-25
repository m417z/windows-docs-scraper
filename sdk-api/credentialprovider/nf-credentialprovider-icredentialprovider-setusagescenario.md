# ICredentialProvider::SetUsageScenario

## Description

Defines the scenarios for which the credential provider is valid. Called whenever the credential provider is initialized.

## Parameters

### `cpus` [in]

Type: **[CREDENTIAL_PROVIDER_USAGE_SCENARIO](https://learn.microsoft.com/windows/win32/api/credentialprovider/ne-credentialprovider-credential_provider_usage_scenario)**

The scenario the credential provider has been created in. This is the usage scenario that needs to be supported. See the Remarks for more information.

### `dwFlags` [in]

Type: **DWORD**

A value that affects the behavior of the credential provider. This value can be a bitwise-OR combination of one or more of the following values defined in Wincred.h. See [CredUIPromptForWindowsCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduipromptforwindowscredentialsa) for more information.

#### CREDUIWIN_GENERIC (0x00000001)

0x00000001. The caller is requesting that the credential provider return the user name and password in plain text. This value cannot be combined with **CREDUIWIN_SECURE_PROMPT**.

#### CREDUIWIN_CHECKBOX (0x00000002)

0x00000002. The **Save** check box is displayed in the dialog box.

#### CREDUIWIN_AUTHPACKAGE_ONLY (0x00000010)

0x00000010. Only credential providers that support the input authentication package should be enumerated. If credential providers do not support the input authentication package, they should enumerate zero user tiles. This value cannot be combined with **CREDUIWIN_IN_CRED_ONLY**.

#### CREDUIWIN_IN_CRED_ONLY (0x00000020)

0x00000020. If the provider can serialize the credentials, then it should enumerate a tile for that credential. No other tiles should be enumerated. Credential providers should use the input [CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION](https://learn.microsoft.com/windows/win32/api/credentialprovider/ns-credentialprovider-credential_provider_credential_serialization) in [ICredentialProvider::SetSerialization](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovider-setserialization) and *dwFlags* in **ICredentialProvider::SetUsageScenario** in order
to determine how many credential tiles to enumerate. This value cannot be combined with **CREDUIWIN_AUTHPACKAGE_ONLY**.

#### CREDUIWIN_ENUMERATE_ADMINS (0x00000100)

0x00000100. Credential providers should enumerate only administrators. This value is intended for UAC purposes only. We recommend that external callers not set this flag.

#### CREDUIWIN_ENUMERATE_CURRENT_USER (0x00000200)

0x00000200. Credential providers should enumerate a tile for the currently logged on user.

#### CREDUIWIN_SECURE_PROMPT (0x00001000)

0x00001000. The credential dialog box should be displayed on the secure desktop. This value cannot be combined with **CREDUIWIN_GENERIC**. Credential provider implementers can safely ignore this flag.

#### CREDUIWIN_PACK_32_WOW (0x10000000)

0x10000000. Buffers passed to the provider are 32-bit. Buffers returned from the provider must also be 32-bit. This is necessary for WOW64.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is required and enables the credential provider to indicate how it will be used.

This method should return **E_NOTIMPL** if the call completes but the requested usage scenario is not supported. This method should return **S_OK** if the method is successful and the usage scenario is supported.