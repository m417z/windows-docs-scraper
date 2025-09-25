# WinBioGetDomainLogonSetting function

## Description

Retrieves a value that specifies whether users can log on to a domain by using biometric information.

## Parameters

### `Value` [out]

Pointer to a Boolean value that specifies whether biometric domain logons are enabled.

### `Source` [out]

Pointer to a **WINBIO_SETTING_SOURCE_TYPE** value that specifies the setting source. This can be one of the following values:

| Value | Meaning |
| --- | --- |
| **WINBIO_SETTING_SOURCE_INVALID** | The setting is not valid. |
| **WINBIO_SETTING_SOURCE_DEFAULT** | The setting originated from built-in policy. |
| **WINBIO_SETTING_SOURCE_LOCAL** | The setting originated in the local computer registry. |
| **WINBIO_SETTING_SOURCE_POLICY** | The setting was created by Group Policy. |

## Return value

If the function succeeds, it returns S_OK. If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[Client Application Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/client-application-functions)