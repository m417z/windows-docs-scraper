# ICredentialProviderUser::GetValue

## Description

Retrieves a specified property value set for the user.

## Parameters

### `key` [in]

One of the following values that specify the property to retrieve.

| REFPROPERTYKEY | Applies to... |
| --- | --- |
| [PKEY_Identity_DisplayName](https://learn.microsoft.com/windows/desktop/properties/props-system-identity-displayname) | Logon and credential UI |
| [PKEY_Identity_UserName](https://learn.microsoft.com/windows/desktop/properties/props-system-identity-username) | Logon and credential UI |
| [PKEY_Identity_QualifiedUserName](https://learn.microsoft.com/windows/desktop/properties/props-system-identity-qualifiedusername) | Logon and credential UI |
| [PKEY_Identity_LogonStatusString](https://learn.microsoft.com/windows/desktop/properties/props-system-identity-logonstatusstring) | Logon UI only |
| [PKEY_Identity_PrimarySid](https://learn.microsoft.com/windows/desktop/properties/props-system-identity-primarysid) | Logon and credential UI |
| [PKEY_Identity_ProviderID](https://learn.microsoft.com/windows/desktop/properties/props-system-identity-providerid) | Logon and credential UI |

### `value` [out]

A pointer to a value that, when this method returns successfully, receives the requested property value.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The PKEY_Identity_DisplayName, PKEY_Identity_UserName, PKEY_Identity_QualifiedUserName, and PKEY_Identity_LogonStatusString values can be retrieved directly as strings through the [GetStringValue](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovideruser-getstringvalue) method.

## See also

[ICredentialProviderUser](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovideruser)

[ICredentialProviderUser::GetStringValue](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovideruser-getstringvalue)