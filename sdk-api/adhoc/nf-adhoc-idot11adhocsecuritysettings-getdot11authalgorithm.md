# IDot11AdHocSecuritySettings::GetDot11AuthAlgorithm

## Description

Gets the authentication algorithm associated with the security settings. The authentication algorithm is used to authenticate machines and users connecting to the ad hoc network associated with an interface.

## Parameters

### `pAuth` [in, out]

A pointer to a [DOT11_ADHOC_AUTH_ALGORITHM](https://learn.microsoft.com/windows/desktop/api/adhoc/ne-adhoc-dot11_adhoc_auth_algorithm) value that specifies the authentication algorithm.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_FAIL** | The method failed. |
| **E_INVALIDARG** | The value pointed to by *pAuth* is invalid. |
| **E_OUTOFMEMORY** | The method could not allocate the memory required to perform this operation. |
| **E_POINTER** | The pointer *pAuth* is invalid. |

## See also

[IDot11AdHocSecuritySettings](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocsecuritysettings)

[IDot11AdHocSecuritySettings::GetDot11CipherAlgorithm](https://learn.microsoft.com/windows/desktop/api/adhoc/nf-adhoc-idot11adhocsecuritysettings-getdot11cipheralgorithm)