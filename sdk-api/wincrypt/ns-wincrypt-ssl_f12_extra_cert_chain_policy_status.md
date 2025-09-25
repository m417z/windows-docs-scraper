# SSL_F12_EXTRA_CERT_CHAIN_POLICY_STATUS structure

## Description

The **SSL_F12_EXTRA_CERT_CHAIN_POLICY_STATUS** structure checks if any certificates in the chain have weak cryptography and checks if a third party root certificate is compliant with the Microsoft Root Program requirements. An error string will be provided if either condition is not met.

## Members

### `cbSize`

**DWORD** value that specifies the size, in bytes, of this structure. This value must be set to a value greater than or equal to sizeof(SSL_F12_EXTRA_CERT_CHAIN_POLICY_STATUS).

### `dwErrorLevel`

**DWORD** value that specifies the level of an error.

| Value | Meaning |
| --- | --- |
| **CERT_CHAIN_POLICY_SSL_F12_SUCCESS_LEVEL**<br><br>0 | No certificate errors. |
| **CERT_CHAIN_POLICY_SSL_F12_WARNING_LEVEL**<br><br>1 | Certificate warning level. |
| **CERT_CHAIN_POLICY_SSL_F12_ERROR_LEVEL**<br><br>2 | Certificate error level. |

### `dwErrorCategory`

**DWORD** value that specifies the category of an error. Each error category has a corresponding **dwErrorLevel**.

| Value | Meaning |
| --- | --- |
| **CERT_CHAIN_POLICY_SSL_F12_NONE_CATEGORY**<br><br>0 | No certificate errors. |
| **CERT_CHAIN_POLICY_SSL_F12_WEAK_CRYPTO_CATEGORY**<br><br>1 | Errors in this category with the **dwErrorLevel**: **CERT_CHAIN_POLICY_SSL_F12_WARNING_LEVEL** are errors associated with all other roots including enterprise.<br><br>Errors in this category with the **dwErrorLevel**: **CERT_CHAIN_POLICY_SSL_F12_ERROR_LEVEL** are errors associated with the third party root certificate. |
| **CERT_CHAIN_POLICY_SSL_F12_ROOT_PROGRAM_CATEGORY**<br><br>2 | Errors in this category with the **dwErrorLevel**: **CERT_CHAIN_POLICY_SSL_F12_WARNING_LEVEL** are all errors with root program compliance failures. |

### `dwReserved`

**DWORD** value reserved for future use.

### `wszErrorText`

The error string provided if any certificates in the chain have weak cryptography or if the third party root certificate is not compliant with the Microsoft Root Program requirements.

## See also

[CertVerifyCertificateChainPolicy](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifycertificatechainpolicy)