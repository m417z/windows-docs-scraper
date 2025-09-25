# ICredentialProviderUser::GetStringValue

## Description

Retrieves string properties from the [ICredentialProviderUser](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovideruser) object based on the input value.

## Parameters

### `key` [in]

One of the following values that specify the property to retrieve.

| REFPROPERTYKEY | Description | Applies to... |
| --- | --- | --- |
| [PKEY_Identity_DisplayName](https://learn.microsoft.com/windows/desktop/properties/props-system-identity-displayname) | The friendly user name. | Logon UI and Credential UI |
| [PKEY_Identity_LogonStatusString](https://learn.microsoft.com/windows/desktop/properties/props-system-identity-logonstatusstring) | A localized string that indicates the user's logged on status. | Logon UI only |
| [PKEY_Identity_PrimarySid](https://learn.microsoft.com/windows/desktop/properties/props-system-identity-primarysid) | The user's SID. | Logon UI and Credential UI |
| [PKEY_Identity_ProviderID](https://learn.microsoft.com/windows/desktop/properties/props-system-identity-providerid) | The user's provider ID. | Logon UI and Credential UI |
| [PKEY_Identity_QualifiedUserName](https://learn.microsoft.com/windows/desktop/properties/props-system-identity-qualifiedusername) | The name used to pack an authentication buffer. | Logon UI and Credential UI |
| [PKEY_Identity_UserName](https://learn.microsoft.com/windows/desktop/properties/props-system-identity-username) | The user name. | Logon UI and Credential UI |

### `stringValue` [out]

The address of a pointer to a buffer that, when this method returns successfully, receives the requested string.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Each of these values can also be retrieved as a **PROPVARIANT** through [ICredentialProviderUser::GetValue](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovideruser-getvalue).

Consider a scenario with the following users.

* Domain user:
  + Domain: contoso
  + User name: lisa
  + Friendly name: Lisa Andrews
* Local user:
  + PC name: lisa-pc
  + User name: lisa
  + Friendly name: Lisa Andrews
* Microsoft account:
  + Email address: lisa@contoso.com
  + Friendly name: Lisa Andrews

In this scenario, the following table provides some sample data for each of the *key* values.

| REFPROPERTYKEY | Domain user | Local user | Microsoft account |
| --- | --- | --- | --- |
| [PKEY_Identity_DisplayName](https://learn.microsoft.com/windows/desktop/properties/props-system-identity-displayname) | "Lisa Andrews" | "Lisa Andrews" | "Lisa Andrews" |
| [PKEY_Identity_LogonStatusString](https://learn.microsoft.com/windows/desktop/properties/props-system-identity-logonstatusstring) | "Signed-in" | "Locked" | "Remotely signed in from lisa-pc" |
| [PKEY_Identity_PrimarySid](https://learn.microsoft.com/windows/desktop/properties/props-system-identity-primarysid) | "{S-1-5-21-2279990834-2601404236-735077814-1001}" | "{S-1-5-21-2279990834-2601404236-735077814-1001}" | "{S-1-5-21-2279990834-2601404236-735077814-1001}" |
| [PKEY_Identity_ProviderID](https://learn.microsoft.com/windows/desktop/properties/props-system-identity-providerid) | "{A198529B-730F-4089-B646-A12557F5665E}" | "{A198529B-730F-4089-B646-A12557F5665E}" | Not pre-defined |
| [PKEY_Identity_QualifiedUserName](https://learn.microsoft.com/windows/desktop/properties/props-system-identity-qualifiedusername) | "contoso\lisa" | "lisa-pc\lisa" | "<account provider name>\lisa@contoso.com" |
| [PKEY_Identity_UserName](https://learn.microsoft.com/windows/desktop/properties/props-system-identity-username) | "contoso\lisa" | "lisa" | "lisa@contoso.com" |

## See also

[ICredentialProviderUser](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovideruser)

[ICredentialProviderUser::GetValue](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovideruser-getvalue)