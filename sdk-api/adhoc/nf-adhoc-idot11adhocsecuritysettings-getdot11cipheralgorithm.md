# IDot11AdHocSecuritySettings::GetDot11CipherAlgorithm

## Description

Gets the cipher algorithm associated with the security settings. The cipher algorithm is used to encrypt and decrypt information sent on the ad hoc network associated with an interface.

## Parameters

### `pCipher` [in, out]

A pointer to a [DOT11_ADHOC_CIPHER_ALGORITHM](https://learn.microsoft.com/windows/desktop/api/adhoc/ne-adhoc-dot11_adhoc_cipher_algorithm) value that specifies the cipher algorithm.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_FAIL** | The method failed. |
| **E_INVALIDARG** | The value pointed to by *pCipher* is invalid. |
| **E_OUTOFMEMORY** | The method could not allocate the memory required to perform this operation. |
| **E_POINTER** | The pointer *pCipher* is invalid. |

## See also

[IDot11AdHocSecuritySettings](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocsecuritysettings)

[IDot11AdHocSecuritySettings::GetDot11AuthAlgorithm](https://learn.microsoft.com/windows/desktop/api/adhoc/nf-adhoc-idot11adhocsecuritysettings-getdot11authalgorithm)